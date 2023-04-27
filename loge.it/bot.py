###############################################################LOGE.IT###################################################################
# a time tracker bot for discord
# made by @tyagi_devansh

from discord.ext import commands, tasks
import discord
from dataclasses import dataclass
from datetime import timedelta, date
import requests
import json
import sqlite3

TOKEN = ''#unique bot token
CHANNEL_ID = 1100633700636557382 #the channel to which the initial bot online message will be sent


def create_connection(): 
    conn = sqlite3.connect('study_tracker.db')
    return conn

def create_table(conn):
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS productive_time (user_id TEXT,activity TEXT, day DATE, start_time TIME, end_time TIME, minutes INT);''')
    conn.commit()

@dataclass
class Session:
    is_active: bool = False
    start_time: int = 0
    user_id: int = None

bot = commands.Bot(command_prefix=["e.", "E.", "@","!"], intents = discord.Intents.all())
conn = create_connection()
create_table(conn)

def get_minutes(time_delta): #returns full text for what needs to be outputted
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        return 'Session too short to be recorded. Sessions must be between 10 and 180 minutes long.'

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return f'You studied for {time} minutes'
    
    elif 600 < total_seconds and total_seconds < 3600:
        time = int(total_seconds / 60)
        return f'You studied for {time} minutes'
    else:
        return 'Session terminated at 180 minutes'

def time_in_min(time_delta): #calculates time for the storing in database
    total_seconds = time_delta.total_seconds()

    if total_seconds < 600:
        return None

    elif total_seconds >= 3600:
        time = int(total_seconds // 60)
        return time
    
    elif 600 < total_seconds and total_seconds < 10800:
        time = int(total_seconds / 60)
        return time

def add_session(conn, user_id, activitytype, start_time, end_time, minutes): #adds each session to the table
    cur_day = date.today()
    day_str = cur_day.strftime('%Y-%m-%d')
    cursor = conn.cursor()
    cursor.execute("INSERT INTO productive_time VALUES (?, ?, ?, ?,?,?)", (user_id,activitytype, day_str, start_time, end_time, minutes))
    conn.commit()

    cursor.execute("SELECT * FROM productive_time")
    result = cursor.fetchall()
    print(result)

def get_data(conn, user_id,activitytype): #kinda useless, fetches the whole table
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM productive_time WHERE user_id=? AND activity =?", (user_id,activitytype))
    return cursor.fetchall()

def get_data_for_day(conn, user_id,activitytype, date): #number of minutes for the current day, seperate from other durations for ease of use
    cursor = conn.cursor()
    cursor.execute("SELECT SUM(minutes) FROM productive_time WHERE user_id = ? AND activity=? AND day=?", (user_id,activitytype, date))
    study_data = cursor.fetchone()[0]
    return study_data
 
def get_data_for_duration(conn, user_id, activitytype, duration): #number of minutes for any (specified) duration
    cursor = conn.cursor()
    today = date.today()
    if duration == "week":
        start_date = today - timedelta(days=6)
    elif duration == "month":
        start_date = today.replace(day=1)
    elif duration == "year":
        start_date = today.replace(month=1, day=1)
    else:
        raise ValueError("Invalid duration specified")

    cursor.execute("SELECT SUM(minutes) FROM productive_time WHERE user_id = ? AND activity=? AND day BETWEEN ? AND ?", (user_id,activitytype, start_date, today))
    study_data = cursor.fetchone()[0]
    return study_data 
    
@bot.event
async def on_ready(): #just sents a confirmation message to the #test channel so i know if its working
    print("Hello! bot ready")
    channel = bot.get_channel(CHANNEL_ID)
    await channel.send("Bot online")
     
sessions = {} #empty dictionary to store everyone's individual sessions, only one session, study or workout, at a time

@bot.command(name = "start", aliases=["ss", "Ss","SS","START"])
async def start(ctx):  #checks if a session is ongoing, if not, creates a new session, using the user_id as the key in the sessions dict
    if ctx.author.id in sessions: #ctx = context
        await ctx.send("A session is already active!")
        return
    sessions[ctx.author.id] = Session(is_active=True, start_time=ctx.message.created_at.timestamp(), user_id=ctx.author.id) #new instant of the Session class
    await ctx.send(f"New study session started!")
    
@bot.command(name="endstudysession", aliases =["es", "ess", "Es"])
async def endstudysession(ctx):  #ends a study session, deletes the entry from the sessions dict, sends the length of the session
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
    activity = "Study" #defines what it is tagged as in the database for later
    add_session(conn, session.user_id,activity, session.start_time, end_time, minutes)
    del sessions[ctx.author.id] #deletes the current session from the dict


@bot.command(name="total", aliases=["ts"])
async def total(ctx): #total time spent studying in current day
    cur_day = date.today() #gets the current day
    day_str = cur_day.strftime('%Y-%m-%d') #converts it to the format used in database
    activitytype = "Study"
    study_data = get_data_for_day(conn, ctx.author.id,activitytype, day_str)
    if study_data == None:
        await ctx.send("You have not studied yet. Start studying now!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have studied for {study_data} minutes today!") #the <> part tags the user who sent the message

@bot.command(name="totalstudyduration", aliases=["td","tsd","Tsd", "Td"])
async def total(ctx, duration=None):
    if duration is None:
        await ctx.send("Please enter the duration you want to see the stats for (week, month or year):")

        def check(message):
            return message.author == ctx.author and message.channel == ctx.channel

        message = await bot.wait_for('message', check=check)
        duration = message.content.strip().lower()

    activitytype = "Study"
    study_data = get_data_for_duration(conn, ctx.author.id, activitytype, duration)
    if study_data is None:
        await ctx.send(f"You have not studied yet. Start studying now!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have studied for {study_data} minutes in the last {duration}!")


################################
##the bit for the workout part##
################################


#functions work in the same way as in the study section, just name and activity changes
@bot.command(name="startworkout", alias= ["sw", "Sw", "SW", "STARTWORKOUT"])
async def startworkout(ctx):
    if ctx.author.id in sessions:
        await ctx.send("A session is already active!")
        return
    sessions[ctx.author.id] = Session(is_active=True, start_time=ctx.message.created_at.timestamp(), user_id=ctx.author.id)
    await ctx.send(f"New workout session started!")
    
@bot.command(name="endworkoutsession", aliases=["ew", "Ew","EW"])
async def endworkoutsession(ctx):
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
    activity = "Workout"
    add_session(conn, session.user_id,activity, session.start_time, end_time, minutes)
    del sessions[ctx.author.id]

@bot.command(name="totalworkout", alias={"tw","Tw","TW"})
async def totalworkout(ctx):
    cur_day = date.today()
    day_str = cur_day.strftime('%Y-%m-%d')
    activitytype = "Workout"
    workout_data = get_data_for_day(conn, ctx.author.id,activitytype, day_str)
    if workout_data == None:
        await ctx.send("You have not worked out yet. Get yourself off the bed!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have worked out for {workout_data} minutes today!")

@bot.command(name="totalworkoutduration", aliases=["twd", "Twd"])
async def total(ctx, duration=None):
    if duration is None:
        await ctx.send("Please enter the duration you want to see the stats for (week, month or year):")

        def check(message):
            return message.author == ctx.author and message.channel == ctx.channel

        message = await bot.wait_for('message', check=check)
        duration = message.content.strip().lower()

    activitytype = "Workout"
    study_data = get_data_for_duration(conn, ctx.author.id, activitytype, duration)
    if study_data is None:
        await ctx.send(f"You have not worked out yet. Stop being lazy!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have studied for {study_data} minutes in the last {duration}!")

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
async def on_command_error(ctx, error): #if it hits a command it does not know, it does not return anything to the terminal and just keeps going
    if isinstance(error, commands.CommandNotFound):
        pass
    else:
        raise error
    

bot.run(TOKEN)