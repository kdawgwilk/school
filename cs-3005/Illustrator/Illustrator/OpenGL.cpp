// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include "OpenGL.h"


// Global Variables (Only what you need!)
int MODE = 3;
double SCREEN_X = 700;
double SCREEN_Y = 500;
std::vector<Point> POINTS;
std::vector<Shape*> SHAPES;
std::vector<Shape*> UNDO_SHAPES;
std::vector<Button*> BUTTONS;
std::vector<Slider*> SLIDERS;
std::vector<double> COLOR = {1, 0, 0};
const std::string FILENAME = "file.txt";


void save()
{
    int i;
    std::ofstream fout(FILENAME);
    if(!fout)
    {
        std::cerr << "Unable to open " << FILENAME << std::endl;
        return;
    }
    for(i = 0; i < SHAPES.size(); i++)
    {
        SHAPES[i]->save(fout);
    }
    fout.close();
}

void load()
{
    clear();
    std::string key;
    std::ifstream fin(FILENAME);
    if(!fin)
    {
        std::cerr << "Unable to open " << FILENAME << std::endl;
        return;
    }
    while(fin >> key)
    {
        Shape *s = 0;
        if (key == "Triangle")	{
            s = new Triangle();
        } else if (key == "Rectangle") {
            s = new Rectangle();
        } else if (key == "Circle") {
            s = new Circle();
        }
        s->load(fin);
        SHAPES.push_back(s);
    }
}

void undo()
{
    if (SHAPES.size() > 0) {
        Shape *tmp = SHAPES[SHAPES.size() - 1];
        SHAPES.pop_back();
        UNDO_SHAPES.push_back(tmp);
    } else {
        SHAPES.clear();
    }
}

void redo()
{
    if (UNDO_SHAPES.size() > 0) {
        Shape *tmp = UNDO_SHAPES[UNDO_SHAPES.size() - 1];
        UNDO_SHAPES.pop_back();
        SHAPES.push_back(tmp);
    } else {
        UNDO_SHAPES.clear();
    }
}

void clear()
{
    int i;
    POINTS.clear();
    for (i = int(SHAPES.size() - 1); i >= 0; i--) {
        UNDO_SHAPES.push_back(SHAPES[i]);
    }
    SHAPES.clear();
}

void drawPoints()
{
    for (auto itr : POINTS) {
        itr.draw();
    }
}

void drawShapes()
{
    for (auto itr : SHAPES) {
        itr->draw();
    }
}

void drawButtons()
{
    for (auto itr : BUTTONS) {
        itr->draw();
    }
}

void drawSliders()
{
    for (auto itr : SLIDERS) {
        itr->draw(COLOR);
    }
}

void createButtons()
{
    std::vector<double> defaultColor = {.6, .6, .6};
    BUTTONS.push_back(new Button(Point(10, 10), "Quit", 1, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 40), "Clear", 2, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 70), "Circle", 3, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 100), "Rectangle", 4, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 130), "Triangle", 5, defaultColor));
    
    BUTTONS.push_back(new Button(Point(10, 250), "Redo", 9, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 280), "Undo", 10, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 310), "Load", 11, defaultColor));
    BUTTONS.push_back(new Button(Point(10, 340), "Save", 12, defaultColor));
}

void createSliders()
{
    SLIDERS.push_back(new Slider(Point(10, 160), "Blue", 6, 0, COLOR));
    SLIDERS.push_back(new Slider(Point(10, 190), "Green", 7, 0, COLOR));
    SLIDERS.push_back(new Slider(Point(10, 220), "Red", 8, 1, COLOR));
}

