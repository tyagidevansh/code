import pygame, sys, random
from pygame.math import Vector2

class SNAKE:
    def __init__(self):
        self.body = [Vector2(5,10), Vector2(4,10), Vector2(3,10)]
        self.direction = Vector2(1,0)
        self.new_block = False
        
        self.head_up = pygame.image.load('graphics/head_up.png').convert_alpha()
        self.head_down = pygame.image.load('graphics/head_down.png').convert_alpha()
        self.head_right = pygame.image.load('graphics/head_right.png').convert_alpha()
        self.head_left = pygame.image.load('graphics/head_left.png').convert_alpha()
        
        self.tail_up = pygame.image.load('graphics/tail_up.png').convert_alpha()
        self.tail_down = pygame.image.load('graphics/tail_down.png').convert_alpha()
        self.tail_right = pygame.image.load('graphics/tail_right.png').convert_alpha()
        self.tail_left = pygame.image.load('graphics/tail_left.png').convert_alpha()
        
        self.body_vertical = pygame.image.load('graphics/body_vertical.png').convert_alpha()
        self.body_horizontal = pygame.image.load('graphics/body_horizontal.png').convert_alpha()
       
        self.body_bl = pygame.image.load('graphics/body_bl.png').convert_alpha()
        self.body_br = pygame.image.load('graphics/body_br.png').convert_alpha()
        self.body_tl = pygame.image.load('graphics/body_tl.png').convert_alpha()
        self.body_tr = pygame.image.load('graphics/body_tr.png').convert_alpha()
        self.crunch_sound = pygame.mixer.Sound('audio/crunch.wav')
        self.death_sound = pygame.mixer.Sound('audio/snake-death.mp3')
         
    def draw_snake(self):
        self.update_head_graphics()
        self.update_tail_graphics()
        
        for index, block in enumerate(self.body):
            block_rect = pygame.Rect(block.x * cell_size, block.y * cell_size, cell_size, cell_size)
            
            if index == 0:
                screen.blit(self.head, block_rect)
            elif index == len(self.body) - 1:
                screen.blit(self.tail, block_rect)
            else:
                previous_block = self.body[index + 1] - block
                next_block = self.body[index - 1] - block
                if previous_block.x == next_block.x:
                    screen.blit(self.body_vertical,block_rect)
                elif previous_block.y == next_block.y:
                    screen.blit(self.body_horizontal,block_rect)
                else:
                    if previous_block.x == -1 and next_block.y == -1 or previous_block.y == -1 and next_block.x == -1:
                        screen.blit(self.body_tl,block_rect)
                    elif previous_block.x == -1 and next_block.y == 1 or previous_block.y == 1 and next_block.x == -1:
                        screen.blit(self.body_bl,block_rect)
                    elif previous_block.x == 1 and next_block.y == -1 or previous_block.y == -1 and next_block.x == 1:
                        screen.blit(self.body_tr,block_rect)
                    elif previous_block.x == 1 and next_block.y == 1 or previous_block.y == 1 and next_block.x == 1:
                        screen.blit(self.body_br,block_rect)
                        
    def update_head_graphics(self):
        head_relation = self.body[1] - self.body[0]
        if head_relation == Vector2(1,0): self.head = self.head_left
        elif head_relation == Vector2(-1,0): self.head = self.head_right  
        elif head_relation == Vector2(0,1): self.head = self.head_up 
        elif head_relation == Vector2(0,-1): self.head = self.head_down 

    def update_tail_graphics(self):
        length = len(self.body)
        tail_relation = self.body[length - 1] - self.body[length - 2]
        if tail_relation == Vector2(1,0): self.tail = self.tail_right
        elif tail_relation == Vector2(-1,0): self.tail = self.tail_left
        elif tail_relation == Vector2(0,1): self.tail = self.tail_down
        elif tail_relation == Vector2(0,-1): self.tail = self.tail_up
    
    def move_snake(self):
        if self.new_block == True:
            body_copy = self.body[:]
            body_copy.insert(0, body_copy[0] + self.direction)
            self.body = body_copy[:]
            self.new_block = False
        else:
            body_copy = self.body[:-1]
            body_copy.insert(0, body_copy[0] + self.direction)
            self.body = body_copy[:]
    
    def add_block(self):
        self.new_block = True
class FRUIT:
    def __init__(self):
        self.randomize()
    
    def draw_fruit(self):
        fruit_rect = pygame.Rect(self.pos.x * cell_size, self.pos.y * cell_size, cell_size, cell_size)
        screen.blit(apple, fruit_rect)
    
    def randomize(self):
        self.x = random.randint(0, cell_number - 2)
        self.y = random.randint(0, cell_number - 1)
        self.pos = Vector2(self.x, self.y)
    
