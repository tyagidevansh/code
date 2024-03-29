###############################################################LOGE.IT###################################################################
# a time tracker bot for discord
# made by @tyagidevansh

from discord.ext import commands, tasks
import discord
from dataclasses import dataclass
from datetime import timedelta, date, datetime
import requests
import json
import sqlite3
import matplotlib.pyplot as plt
import io
from discord.ext import commands
import calendar

TOKEN = 'MTEwMDQ4MjUzMjE3ODM5OTMwMg.GvVLf_.0_xVmyzahXaitJ1WYFvlbLewoW9UjYA2DcdHoU'#unique bot token
CHANNEL_ID = 1100633700636557382 #the channel to which the initial bot online message will be sent

def create_connection(): 
    conn = sqlite3.connect('study_tracker.db')
    return conn

def create_table(conn):
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS productive_time (user_id TEXT,activity TEXT, day DATE, start_time TIME, end_time TIME, minutes INT);''')
    conn.commit()

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
        return 10

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

def plot_data_for_week(conn, user_id, activitytype):
    cursor = conn.cursor()
    cur_day = datetime.today().date()  
    week_ago = cur_day - timedelta(days=7)
    cursor.execute("SELECT day, SUM(minutes) FROM productive_time WHERE user_id = ? AND activity=? AND day BETWEEN ? and ? GROUP BY day", (user_id, activitytype, week_ago, cur_day))

    rows = cursor.fetchall()
    days = [row[0] for row in rows]
    minutes = [row[1] for row in rows]
    # Convert days to datetime objects
    days = [datetime.strptime(day, '%Y-%m-%d').date() for day in days]
    
    # Get all the days between the week ago date and current date
    all_days = [week_ago + timedelta(days=i) for i in range(1,8)]
    day_names = [day.strftime("%A") for day in all_days]
  
    # Create a dictionary to map each day to its corresponding minute value
    day_minutes = dict(zip(days, minutes))
    # Create a list of minute values for each day, in the order of the all_days list
    minute_values = [day_minutes.get(day, 0) for day in all_days]

    return all_days, minute_values, day_names

def plot_data_for_month(conn, user_id, activitytype):
    cursor = conn.cursor()
    cur_day = datetime.today().date()
    num_days = calendar.monthrange(cur_day.year, cur_day.month)[1]
    month_ago = cur_day - timedelta(days=num_days)
    cursor.execute("SELECT day, SUM(minutes) FROM productive_time WHERE user_id = ? AND activity=? AND day BETWEEN ? and ? GROUP BY day", (user_id, activitytype, month_ago, cur_day))

    rows = cursor.fetchall()
    days = [datetime.date(datetime.strptime(row[0], '%Y-%m-%d')) for row in rows]
    minutes = [row[1] for row in rows]
    
    all_days = []
    days_for_xticks = []
    for i in range(1, num_days+1):
        all_days.insert(0, datetime.date(datetime(cur_day.year, cur_day.month, i)))
        if i%5 == 0:
            days_for_xticks.insert(0, datetime.date(datetime(cur_day.year, cur_day.month, i)))
        else:
            days_for_xticks.insert(0,None)
    
    # Create a dictionary to map each day to its corresponding minute value
    day_minutes = dict(zip(days, minutes))
    # Create a list of minute values for each day, in the order of the all_days list
    minute_values = [day_minutes.get(day, 0) for day in all_days]
    
    return all_days, minute_values, days_for_xticks

def get_quote():
    response= requests.get("https://zenquotes.io/api/quotes") #returns a json file off of zenquotes server
    json_data = json.loads(response.text)
    quote = json_data[0]['q']+"  "  +  "-" + json_data[0]['a'] #first part returns the quote, second part returns the author
    return quote

@dataclass
class Session:
    is_active: bool = False
    start_time: int = 0
    user_id: int = None

bot = commands.Bot(command_prefix=["e.", "E.", "@","!"], intents = discord.Intents.all())
conn = create_connection()
create_table(conn)

@bot.event
async def on_ready(): #just sents a confirmation message to the #test channel so i know if its working
    channel = bot.get_channel(CHANNEL_ID)
    await channel.send("Bot online")
     
@bot.command(name = "commands")
async def commands(ctx):
    await ctx.send('''
