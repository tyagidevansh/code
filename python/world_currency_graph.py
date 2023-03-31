import pandas as pd
import matplotlib.pyplot as plt
from tkinter.ttk import *
from tkinter import *
from PIL import ImageTk,Image

window = Tk()
window.title("Graphs!")
window.geometry("1900x800")

def all_change():
    
    #importing all the csv files
    gbp = pd.read_csv (r'C:\Users\devan\Downloads\GBP_USD.csv')
    eur= pd.read_csv (r'C:\Users\devan\Downloads\EUR_USD.csv')
    inr = pd.read_csv (r'C:\Users\devan\Downloads\INR_USD.csv')
    turkey = pd.read_csv (r'C:\Users\devan\Downloads\TRY_USD.csv')
    cny = pd.read_csv (r'C:\Users\devan\Downloads\CNY_USD.csv')
    jpy = pd.read_csv (r'C:\Users\devan\Downloads\JPY_USD.csv')
        
    #percent change of all currencies against the dollar
    gbp_ = gbp['Change %'].iloc[::-1]
    eur_ = eur['Change %'].iloc[::-1]
    inr_ = inr['Change %'].iloc[::-1]
    try_ = turkey['Change %'].iloc[::-1]
    cny_ = cny['Change %'].iloc[::-1]
    jpy_ = jpy['Change %'].iloc[::-1]

        #removing all the % signs
    change_values = [gbp_, eur_, inr_, try_, cny_, jpy_]
    for countries in change_values:
        for i, x in countries.items():
            countries[i] = float(x.removesuffix('%'))
            
    x = (gbp['Date'].iloc[::-1])
    plt.plot(x,gbp_, label = 'Great British Pound')
    plt.plot(x,eur_, label = 'Euro')
    plt.plot(x,inr_, label = 'Indian Rupee')
    plt.plot(x,try_, label = 'Turkish Lira')
    plt.plot(x, cny_, label = 'Chinese Yuan')
    plt.plot(x, jpy_, label = 'Japanese Yen')

    plt.xlabel('Date')
    plt.ylabel('Percent change against the US dollar')
    plt.xticks(rotation = 'vertical')
    plt.legend()
    plt.show()

def gbp():
    gbp = pd.read_csv (r'C:\Users\devan\Downloads\GBP_USD.csv')

    x = gbp['Date'].iloc[::-1]
    y = gbp['Price'].iloc[::-1]

    plt.plot(x,y,color = "red")
    plt.xlabel('Date')
    plt.ylabel('Pound to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def eur():
    eur = pd.read_csv (r'C:\Users\devan\Downloads\EUR_USD.csv')

    x = eur['Date'].iloc[::-1]
    y = eur['Price'].iloc[::-1]

    plt.plot(x,y,color = "red")
    plt.xlabel('Date')
    plt.ylabel('Euro to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def inr():
    inr = pd.read_csv (r'C:\Users\devan\Downloads\INR_USD.csv')

    x = inr['Date'].iloc[::-1]
    y = inr['Price'].iloc[::-1]

    plt.plot(x,y,color = "red")
    plt.xlabel('Date')
    plt.ylabel('Rupee to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def turkey():
    turkey = pd.read_csv (r'C:\Users\devan\Downloads\TRY_USD.csv')

    x = turkey['Date'].iloc[::-1]
    y = turkey['Price'].iloc[::-1]

    plt.plot(x,y,color = "red")
    plt.xlabel('Date')
    plt.ylabel('Lira to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def cny():
    cny = pd.read_csv (r'C:\Users\devan\Downloads\CNY_USD.csv')

    x = cny['Date'].iloc[::-1]
    y = cny['Price'].iloc[::-1]

    plt.plot(x,y,color = "red")
    plt.xlabel('Date')
    plt.ylabel('Renminbi to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def jpy():
    jpy = pd.read_csv (r'C:\Users\devan\Downloads\JPY_USD.csv')

    x = jpy['Date'].iloc[::-1]
    y = jpy['Price'].iloc[::-1]

    plt.plot(x,y, color = "red")
    plt.xlabel('Date')
    plt.ylabel('Yen to Dollar')
    plt.xticks(rotation = 'vertical')
    plt.show()

def open1():   
    
    window2 = Toplevel()
    window2.title("Percent change")
    window2.geometry("900x900")
    button3 = Button(window2, text = "Compare the percent change of all available currencies", height = 4, width = 70, font =  40, command = all_change).place(x = 100, y = 400)
    
def open2():
    window3 = Toplevel()
    window3.title("Absolute change")
    window3.geometry("1000x1000")
    
    button4 = Button(window3, text = "GBP vs USD", height = 4, width = 30, font = 40, command = gbp).pack()
    button5 = Button(window3, text = "EUR vs USD", height = 4, width = 30, font = 40, command = eur).pack()
    button6 = Button(window3, text = "INR vs USD", height = 4, width = 30, font = 40, command = inr).pack()
    button7 = Button(window3, text = "TRY vs USD", height = 4, width = 30, font = 40, command = turkey).pack()
    button8 = Button(window3, text = "CNY vs USD", height = 4, width = 30, font = 40, command = cny).pack()
    button9 = Button(window3, text = "JPY vs USD", height = 4, width = 30, font = 40, command = jpy).pack()

    
img = ImageTk.PhotoImage(Image.open(r"C:\Users\devan\Downloads\dollar.jpg"))
label = Label(window, image = img).place(x = 0, y=0)   

button0 = Button(window, text = "Quit", height = 2, width = 7, font = 35, command = window.destroy).place(x= 1400, y= 720)
button1 = Button(window, text = "Graphs for percent change", height = 4, width = 40, font = 40, command = open1).place(x=200, y = 720)
button2 = Button(window, text = "Graphs for absolute change", height = 4, width = 40, font = 40,command = open2).place(x = 900, y = 720)

img = ImageTk.PhotoImage(Image.open(r"C:\Users\devan\Downloads\dollar.jpg"))
label = Label(window, image = img).place(x = 0, y=0)   

mainloop()