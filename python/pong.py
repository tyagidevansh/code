import turtle

def up_a():
    paddle_a.forward(20)

def up_b():
    paddle_b.forward(20)

def down_a():
    paddle_a.backward(20)

def down_b():
    paddle_b.backward(20)

screen = turtle.Screen()
screen.bgcolor("black")
screen.title("Pong!")
screen.setup(width = 800, height = 600)
screen.tracer(0)

score_a = 0
score_b = 0

player_a = screen.textinput("Pong!", "Player #1: ")
player_b = screen.textinput("Pong!", "Name of #2: ")

#pen
pen = turtle.Turtle()
pen.shape("square")
pen.color("white")
pen.pendown()
pen.hideturtle()
pen.goto(0,260)
pen.write("{} : {}    {} : {} ".format(player_a, score_a, player_b, score_b), align="center", font = ("Noto Sans Mono CJK JP", 24, "normal"))

#paddle a
paddle_a = turtle.Turtle()
paddle_a.left(90)
paddle_a.speed(10)
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid = 1, stretch_len = 5)
paddle_a.penup()
paddle_a.goto(-350,0)

#paddle b
paddle_b = turtle.Turtle()
paddle_b.speed(10)
paddle_b.left(90)
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid = 1, stretch_len = 5)
paddle_b.penup()
paddle_b.goto(350,0)

#ball
ball = turtle.Turtle()
ball.speed(6)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0,0)
ball.dx = 0.1
ball.dy = 0.1

#moving the paddles
screen.listen()
screen.onkey(up_a, "Up")
screen.onkey(up_b, "w")
screen.onkey(down_a, "Down")
screen.onkey(down_b, "s")

while True:
    screen.update()
    
    #moving the ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)
    
    if ball.ycor() > 290:
        ball.sety(290)
        ball.dy *= -1
    elif ball.ycor() < -290:
        ball.sety(-290)
        ball.dy *= -1
    elif ball.xcor() > 350:
        ball.goto(0,0)
        score_a += 1
        pen.clear()
        pen.write("{} : {}    {} : {} ".format(player_a, score_a, player_b, score_b), align="center", font = ("Noto Sans Mono CJK JP", 24, "normal"))
        ball.dx *= -1
    elif ball.xcor() < - 350:
        ball.goto(0,0)
        score_b += 1
        pen.clear()
        pen.write("{} : {}    {} : {} ".format(player_a, score_a, player_b, score_b), align="center", font = ("Noto Sans Mono CJK JP", 24, "normal"))
        ball.dx *= -1
        
    #detecting collision (miss chad colliderect)
    
    if ball.xcor() < -340 and ball.ycor() < paddle_a.ycor() + 50 and ball.ycor() > paddle_a.ycor() - 50:
        ball.dx *= -1
    
    elif ball.xcor() > 340 and ball.ycor() < paddle_b.ycor() + 50 and ball.ycor() > paddle_b.ycor() - 50:
        ball.dx *= -1
        
    