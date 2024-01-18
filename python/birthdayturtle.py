import turtle

t = turtle.Turtle()
s = turtle.Screen()
s.bgcolor('lightyellow')

#Unmark the hash in "s.tracer(0)" if you want the cake and text to form faster.
#s.tracer(0)

t.penup()
t.goto(-150, -100)
t.pendown()
t.pensize(2)
t.color('black', 'orange')
t.begin_fill()


for i in range (3):
    t.forward(300)
    t.left(90)
    t.forward(125)
    t.left(90)


t.end_fill()
t.forward(300)
t.left(90)


#Circle
t.color('black', 'yellow')


t.begin_fill()
t.circle(50, 180)
for i in range(2):
    t.left(180)
    t.circle(50,180)
t.end_fill()


t.left(90)
t.forward(70)
t.right(90)


t.color('black', 'pink')
t.begin_fill()
for i in range(3):
    t.forward(100)
    t.left(90)
    t.forward(160)
    t.left(90)
t.end_fill()

#Circle
t.color('black', 'yellow')
t.begin_fill()
for i in range(2):
    t.circle(40, 180)
    t.left(180)
t.end_fill()


t.right(90)
t.forward(160)
t.left(90)
t.forward(100)
t.right(90)
t.forward(70)

#Candle
def candle (x,y):
       t.color("black")
       t.penup()
       t.goto(x,y)
       t.pendown()
       t.begin_fill
       for i in range(2):
             t.forward(7)
             t.left(90)
             t.forward(25)
             t.left(90)
       t.end_fill()
     
       t.color("black", "yellow")
       t.begin_fill()
       for i in range(2):
             t.forward(7)
             t.right(90)
             t.forward(10)
             t.right(90)
       t.end_fill()

candle(55, 150)
candle(5, 150)
candle(-50, 150)

#Text
t.color ('Red')
t.penup()
t.goto(0, -175)
t.write ('Happy Birthday!', align='center', font="Segoeui 35 normal")
t.color ('Orange')
t.goto(0, -230)
t.write ('Tanya', align='center', font="Segoeprint 35 normal")
t.goto(0, -280)
t.color ('Purple')
t.write ('Best Wishes!', align='center', font="Segoeui 35 normal")


turtle.done()