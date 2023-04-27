from discord.ext import commands, tasks
import discord
from dataclasses import dataclass
from datetime import datetime, timedelta, time, date, timezone
import requests
import json
import sqlite3

TOKEN = ''
CHANNEL_ID = 1100633700636557382
MAX_SESSION_TIME = 180

def create_connection():
    conn = sqlite3.connect('study_tracker.db')
    return conn

def create_table(conn):
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS study_sessions (user_id TEXT, day DATE, start_time TIME, end_time TIME, minutes INT);''')
    conn.commit()

@dataclass
class Session:
    is_active: bool = False
    start_time: int = 0
    user_id: int = None

bot = commands.Bot(command_prefix=["e.", "E.", "@","!"], intents = discord.Intents.all())
conn = create_connection()
create_table(conn)

def get_minutes(time_delta):
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        return 'Study session too short to be recorded'

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return f'You studied for {time} minutes'
    
    elif 600 < total_seconds and total_seconds < 3600:
        time = int(total_seconds / 60)
        return f'You studied for {time} minutes'

def time_in_min(time_delta):
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        return 10

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return time
    
    elif 600 < total_seconds and total_seconds < 3600:
        time = int(total_seconds / 60)
        return time

def add_study_session(conn, user_id, start_time, end_time, minutes):
    cur_day = date.today()
    day_str = cur_day.strftime('%Y-%m-%d')
    cursor = conn.cursor()
    cursor.execute("INSERT INTO study_sessions VALUES (?, ?, ?, ?,?)", (user_id,day_str, start_time, end_time, minutes))
    conn.commit()

    cursor.execute("SELECT * FROM study_sessions")
    result = cursor.fetchall()
    print(result)


def get_study_data(conn, user_id):
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM study_sessions WHERE user_id=?", (user_id,))
    return cursor.fetchall()

def get_study_data_for_day(conn, user_id, date):
    cursor = conn.cursor()
    cursor.execute("SELECT SUM(minutes) FROM study_sessions WHERE user_id = ? AND day=?", (user_id, date))
    study_data = cursor.fetchone()[0]
    return study_data
    
@bot.event
async def on_ready():
    print("Hello! bot ready")
    channel = bot.get_channel(CHANNEL_ID)
    await channel.send("Bot online")
     
sessions = {}

@bot.command(name = "start", aliases=["ss"])
async def start(ctx):
    if ctx.author.id in sessions:
        await ctx.send("A session is already active!")
        return
    sessions[ctx.author.id] = Session(is_active=True, start_time=ctx.message.created_at.timestamp(), user_id=ctx.author.id)
    await ctx.send(f"New session started!")
    
@bot.command()
async def end(ctx):
    session = sessions.get(ctx.author.id)
    if session is None or not session.is_active:
        await ctx.send("You do not have a session active!")
        return

    session.is_active = False
    end_time = ctx.message.created_at.timestamp()
    duration = end_time - session.start_time
    duration_timedelta = timedelta(seconds=duration)
    minutes = time_in_min(duration_timedelta)
    time_output = get_minutes(duration_timedelta)
    await ctx.send(time_output)
    add_study_session(conn, session.user_id, session.start_time, end_time, minutes)
    del sessions[ctx.author.id]


@bot.command()
async def total(ctx):
    cur_day = date.today()
    day_str = cur_day.strftime('%Y-%m-%d')
    study_data = get_study_data_for_day(conn, ctx.author.id, day_str)
    if study_data == None:
        await ctx.send("You have not studied yet. Start studying now!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have studied for {study_data} minutes today!")

@bot.command()
async def tt(ctx):
    userid = ctx.author.id
    data = get_study_data(conn,userid)
    await ctx.send(data)


def get_quote():
    response= requests.get("https://zenquotes.io/api/quotes") #returns a json file off of zenquotes server
    json_data = json.loads(response.text)
    quote = json_data[0]['q']+"  "  +  "-" + json_data[0]['a'] #first part returns the quote, second part returns the author
    return quote

@bot.command()
async def quote(ctx):
    quote = get_quote()
    await ctx.send(quote)
    
@bot.event
async def on_command_error(ctx, error):
    if isinstance(error, commands.CommandNotFound):
        pass
    else:
        raise error
    

bot.run(TOKEN)