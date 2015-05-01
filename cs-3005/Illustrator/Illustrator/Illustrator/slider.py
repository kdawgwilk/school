import pygame
import config
from point import Point

class Slider:
    def __init__(self, p1, p2, label, font, mode, value):
        self.points = []
        self.x1 = min(p1.getX(), p2.getX())
        self.y1 = min(p1.getY(), p2.getY())
        self.x2 = max(p1.getX(), p2.getX())
        self.y2 = max(p1.getY(), p2.getY())
        self.points.append([self.x1, self.y1])
        self.points.append([self.x2 - self.x1, self.y2 - self.y1])
        self.label = label
        self.font = font
        self.mode = mode
        self.value = value
        self.color = [255, 0, 0]
        return

    def setColor(self, color):
        self.color = color
        return

    def setValue(self, value):
        self.value = value

    def getOppositeColor(self):
        return [255-x for x in self.color]

    def paint(self, surface):
        pygame.draw.rect(surface, self.color, self.points)
        xmid = int(round(self.x1 + self.value * (self.x2 - self.x1)))
        xleft = xmid - config.SLIDER_WIDTH / 2
        xright = xmid + config.SLIDER_WIDTH / 2
        points = [(xleft, self.y1), (xright, self.y1), (xright, self.y2), (xleft, self.y2)]
        pygame.draw.polygon(surface, self.getOppositeColor(), points)
        return

    def contains(self, point):
        if ((point.getX() >= self.x1) and (point.getX() <= self.x2) and
                (point.getY() >= self.y1) and (point.getY() <= self.y2)):
            dx = point.getX() - self.x1
            mx = self.x2 - self.x1
            self.value = float(dx)/float(mx)
            return True
        return False

    def getMode(self):
        return self.mode

    def getValue(self):
        return self.value