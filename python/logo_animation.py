import turtle

screen = turtle.getscreen()

x = 500 #the amoun the pen will be moving each time
a = 120
color = ['#ffffff', '#e6ffff', '#ccf2ff', '#1aa3ff', '#0000ff', '#6600ff',  '#6600cc',  '#9900ff',  '#cc00cc',
         '#ff1aff',  '#ff66ff', '#ffb3b3', '#ff6666', '#ff3333',  '#ffb84d', '#ffff66' ,
         '#00ff00', '#ffffcc', '#e6ffe6' ]

screen.bgcolor("black")
screen.title("cool innit")

vt = turtle.Turtle()
vt.goto(-250, -250)

while True:
    for i in color:
        vt.color(i)
        vt.right(a)
        vt.backward(x)
        x = x-10
       
    
    
    
