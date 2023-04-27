from discord.ext import commands, tasks
import discord
from dataclasses import dataclass
from datetime import datetime, timedelta, time, date
import requests
import json
import sqlite3

TOKEN = 'MTEwMDQ4MjUzMjE3ODM5OTMwMg.GW8Ygj.19-3B_ETDwq0eg10oG0qQeU2iod4VAwz1XVvsY'
CHANNEL_ID = 1100633700636557382
MAX_SESSION_TIME = 180
time = 0

def create_connection():
    global conn
    conn = sqlite3.connect('study_tracker.db')
    return conn

def create_table(conn):
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS study_sessions
                      (user_id TEXT, start_time TEXT, end_time TEXT, minutes INT)''')
    conn.commit()

@dataclass
class Session:
    is_active : bool = False
    start_time : int = 0
    user_id = None

bot = commands.Bot(command_prefix="e.", intents = discord.Intents.all())
create_connection()
create_table(conn)

def get_minutes(time_delta,time):
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        time = 0
        return 'Study session too short to be recorded'

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return f'You studied for {time} minutes'
    
    elif 600 < total_seconds and total_seconds < 3600:
        time = int(total_seconds / 60)
        return f'You studied for {time} minutes'

def time_in_min(time_delta,time):
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        time = 0
        return '0'

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return time
    
    elif 600 < total_seconds and total_seconds < 3600:
        time = int(total_seconds / 60)
        return time

def add_study_session(conn, user_id, start_time, end_time, minutes):
    cursor = conn.cursor()
    cursor.execute("INSERT INTO study_sessions VALUES (?, ?, ?, ?)", (user_id, start_time, end_time, minutes))
    conn.commit()

    # Fetch all data from the table after committing the changes
    cursor.execute("SELECT * FROM study_sessions")
    result = cursor.fetchall()

    # You can print or process the fetched result as needed
    print(result)


def get_study_data(conn, user_id):
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM study_sessions WHERE user_id=?", (user_id,))
    return cursor.fetchall()

def get_study_data_for_day(conn, user_id, date):
    start_of_day = datetime.combine(date, time.min).timestamp()
    end_of_day = datetime.combine(date, time.max).timestamp()
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM study_sessions WHERE user_id=? AND start_time >= ? AND end_time <= ?", (user_id, start_of_day, end_of_day))
    return cursor.fetchall()

@bot.event
async def on_ready():
    print("Hello! bot ready")
    channel = bot.get_channel(CHANNEL_ID)
    await channel.send("Bot online")
     
session = Session()

@bot.command()
async def start(ctx):
    if session.is_active:
        await ctx.send("A session is already active!")
        return
    session.is_active = True
    session.start_time = ctx.message.created_at.timestamp()
    readable_time = ctx.message.created_at.strftime("%H:%M:%S")
    await ctx.send(f"New session started at {readable_time}")
    session.userid = ctx.author.id
    
@bot.command()
async def end(ctx):
    if not session.is_active:
        await ctx.send("No session is active!")
        return
    
    session.is_active = False
    end_time = ctx.message.created_at.timestamp()
    duration = end_time - session.start_time
    #readable_duration = str(timedelta(seconds = duration))
    duration_timedelta = timedelta(seconds=duration)
    minutes = time_in_min(duration_timedelta,time)
    print(minutes)
    time_output = get_minutes(duration_timedelta,time)
    await ctx.send(time_output)
    add_study_session(conn, session.user_id, session.start_time, end_time, minutes)

@bot.command()
async def total(ctx):
    date_ = date.today()    
    date_str = date_.strftime("%Y-%m-%d")
    study_data = get_study_data_for_day(conn, ctx.author.id, date_)
    total_duration = sum((datetime.fromtimestamp(end_time) - datetime.fromtimestamp(start_time)).total_seconds() for _, start_time, end_time, _ in study_data)
    readable_duration = str(timedelta(seconds=total_duration))
    await ctx.send(f"Total study time for {date_str}: {readable_duration}")

def get_quote():
    response= requests.get("https://zenquotes.io/api/quotes") #returns a json file off of zenquotes server
    json_data = json.loads(response.text)
    quote = json_data[0]['q']+"  "  +  "-" + json_data[0]['a'] #first part returns the quote, second part returns the author
    return quote

@bot.command()
async def quote(ctx):
    quote = get_quote()
    await ctx.send(quote)
    
bot.run(TOKEN)