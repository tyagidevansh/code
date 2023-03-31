from tkinter import *

window = Tk()
window.title("Word Guessing Game")
window.geometry("1900x800")

bg = PhotoImage(file = r"C:\Users\devan\Pictures\paint\guessing_background.png")
label1 = Label(window,image = bg)
label1.pack()
window.mainloop()