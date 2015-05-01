import pygame


class Triangle:
    def __init__(self, p1, p2, p3):
        self.points = []
        self.points.append([p1.getX(), p1.getY()])
        self.points.append([p2.getX(), p2.getY()])
        self.points.append([p3.getX(), p3.getY()])
        self.color = [0, 0, 255]
        return

    def setColor(self, color):
        self.color = color
        return

    def paint(self, surface):
        pygame.draw.polygon(surface, self.color, self.points)
        return