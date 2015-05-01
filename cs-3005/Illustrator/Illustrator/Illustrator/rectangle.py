import pygame


class Rectangle:
    def __init__(self, p1, p2):
        self.points = []
        self.x1 = min(p1.getX(), p2.getX())
        self.y1 = min(p1.getY(), p2.getY())
        self.x2 = max(p1.getX(), p2.getX())
        self.y2 = max(p1.getY(), p2.getY())
        self.points.append([self.x1, self.y1])
        self.points.append([self.x2 - self.x1, self.y2 - self.y1])
        self.color = [0, 255, 0]
        return

    def setColor(self, color):
        self.color = color
        return

    def paint(self, surface):
        pygame.draw.rect(surface, self.color, self.points)
        return