Hi! I am loge.it, you can call me e. I am here to help you be more productive.

This bot is far from complete, most things are unpolished but the basic functions should work fine. 

STARTING OR ENDING SESSIONS
Start or ss: Start a new study session
End or es: End an ongoing study session
Startworkout or sw : Start a new workout session
Endworkoutsession or ew: End an ongoing workout session

VIEW TOTALS 
Total or ts: Total time spent studying today
Totalstudyduration or td or tsd: Total time spent studying in a week, month or year
Totalworkout or tw: Total time spent working out today
Totalworkoutduration or twd: Total time spent working out in a week, month or year

VISUALISE TOTALS
Graph or g: Graph for time spent studying in the last week
Graphmonth or gm: Graph for time spent studying in the last month
Graphworkout or gw: Graph for time spent working out in the last week
Graphworkoutmonth or gwm: Graph for time spent working out in the last month

RANDOM
Quote : Just a quote
  
                   ''')
sessions = {} #empty dictionary to store everyone's individual sessions, only one session, study or workout, at a time

@bot.command(name = "start", aliases=["Start","ss", "Ss","SS","START"])
async def start(ctx):  #checks if a session is ongoing, if not, creates a new session, using the user_id as the key in the sessions dict
    if ctx.author.id in sessions: #ctx = context
        await ctx.send("A session is already active!")
        return
    sessions[ctx.author.id] = Session(is_active=True, start_time=ctx.message.created_at.timestamp(), user_id=ctx.author.id) #new instant of the Session class
    await ctx.send(f"New study session started!")
    
@bot.command(name="endstudysession", aliases =["end","End","es", "ess", "Es"])
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


@bot.command(name="total", aliases=["ts","Total","Ts"])
async def total(ctx): #total time spent studying in current day
    cur_day = date.today() #gets the current day
    day_str = cur_day.strftime('%Y-%m-%d') #converts it to the format used in database
    activitytype = "Study"
    study_data = get_data_for_day(conn, ctx.author.id,activitytype, day_str)
    if study_data == None:
        await ctx.send("You have not studied yet. Start studying now!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have studied for {study_data} minutes today!") #the <> part tags the user who sent the message

@bot.command(name="totalstudyduration", aliases=["td","tsd","Tsd", "Td","Totalstudyduration"])
async def totalstudyduration(ctx, duration=None):
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

#functions work in the same way as in the study section, just name and activity changes
@bot.command(name="startworkout", aliases= ["sw", "Sw", "SW", "STARTWORKOUT", "Startworkout"])
async def startworkout(ctx):
    if ctx.author.id in sessions:
        await ctx.send("A session is already active!")
        return
    sessions[ctx.author.id] = Session(is_active=True, start_time=ctx.message.created_at.timestamp(), user_id=ctx.author.id)
    await ctx.send(f"New workout session started!")
    
@bot.command(name="endworkoutsession", aliases=["ew", "Ew","EW","Endworkoutsession"])
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

@bot.command(name="totalworkout", aliases=["tw","Tw","TW"])
async def totalworkout(ctx):
    cur_day = date.today()
    day_str = cur_day.strftime('%Y-%m-%d')
    activitytype = "Workout"
    workout_data = get_data_for_day(conn, ctx.author.id,activitytype, day_str)
    if workout_data == None:
        await ctx.send("You have not worked out yet. Get yourself off the bed!")
    else:
        await ctx.send(f"<@{ctx.author.id}> You have worked out for {workout_data} minutes today!")

@bot.command(name="totalworkoutduration", aliases=["twd", "Twd", "Totalworkoutduration"])
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

@bot.command(name = "quote", aliases = ["Quote"])
async def quote(ctx):
    quote = get_quote()
    await ctx.send(quote)
    
@bot.event
async def on_command_error(ctx, error): #if it hits a command it does not know, it does not return anything to the terminal and just keeps going
    if isinstance(error, commands.CommandNotFound):
        pass
    else:
        raise error

@bot.command(name= "graph", aliases = ["Graph", "G","g"])
async def graph(ctx):
    activitytype = "Study"
    days, minutes, day_names = plot_data_for_week(conn, ctx.author.id, activitytype)
    # Create the bar graph
    fig, ax = plt.subplots()
    ax.bar(days, minutes,color = "#029386")
    ax.set_xticklabels(day_names, rotation=45, ha='right')
    ax.set_xlabel('Day')
    ax.set_ylabel('Minutes')
    ax.set_title(f"Time spent {activitytype.lower()}ing in the last 7 days")
    plt.tight_layout()

    # Convert the plot to an image buffer
    buf = io.BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)

    # Create and send the embed with the image
    file = discord.File(buf, filename='plot.png')
    embed = discord.Embed(title=f"Time spent studying in the last 7 days",color=0x029386)
    embed.set_image(url='attachment://plot.png')
    await ctx.send(embed=embed, file=file)
    
@bot.command(name="graphworkout", aliases = ["Graphworkout","gw"])
async def graphworkout(ctx):
    activitytype = "Workout"
    days, minutes, day_names = plot_data_for_week(conn, ctx.author.id, activitytype)
    # Create the bar graph
    fig, ax = plt.subplots()
    ax.bar(days, minutes,color = "#029386")
    ax.set_xticklabels(day_names, rotation=45, ha='right')
    ax.set_xlabel('Day')
    ax.set_ylabel('Minutes')
    ax.set_title(f"Time spent {activitytype.lower()}ing in the last 7 days")
    plt.tight_layout()

    # Convert the plot to an image buffer
    buf = io.BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)

    # Create and send the embed with the image
    file = discord.File(buf, filename='plot.png')
    embed = discord.Embed(title=f"Time spent studying in the last 7 days",color=0x029386)
    embed.set_image(url='attachment://plot.png')
    await ctx.send(embed=embed, file=file)

@bot.command(name="graphmonth", aliases = ["Graphmonth", "Gm","gm"])
async def graphmonth(ctx):
    activitytype = "Study"
    days, minutes, days_for_xticks = plot_data_for_month(conn, ctx.author.id, activitytype)
    # Create the bar graph
    fig, ax = plt.subplots()
    ax.bar(days, minutes,color = "#029386")
    ax.set_xticks(days_for_xticks)
    ax.set_xticklabels([day.strftime("%d") for day in days], rotation=0, ha='right')
    ax.set_xlabel('Day')
    ax.set_ylabel('Minutes')
    ax.set_title(f"Time spent {activitytype.lower()}ing in the last month")
    plt.tight_layout()

    # Convert the plot to an image buffer
    buf = io.BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)

    # Create and send the embed with the image
    file = discord.File(buf, filename='plot.png')
    embed = discord.Embed(title=f"Time spent studying in the last 7 days", color=0x029386)
    embed.set_image(url='attachment://plot.png')
    await ctx.send(embed=embed, file=file)
    
@bot.command(name = "graphworkoutmonth", aliases = ["Graphworkoutmonth", "Gwm", "gwm"])
async def graphworkoutmonth(ctx):
    activitytype = "Workout"
    days, minutes, days_for_xticks = plot_data_for_month(conn, ctx.author.id, activitytype)
    # Create the bar graph
    fig, ax = plt.subplots()
    ax.bar(days, minutes,color = "#029386")
    ax.set_xticks(days_for_xticks)
    ax.set_xticklabels([day.strftime("%d") for day in days], rotation=0, ha='right')
    ax.set_xlabel('Day')
    ax.set_ylabel('Minutes')
    ax.set_title(f"Time spent {activitytype.lower()}ing in the last month")
    plt.tight_layout()

    # Convert the plot to an image buffer
    buf = io.BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)

    # Create and send the embed with the image
    file = discord.File(buf, filename='plot.png')
    embed = discord.Embed(title=f"Time spent working out in the last month", color=0x029386)
    embed.set_image(url='attachment://plot.png')
    await ctx.send(embed=embed, file=file)
    
@bot.command()
async def totalall(ctx):
    activitytype = "Studying"
    study_data = get_data(conn, ctx.author.id,activitytype)
    await ctx.send(study_data)

bot.run(TOKEN)