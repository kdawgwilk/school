import pygame


class Circle:
    def __init__(self, center, radius):
        self.center = [center.getX(), center.getY()]
        self.radius = int(radius)
        self.color = [255, 0, 0]
        return

    def setColor(self, color):
        self.color = [ x for x in color ]
        return

    def setCenter(self, newCenter):
        self.center = newCenter
        return

    def paint(self, surface):
        pygame.draw.circle(surface, self.color, self.center, self.radius, 0)
        return