class MAIN:
    def __init__(self):
        self.snake = SNAKE()
        self.fruit = FRUIT()
        self.score = 0
        self.game_over_flag = False
        
        with open('highscores.txt', 'r') as file:
            self.high_score = int(file.read())
    
    def update_high(self):
        if self.score > self.high_score:
            with open('highscores.txt', 'w') as file:
                file.write(str(self.score))
        
    def reset(self):
        self.snake = SNAKE()
        self.fruit = FRUIT()
        self.score = 0
        self.game_over_flag = False
        with open('highscores.txt', 'r') as file:
            self.high_score = int(file.read())
    
    def update(self):
        self.snake.move_snake()
        self.check_collision()
        self.check_fail()
    
    def draw_elements(self):
        self.draw_grass()
        self.fruit.draw_fruit()
        self.snake.draw_snake()
        self.display_score()
        
    def check_collision(self):
        if self.fruit.pos == self.snake.body[0]:
            self.fruit.randomize()
            self.score += 1
            self.snake.add_block()
            self.snake.crunch_sound.play()
    
    def draw_grass(self):
        grass_color = (167, 209, 61)
        for row in range(cell_number):
            if row % 2 == 0:
                for col in range(cell_number):
                    if col % 2 == 0:
                        grass_rect = pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size)
                        pygame.draw.rect(screen, grass_color, grass_rect)
            else:
                for col in range(cell_number):
                    if col % 2 == 0:
                        grass_rect = pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size)
                        pygame.draw.rect(screen, grass_color, grass_rect)    
        
    
    def display_score(self):
        score_text = str(len(self.snake.body) - 3)
        score_surface = font.render(score_text, True, (56,74,12))
        score_x = int(cell_size * cell_number - 60)
        score_y = int(cell_size * cell_number - 40)
        score_rect = score_surface.get_rect(center = (score_x, score_y))
        apple_rect = apple.get_rect(midright = (score_rect.left, score_rect.centery))
        
        
        hs_text = font.render(str(self.high_score), True, (56, 64, 12))
        hs_x = int(cell_size * cell_number - 120)
        hs_y = int(cell_size * cell_number - 40)
        hs_rect = hs_text.get_rect(center = (hs_x, hs_y))
        trophy_rect = trophy.get_rect(midright = (hs_rect.left, hs_rect.centery))
         
        bg_rect = pygame.Rect(trophy_rect.left, apple_rect.top, apple_rect.width + score_rect.width + hs_rect.width + trophy_rect.width + 6, apple_rect.height)
        
        pygame.draw.rect(screen, (167, 209, 61), bg_rect)
        screen.blit(score_surface, score_rect)
        screen.blit(apple, apple_rect)
        screen.blit(hs_text, hs_rect)
        screen.blit(trophy, trophy_rect)
        pygame.draw.rect(screen, (56, 74, 12), bg_rect, 2)
    
    def check_fail(self):
        if not 0 <= self.snake.body[0].x < cell_number or not 0 <= self.snake.body[0].y < cell_number:
            self.game_over_flag = True
            self.snake.death_sound.play()
            self.update_high()
            
        for block in self.snake.body[1:]:
            if block == self.snake.body[0]:
                self.game_over_flag = True
                self.snake.death_sound.play()
                self.update_high()
                
    def game_over(self):
        if (self.game_over_flag == True):
            self.snake.body = [Vector2(5,10), Vector2(5,9), Vector2(5,8), Vector2(5,7), Vector2(5,6), Vector2(5,5), Vector2(6,5), 
                               Vector2(7,5), Vector2(8,5), Vector2(9,5), Vector2(10,5), Vector2(11,5), Vector2(12,5), Vector2(13,5),
                               Vector2(14,5), Vector2(14,6),Vector2(14,7),Vector2(14,8),Vector2(14,9),Vector2(14,10),Vector2(13,10)]
            screen.fill((172,215,70))
            self.draw_grass()
            self.snake.draw_snake()
            
            screen.blit(scaled_apple, (220, 215))
            score = font_large.render(":  "+ str(self.score), True, (56, 72, 12))
            score_rect = score.get_rect(center = (330,250))
            screen.blit(score, score_rect)
            
            go_text = font_large.render("Game Over!", True, (56, 72, 12))
            go_rect = go_text.get_rect(center = (300, 375))
            screen.blit(go_text, go_rect)
            
            play_text = font.render("Press R to play again", True, (56, 72, 12))
            play_rect = play_text.get_rect(center = (300, 420))
            screen.blit(play_text, play_rect)

pygame.init()
cell_size = 30
cell_number = 20
screen = pygame.display.set_mode((cell_size*cell_number, cell_size*cell_number))
pygame.display.set_caption("Snake")
clock = pygame.time.Clock()
apple = pygame.image.load('graphics/apple.png').convert_alpha()
trophy_raw = pygame.image.load('graphics/trophy.png').convert_alpha()
trophy = pygame.transform.scale(trophy_raw, (trophy_raw.get_width()*0.06, trophy_raw.get_height()*0.06))
scaled_apple = pygame.transform.scale(apple, (apple.get_width()*1.8, apple.get_height()*1.8))
font = pygame.font.Font('font/PoetsenOne-Regular.ttf', 28)
font_large = pygame.font.Font('font/PoetsenOne-Regular.ttf', 46)

pygame.mixer.music.load('audio/snake-bgm.mp3')
#pygame.mixer.music.play(-1)

SCREEN_UPDATE = pygame.USEREVENT
pygame.time.set_timer(SCREEN_UPDATE, 150)

main_game = MAIN()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        if main_game.game_over_flag == False:
            if event.type == SCREEN_UPDATE:
                main_game.update()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    if main_game.snake.direction.y != 1:
                        main_game.snake.direction = Vector2(0,-1)
                if event.key == pygame.K_DOWN:
                    if main_game.snake.direction.y != -1:
                        main_game.snake.direction = Vector2(0,1)
                if event.key == pygame.K_RIGHT:
                    if main_game.snake.direction.x != -1:
                        main_game.snake.direction = Vector2(1,0)
                if event.key == pygame.K_LEFT:
                    if main_game.snake.direction.x != 1:
                        main_game.snake.direction = Vector2(-1,0)
        else:
            main_game.game_over()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_r:
                main_game.reset()
    
    if main_game.game_over_flag == False:        
        screen.fill((172,215,70))
        main_game.draw_elements()
    
    pygame.display.update()
    clock.tick(60)