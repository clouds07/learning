# this allows us to use code from
# the open-source pygame library
# throughout this file
import pygame
from constants import *
from player import Player

def main():
    print("Starting asteroids!")
    print(f"Screen width: {SCREEN_WIDTH}")
    print(f"Screen height: {SCREEN_HEIGHT}")

    pygame.init()
    
    clock = pygame.time.Clock()
    dt = 0

    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

    player = Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2) 

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        # Step 1: Check for player inputs
        

        # Step 2: Update the game world

        # Step 3: Draw the game onto the screen
        sky_surface = pygame.surface.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
        sky_rect = pygame.Surface.fill(sky_surface, "black")

        player.update(dt)

        screen.fill("black")
        player.draw(screen)

        pygame.display.flip()
        dt = clock.tick(60) / 1000

    pygame.quit()


if __name__ == "__main__":
    main()
