from pytimedinput import timedInput
import os

def print_field():
    for cell in CELLS:
        if cell in snake_body:
            print("X", end = '')
        if cell[0] in (0, FIELD_WIDTH-1) or cell[1] in (0, FIELD_HEIGHT-1):
            print("#", end = "") 
        elif cell == apple_pos:
            print('a', end='')
        else:
            print(' ', end = "")
        if cell[0] == FIELD_WIDTH-1:
            print('')

def update_snake():
    new_head = snake_body[0][0] + direction[0], snake_body[0][1] + direction[1]
    snake_body.insert(0, new_head)
    snake_body.pop(-1)
    
FIELD_WIDTH =  32
FIELD_HEIGHT = 16
CELLS = [(col, row) for row in range(FIELD_HEIGHT) for col in range(FIELD_WIDTH)]

#snake
snake_body = [(5,FIELD_HEIGHT//2),(4,FIELD_HEIGHT//2),(3,FIELD_HEIGHT//2)]
DIRECTIONS = {'left' : (-1,0), 'right': (1,0), 'up': (0,-1), 'down' : (0,1)}
direction = DIRECTIONS['right']

#apple
apple_pos = (5, 10)

while True:
    os.system('cls')
    
    print_field()
    
    txt,_ = timedInput('get input:', timeout=0.3)
    
    update_snake()