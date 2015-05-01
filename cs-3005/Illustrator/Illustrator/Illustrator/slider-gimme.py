import config
import pygame
from point import Point

class Slider:

    def __init__(self, p1, p2, label, font, mode, value):
        # WRITE CODE HERE
        # most of this code should be similar to the Button class
        # just add the value data member
        # WRITE CODE HERE
        return


    # WRITE CODE HERE
    # most of this code should be similar to the Button class
    # this should handle color
    # WRITE CODE HERE

    def getOppositeColor(self):
        return [ 255-x for x in self.color ]

    def paint(self, surface):
        # WRITE CODE HERE
        # most of this code should be similar to the Button class
        # this draws the button, and draws the label
        # WRITE CODE HERE


        # this code assumes that :
        # self.ul is a Point object with the upper-left coordinates
        # self.lr is a Point object with the lower-right coordinates
        xmid = int(round(self.ul.getX() + self.value * (self.lr.getX()-self.ul.getX())))
        xleft = xmid - config.SLIDER_WIDTH/2
        xright = xmid + config.SLIDER_WIDTH/2
        points = [ (xleft,self.ul.getY()), (xright, self.ul.getY()),
                    (xright, self.lr.getY()), (xleft, self.lr.getY())]
        pygame.draw.polygon(surface, self.getOppositeColor(), points)
        return

    # This method replaces the contains method of the Button class
    # It sets self.value based on the location of the click in the button
    def contains(self, p):
        if (p.getX() >= self.ul.getX() and p.getX() <= self.lr.getX() and
            p.getY() >= self.ul.getY() and p.getY() <= self.lr.getY()):
            dx = p.getX() - self.ul.getX()
            mx = self.lr.getX() - self.ul.getX()
            self.value = float(dx)/float(mx)
            return True
        return False
        
    # WRITE CODE HERE
    # most of this code should be similar to the Button class
    # this should handle drawing text
    # WRITE CODE HERE
    
    