// Outputs a string of text at the specified location.
void drawText(double x, double y, const char *string)
{
    void *font = GLUT_BITMAP_9_BY_15;
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    int len, i;
    glRasterPos2d(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
    
    glDisable(GL_BLEND);
}

void handleButtonClick(int x, int y, Button *btn)
{
    if (btn->getID() == 1) {
        exit(0);
    }
    if (btn->getID() == 2) {
        clear();
    }
    if (btn->getID() >= 3 && btn->getID() <= 5) {
        MODE = btn->getID();
        for (auto itr : BUTTONS) {
            itr->setActive(false);
        }
        btn->setActive(true);
    }
    if (btn->getID() == 9) {
        redo();
    }
    if (btn->getID() == 10) {
        undo();
    }
    if (btn->getID() == 11) {
        load();
    }
    if (btn->getID() == 12) {
        save();
    }
}

void handleSliderClick(int x, int y, Slider *slider)
{
    if (slider->getID() == 6) {
        COLOR[2] = slider->getValue();
    }
    if (slider->getID() == 7) {
        COLOR[1] = slider->getValue();
    }
    if (slider->getID() == 8) {
        COLOR[0] = slider->getValue();
    }
    for (auto itr : SLIDERS) {
        itr->setColor(COLOR);
    }
}

void handleOtherClick(int x, int y)
{
    POINTS.push_back(Point(x, y));
    if (MODE == 3 && POINTS.size() == 2) {
        SHAPES.push_back(new Circle(POINTS[0], POINTS[1], COLOR));
        POINTS.clear();
    }
    if (MODE == 4 && POINTS.size() == 2) {
        SHAPES.push_back(new Rectangle(POINTS[0], POINTS[1], COLOR));
        POINTS.clear();
    }
    if (MODE == 5 && POINTS.size() == 3) {
        SHAPES.push_back(new Triangle(POINTS[0], POINTS[1], POINTS[2], COLOR));
        POINTS.clear();
    }
}

//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Test lines that draw all three shapes and some text.
    // Delete these when you get your code working.
//    glColor3d(0,0,1);
    
    drawButtons();
    drawSliders();
    
    drawPoints();
    drawShapes();
    
//    glColor3d(1, 1, 1);
//    drawText(150, 100, "Can you see this black text and 3 blue shapes?");
    
    glutSwapBuffers();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    switch (c) {
        case 'q':
        case 27: // escape character means to quit the program
            exit(0);
            break;
        case 'u':
            // Undo Shape
            undo();
            break;
        case 'r':
            // Redo last undo
            redo();
            break;
        case 's':
            // Save to file
            save();
            break;
        case 'l':
            // Load from file
            load();
            break;
        case 'x':
            // Clear all Shapes
            clear();
            break;
        default:
            return; // if we don't care, return without glutPostRedisplay()
    }
    
    glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
    // Reset our global variables to the new width and height.
    SCREEN_X = w;
    SCREEN_Y = h;
    
    // Set the pixel resolution of the final picture (Screen coordinates).
    glViewport(0, 0, w, h);
    
    // Set the projection mode to 2D orthographic, and set the world coordinates:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y_inverted)
{
    // translate pixel coordinates to display coordinates
    //  int xdisplay = x;
    //  int ydisplay = screen_y - y;
    int y = SCREEN_Y - y_inverted;
    bool buttonClicked = false;
    bool sliderClicked = false;
    
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        for (auto itr : BUTTONS) {
            if (itr->contains(Point(x, y))) {
                handleButtonClick(x, y, itr);
                buttonClicked = true;
            }
        }
        for (auto itr : SLIDERS) {
            if (itr->contains(Point(x, y))) {
                handleSliderClick(x, y, itr);
                sliderClicked = true;
            }
        }
        if (!(buttonClicked || sliderClicked)) {
            handleOtherClick(x, y);
        }
    }
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
    }
    glutPostRedisplay();
}

// Your initialization code goes here.
void initMyStuff()
{
//    COLOR->push_back(255);
//    COLOR->push_back(0);
//    COLOR->push_back(0)
    createButtons();
    BUTTONS[2]->setActive(true);
    createSliders();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutInitWindowPosition(50, 50);
    
    int fullscreen = 0;
    if (fullscreen) {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    } else {
        glutCreateWindow("CS-3005 - Illustrator");
    }
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    
    glColor3d(0,0,0); // forground color
    glClearColor(0, 0, 0, 0); // background color
    
    // Initializes My Stuff
    initMyStuff();
    
    glutMainLoop();
    
    return 0;
}
