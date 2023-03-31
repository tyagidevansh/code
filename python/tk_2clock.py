from tkinter import *
from time import *

def update():
    time_string = strftime("%I:%M:%S %p")
    time_label.config(text = time_string)
    
    day_string = strftime("%A")
    day_label.config(text = day_string)
 
    date_string = strftime("%B %d %Y")
    date_label.config(text = date_string)

    window.after(100, update)

window = Tk()

time_label = Label(window,font = ("Arial", 50), fg = "#00FF00", bg = "black")
time_label.pack()

day_label = Label(window, font = ("Arial", 20), fg = "#00FF00", bg = "black")
day_label.pack(fill = X, expand = True, ipady = 10)

date_label = Label(window, font = ("Arial", 15), fg= "#00FF00", bg = "black")
date_label.pack(fill = X, expand = True, ipady = 10)

update()

window.mainloop()