import config
import sys, math, pygame
from game import Game

from point import Point
from rectangle import Rectangle
from triangle import Triangle
from circle import Circle
from button import Button
from slider import Slider


MODE_QUIT = 1
MODE_CLEAR = 2
MODE_DRAW_CIRCLE = 3
MODE_DRAW_RECTANGLE = 4
MODE_DRAW_TRIANGLE = 5
MODE_COLOR_BLUE = 6
MODE_COLOR_GREEN = 7
MODE_COLOR_RED = 8
MODE_UNDO = 9

class Illustrator(Game):

    def __init__(self, name, screen_x, screen_y, frames_per_second):
        Game.__init__(self, name, screen_x, screen_y, frames_per_second)
        pygame.font.init()
        self.font = pygame.font.SysFont("Times New Roman",12)

        # list of shapes that have been created
        self.shapes = []
        
        # list of marker points to display
        self.points = []

        # current draw mode
        self.mode = MODE_DRAW_CIRCLE

        # current selected color
        self.color = [255, 0, 0]
        
        # List of buttons to display.  Fell free to to move them around to where you want them
        # Requires Point, Button classes.
        # Sliders are a special kind of button.  They require the Slider class.
        self.buttons = []
        self.buttons.append(Button(Point(10, screen_y - 10), Point(110, screen_y - 30), "Quit", self.font, MODE_QUIT))
        self.buttons.append(Button(Point(10, screen_y - 40), Point(110, screen_y - 60), "Clear", self.font, MODE_CLEAR))
        self.buttons.append(Button(Point(10, screen_y - 70), Point(110, screen_y - 90), "Circle", self.font, MODE_DRAW_CIRCLE))
        self.buttons.append(Button(Point(10, screen_y - 100), Point(110, screen_y - 120), "Rectangle", self.font, MODE_DRAW_RECTANGLE))
        self.buttons.append(Button(Point(10, screen_y - 130), Point(110, screen_y - 150), "Triangle", self.font, MODE_DRAW_TRIANGLE))
        self.buttons.append(Slider(Point(10, screen_y - 160), Point(110, screen_y - 180), "Blue", self.font, MODE_COLOR_BLUE, self.color[2]/255.))
        self.buttons.append(Slider(Point(10, screen_y - 190), Point(110, screen_y - 210), "Green", self.font, MODE_COLOR_GREEN, self.color[1]/255.))
        self.buttons.append(Slider(Point(10, screen_y - 220), Point(110, screen_y - 240), "Red", self.font, MODE_COLOR_RED, self.color[0]/255.))
        self.buttons.append(Button(Point(10, screen_y - 250), Point(110, screen_y - 270), "Undo", self.font, MODE_UNDO))

        # positions of the color sliders in the buttons list
        self.SLIDER_BLUE = 5
        self.SLIDER_GREEN = 6
        self.SLIDER_RED = 7

        for i in range(self.SLIDER_BLUE, self.SLIDER_RED + 1):
           self.buttons[i].setColor(self.color)
                             
        return

    def game_logic(self, keys, newkeys, buttons, newbuttons, mouse_position, dt):
        found = False
        prev_mode = self.mode

        # current mouse position.  Requires Point class
        p = Point(mouse_position[0], mouse_position[1])

        # If the left mouse button is held down, check if it is in a color slider
        # Requires the Slider class
        if 1 in buttons:
            for i in range(self.SLIDER_BLUE, self.SLIDER_RED+1):
                if self.buttons[i].contains(p):
                    self.mode = self.buttons[i].getMode()
                    found = True
                    self.points = []
                    break

        # If the left mouse button was just pressed, check if it is in a button, if not, add to the marker points
        # Requires Button and Point classes
        if 1 in newbuttons:
            for b in self.buttons:
                if b.contains(p):
                    self.mode = b.getMode()
                    found = True
                    self.points = []
                    break
            if not found:
                self.points.append(p)

        # In CIRCLE mode, create a circle if enough marker points have been given
        # Requires Circle and Point classes
        if self.mode == MODE_DRAW_CIRCLE:
            if not found and len(self.points) >= 2:
                center = Point(self.points[0].getX(), self.points[0].getY())
                dx = self.points[0].getX() - self.points[1].getX()
                dy = self.points[0].getY() - self.points[1].getY()
                radius = math.sqrt(dx * dx + dy * dy)
                s = Circle(center, radius)
                s.setColor(self.color)
                self.shapes.append(s)
                self.points = []

        # In RECTANGLE mode, create a rectangle if enough marker points have been given
        # Requires Rectangle and Point classes
        elif self.mode == MODE_DRAW_RECTANGLE:
            if not found and len(self.points) >= 2:
                s = Rectangle(self.points[0], self.points[1])
                s.setColor(self.color)
                self.shapes.append(s)
                self.points = []

        # In TRIANGLE mode, create a triangle if enough marker points have been given
        # Requires Triangle and Point classes
        elif self.mode == MODE_DRAW_TRIANGLE:
            if not found and len(self.points) >= 3:
                s = Triangle(self.points[0], self.points[1], self.points[2])
                s.setColor(self.color)
                self.shapes.append(s)
                self.points = []

        # If a color slider was moved, update color of all sliders
        # Requires Slider class
        elif self.mode == MODE_COLOR_BLUE or self.mode == MODE_COLOR_GREEN or self.mode == MODE_COLOR_RED:
            if found:
                self.color[0] = int(255*self.buttons[self.SLIDER_RED].getValue())
                self.color[1] = int(255*self.buttons[self.SLIDER_GREEN].getValue())
                self.color[2] = int(255*self.buttons[self.SLIDER_BLUE].getValue())
                self.mode = prev_mode
                for i in range(self.SLIDER_BLUE, self.SLIDER_RED+1):
                    self.buttons[i].setColor(self.color)

        # Empty the marker points and shapes.
        elif self.mode == MODE_CLEAR:
            if found:
                self.points = []
                self.shapes = []
                self.mode = prev_mode

        # Remove the latest shape
        elif self.mode == MODE_UNDO:
            if found:
                self.points = []
                if len(self.shapes) > 0:
                    self.shapes.pop()
                self.mode = prev_mode

        # Quit
        elif self.mode == MODE_QUIT:
            if found:
                sys.exit(0)

        # catch all for errors
        else:
            print "Bad Mode!:", self.mode

        return

    def paint(self, surface):
        surface.fill(config.BACKGROUND_COLOR)
        for s in self.shapes:
            s.paint(surface)
        for b in self.buttons:
            b.paint(surface)
        for p in self.points:
            p.paint(surface)
        return

def main():
    a = Illustrator(config.TITLE, config.SCREEN_X, config.SCREEN_Y, config.FRAMES_PER_SECOND)
    a.main_loop()
    return

if __name__ == "__main__":
    main()
