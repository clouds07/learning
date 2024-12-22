# this allows us to use code from
# the open-source pygame library
# throughout this file
import pygame
from constants import *
from player import Player
from asteroid import Asteroid
from asteroidfield import AsteroidField
from shot import Shot

def main():
    print("Starting Asteroids!")

    pygame.init()
    
    updatable_group = pygame.sprite.Group()
    drawable_group = pygame.sprite.Group()
    asteroids_group = pygame.sprite.Group()
    bullets_group = pygame.sprite.Group()

    Player.containers = (updatable_group, drawable_group)
    Asteroid.containers = (asteroids_group, updatable_group, drawable_group)
    AsteroidField.containers = (updatable_group)
    Shot.containers = (bullets_group, updatable_group, drawable_group)

    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    clock = pygame.time.Clock()
    player = Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2)
    asteroidField = AsteroidField()

    dt = 0 
    game_over = False

    while True and not game_over:
        # Step 1: Check for player inputs
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return

        # Step 2: Update the game world
        for thing in updatable_group:
            thing.update(dt)

        for asteroid in asteroids_group:
            if asteroid.collides_with(player):
                game_over = True
                break

        for asteroid in asteroids_group:
            for bullet in bullets_group:
                if asteroid.collides_with(bullet):
                    asteroid.split()
                    bullet.kill()

        # Step 3: Draw the game onto the screen
        screen.fill("black")
        for thing in drawable_group:
            thing.draw(screen)

        pygame.display.flip()
        dt = clock.tick(60) / 1000

    print(f"COLLISION!\n\nGame Over!")
    pygame.quit()


if __name__ == "__main__":
    main()
