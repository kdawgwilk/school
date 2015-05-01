import pygame
import config
from point import Point


class Button:
    def __init__(self, p1, p2, label, font, mode):
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
        self.setColor(config.BUTTON_BACKGROUND_COLOR)
        self.setTextColor(config.BUTTON_FOREGROUND_COLOR)
        return

    def setColor(self, color):
        self.color = color
        return

    def setTextColor(self, value):
        self.text_color = [x for x in value]
        return

    def setMode(self, mode):
        self.mode = mode
        return

    def paint(self, surface):
        pygame.draw.rect(surface, self.color, self.points)
        self.drawTextCenter(surface, self.label, self.text_color,
                            (self.x1 + self.x2) / 2, (self.y1 + self.y2) / 2, self.font)
        return
        
    def contains(self, point):
        return (point.getX() >= self.x1) and (point.getX() <= self.x2) and \
               (point.getY() >= self.y1) and (point.getY() <= self.y2)

    def getMode(self):
        return self.mode

    def drawTextCenter(self, surface, text, color, x, y, font):
        textobj = font.render(text, False, color)
        textrect = textobj.get_rect()
        textrect.center = (x, y)
        surface.blit(textobj, textrect)
        return