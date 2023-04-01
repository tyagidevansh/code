import random
from tkinter import *

board = [[' ']*3 for i in range(3)]
freespaces = 9
x1 = None
x2= None
y1 = None
y2 = None
a = 100
b = 350
c = 600
winner = ' '
movedict = {'1' : [0,0], '2': [0,1], '3': [0,2], '4' : [1,0], '5' : [1,1], '6': [1,2], '7' : [2,0], '8': [2,1], '9': [2,2]}

def boardinit():
    global window, canvas
    window = Tk()
    window.title("Tic Tac Toe")
    window.geometry("950x850")
    window['bg'] = 'gray12'
    canvas = Canvas(window, width = 950, height = 850, bg = 'gray12')
    canvas.pack()

def button_clicked(event):
    global freespaces, movedict, winner, window, canvas
    winner = ' '
    button = event.widget
    button_name = button.winfo_name()
    button_num = button_name.replace("button", "")
    print("Square {} clicked".format(button_num))

    button = canvas.nametowidget(button_name)
    x1 = button.winfo_x()
    y1 = button.winfo_y()
    print(x1, y1)
    button.destroy()
    
    img = PhotoImage(file = r"C:\Users\devan\OneDrive\Documents\code\python\graphics\X.png")
    label = Label(canvas, image=img)
    label.image = img
    label.place(x = x1,y = y1-15)
    
    x2 = movedict[button_num][0]
    y2 = movedict[button_num][1]
    print("test", x2, y2)
    board[x2][y2] = 'X'
    winner = checkWinner()
    if winner:
        print(f"{winner} wins!")
        victory()
    else:
        computerMove()
        winner = checkWinner()
        if winner:
            print(f"{winner} wins!")
            victory()
    return winner
    
def GUI():
    global window, canvas
    line1 = canvas.create_line(a,325,850,325, width = 7, fill = 'white')
    line2 = canvas.create_line(a,575,850,575, width = 7, fill = 'white')
    line3 = canvas.create_line(b,75,b,825, width = 7, fill = 'white')
    line4 = canvas.create_line(c,75,c,825, width = 7, fill = 'white')


    button1 = Button(canvas, text = ' ', name = 'button1', bd = 0, bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button1.place(x = a,y =a)
    button1.bind("<Button-1>", button_clicked)

    button2 = Button(canvas, text = ' ', bd = 0, name = 'button2', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button2.place(x = b +10,y =a)
    button2.bind("<Button-1>", button_clicked)

    button3 = Button(canvas, text = ' ', bd = 0,name = 'button3', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button3.place(x = c + 10,y =a)
    button3.bind("<Button-1>", button_clicked)

    button4 = Button(canvas, text = ' ', bd = 0,name = 'button4', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button4.place(x = a,y =b)
    button4.bind("<Button-1>", button_clicked)

    button5 = Button(canvas, text = ' ', bd = 0, name = 'button5', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button5.place(x = b+10,y =b)
    button5.bind("<Button-1>", button_clicked)

    button6 = Button(canvas, text = ' ', bd = 0,name = 'button6', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button6.place(x = c+10,y =b)
    button6.bind("<Button-1>", button_clicked)

    button7 = Button(canvas, text = ' ', bd = 0, name = 'button7', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button7.place(x = a,y = c)
    button7.bind("<Button-1>", button_clicked)

    button8 = Button(canvas, text = ' ', bd = 0, name = 'button8', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button8.place(x = b+10,y =c)
    button8.bind("<Button-1>", button_clicked)

    button9 = Button(canvas, text = ' ', bd = 0, name = 'button9', bg = 'gray12',activebackground= 'gray12', height = 14, width = 33)
    button9.place(x = c+10,y =c)
    button9.bind("<Button-1>", button_clicked)
    
    window.mainloop()
    
def resetBoard():
    global board, freespaces
    board = [[' ']*3 for i in range(3)]
    freespaces = 9

def checkFreeSpaces():
    global freespaces
    freespaces = 0
    for row in board:
        for cell in row:
            if cell == ' ':
                freespaces += 1

def computerMove():
    global freespaces, movedict, winner
    if freespaces > 0:
        while True:
            row = random.randint(0, 2)
            col = random.randint(0, 2)
            if board[row][col] == ' ':
                button_num = list(movedict.keys())[list(movedict.values()).index([row, col])]
                button_name = "button" + button_num
                button = canvas.nametowidget(button_name)
                print("Computer chooses square", button_num)
                x1 = button.winfo_x()
                y1 = button.winfo_y()
                
                board[row][col] = 'O'
                button.destroy()
                
                img = PhotoImage(file=r"C:\Users\devan\OneDrive\Documents\code\python\graphics\O.png")
                label = Label(canvas, image=img)
                label.image = img
                label.place(x=x1, y=y1-15)
                
                freespaces -= 1
                return

            
    else:
        winner = ' '

def checkWinner():
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] != ' ':
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] != ' ':
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != ' ':
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != ' ':
        return board[0][2]
    return None

def victory():
    global winner
    #makes another popup window, makes it toplevel and puts a canvas on it so i can place buttons
    canvas2 = Canvas(window, width=400, height=150)
    canvas2.pack()
    toplevel = Toplevel(window)
    toplevel.geometry('400x150+400+400') #window of 400x100, at (400,400)
    toplevel.config(bg='gray12')
    canvas2_toplevel = Canvas(toplevel, width=400, height=150, bg='gray12')
    canvas2_toplevel.pack(fill=BOTH, expand=True)
    canvas2_toplevel.create_window((400, 150))

    canvas2_toplevel.create_text(20, 80, text = f"{winner} wins!", font=("Times New Roman", 35), fill="white", anchor="nw")
    button = Button(canvas2_toplevel, text="Play again", font=("Times New Roman", 25), fg = "white", bg = 'gray12', activebackground='gray12', command=destruction)
    button.pack()
    window.mainloop()

def destruction():
    global window, winner
    winner = ' '
    window.destroy()
    play()

def play():
    boardinit()
    resetBoard()
    while winner == ' ' and checkFreeSpaces() != 0:
        GUI()
        if winner != ' ' or checkFreeSpaces() == 0:
            break

play()
window.mainloop()