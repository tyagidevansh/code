import pygame, sys

class FRUIT:
    def __init__(self):
        self.x = 5
        self.y = 4
        

pygame.init()
cell_size = 30
cell_number = 20
screen = pygame.display.set_mode((cell_size*cell_number, cell_size*cell_number))
clock = pygame.time.Clock()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
            
    screen.fill((172,215,70))
    pygame.display.update()
    clock.tick(60)