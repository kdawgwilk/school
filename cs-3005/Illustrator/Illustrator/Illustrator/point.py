import pygame


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        return

    def setX(self, x):
        self.x = x
        return

    def setY(self, y):
        self.y = y
        return

    def paint(self, surface):
        pygame.draw.circle(surface, (255, 255, 255), (self.x, self.y), 3, 0)
        return

    def getX(self):
        return self.x

    def getY(self):
        return self.y