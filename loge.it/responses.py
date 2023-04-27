import sqlite3

conn = sqlite3.connect('timetrack.db')

c = conn.cursor()

c.execute("""CREATE TABLE TIME_LOGS(
             userid text primary
             start_time DATE,
    )""")