#add a settings menu to chose the difficulty (make balls faster and the paddle smaller) and to choose the theme 
#also make a GUI type word guessor game in tkinter

import pygame
from sys import exit
import numpy

#constants
light_grey = (200,200,200)
ball_x_speed = 10
ball_y_speed = 10
paddle_1_speed = 0
paddle_2_speed = 12
speed_const = 9
score_1 = 0
score_2 = 0

def ball_movement():
    global ball_x_speed, ball_y_speed
    ball.x += ball_x_speed
    ball.y += ball_y_speed
    
    #detecting collision with the walls
    if ball.x >= 1000 :
        ball_x_speed *= -1
    if ball.x <= 0:
        ball_x_speed *= -1
    if ball.y >= 800:
        ball_y_speed *= -1
    if ball.y <= 0:
        ball_y_speed *= -1
      
     #detecting collision with either of the paddles       
    if ball.colliderect(paddle_1) or ball.colliderect(paddle_2):
        ball_x_speed *= -1
    
    #bug fix
    if ball.colliderect(paddle_1) and ball.x < 10:
        ball.x += 20
        
    if ball.colliderect(paddle_2) and ball.x > 990:
        ball.x -= 20
        
    
def paddle_movement():
    global paddle_1_speed
    paddle_1.y += paddle_1_speed
    
    #so it doesnt fly off the screen
    if paddle_1.top < 0:
        paddle_1.top = 0
    if paddle_1.bottom > 800:
        paddle_1.bottom = 800
        
def opposition_ai():
    global paddle_2_speed
    
    if ball.x > 500:
        if paddle_2.top < ball.y:
            paddle_2.y += paddle_2_speed
        if paddle_2.bottom > ball.y:
            paddle_2.y -= paddle_2_speed
    
    #so it doesnt fly off the screen
    if paddle_2.top < 0:
        paddle_2.top = 0
    if paddle_2.bottom > 800:
        paddle_2.bottom = 800
        
        
def scoring():
    global score_1, score_2, font, player_text
    if ball.x <= 0:
        score_1 += 1 
    if ball.x >= 1000:
        score_2 += 1 
        
    return score_1, score_2
    
pygame.init()
screen = pygame.display.set_mode((1000,800))
pygame.display.set_caption("Pong!")
Clock = pygame.time.Clock()

paddle_1 = pygame.Rect(10, 275, 8, 200)
paddle_2 = pygame.Rect(982, 275, 8, 200)
ball = pygame.Rect(490, 380, 20, 20)
font = pygame.font.SysFont('timesnewroman', 25)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                paddle_1_speed -= speed_const
            if event.key == pygame.K_DOWN:
                paddle_1_speed += speed_const
        
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_UP: 
                paddle_1_speed += speed_const
            if event.key == pygame.K_DOWN:
                paddle_1_speed -= speed_const
        
        
                
    ball_movement()
    paddle_movement()
    scoring()
    player_text = font.render("test",False, light_grey)
    screen.blit(player_text,(660,470))
    opposition_ai() 
    
    screen.fill('grey12')
    pygame.draw.rect(screen, light_grey, paddle_1)
    pygame.draw.rect(screen, light_grey, paddle_2)
    pygame.draw.ellipse(screen, light_grey, ball)
    pygame.draw.aaline(screen, light_grey, (500,0), (500,800))
    
    
    pygame.display.update()
    Clock.tick(60)
           
   
