import pygame
import math

pygame.init()

WIDTH, HEIGHT = 800,800
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Planet Simulator")


white = (255,255,255)
yellow = (253,184,19)
blue = (40,122,184)
grey = (219,206,202)
red = (156,46,53)


class Celestial_body:
    AU = 149.6e6 * 1000
    G = 6.67428e-11 
    scale = 150/AU
    Time = 3600*24 

    def __init__(self,x,y,radius,color,mass, name):
        self.radius = radius
        self.color = color
        self.mass = mass
        self.name = name
        self.x = x
        self.y = y

        self.font = pygame.font.Font(None, 20)

        self.sun = False
        self.distance_to_sun = 0
        self.orbit = []

        self.x_velocity =0
        self.y_velocity =0


    def draw(self, win): 
        x = self.x * self.scale + WIDTH/2
        y = self.y * self.scale + HEIGHT/2

        if len(self.orbit) > 2:

            updated_points  = []
            for point in self.orbit:
                x,y = point
                x = x*self.scale + WIDTH/2
                y = y*self.scale + HEIGHT/2
                updated_points.append((x,y))

            pygame.draw.lines(win, self.color, False, updated_points,2)
        
        text_surface = self.font.render(self.name, True, (255, 255, 255))  
        text_rect = text_surface.get_rect()
        text_rect.center = (x, y+ self.radius+12)  
        win.blit(text_surface, text_rect)
        pygame.draw.circle(win,self.color,(x,y),self.radius)



    def attraction(self, other):
        other_x, other_y = other.x,other.y
        distance_x = other_x -self.x
        distance_y = other_y -self.y
        distance = math.sqrt(distance_x**2 + distance_y**2)

        if other.sun:
            self.distance_to_sun = distance

        force = self.G * self.mass * other.mass/distance**2
        theta = math.atan2(distance_y,distance_x)
        force_x = math.cos(theta)*force
        force_y = math.sin(theta)*force
    
        return force_x,force_y
    
    def update_position(self, celestial_bodies):
        total_force_x = total_force_y = 0
        for celestial_body in celestial_bodies:
            if self == celestial_body:
                continue

            fx,fy = self.attraction(celestial_body)
            total_force_x += fx
            total_force_y += fy

        self.x_velocity += total_force_x/self.mass *self.Time
        self.y_velocity += total_force_y/self.mass *self.Time


        self.x += self.x_velocity* self.Time
        self.y += self.y_velocity* self.Time
        self.orbit.append((self.x, self.y)) 


def main():
    run = True
    clock = pygame.time.Clock()

    sun = Celestial_body(0,0,30,yellow,1.98892 * 10**30, "Sun",)
    sun.sun = True

    Earth = Celestial_body(-1*Celestial_body.AU, 0,16,blue,  5.9742 * 10**24,"Earth",)
    Earth.y_velocity = 29.783 * 1000

    Mars = Celestial_body(-1.524*Celestial_body.AU, 0,12,red, 6.39 * 10**23,"Mars",)
    Mars.y_velocity = 24.077 * 1000

    Mercury = Celestial_body(0.387*Celestial_body.AU, 0,9,red, 3.30 * 10**23,"Mercury",)
    Mercury.y_velocity = -47.4 * 1000

    Venus = Celestial_body(0.723 * Celestial_body.AU, 0, 14, white, 4.8685 * 10**24,"Venus")
    Venus.y_velocity = -35.02 * 1000

    Celestial_bodies = [sun, Earth, Mars, Mercury,Venus]

    while run:
        clock.tick(60)
        WIN.fill((0,0,0))
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
    
        for celestial_body in Celestial_bodies:
            celestial_body.update_position(Celestial_bodies)
            celestial_body.draw(WIN)

        pygame.display.update()
    
    pygame.quit()

main()


