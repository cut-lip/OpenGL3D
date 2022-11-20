//////// OpenGL Prac ////////
/////////////////////////////

#include <iostream>
#include <vector>
#include <math.h>
#include <vector>
#include "GL\glut.h"
//#include "myGLlib.h"
#include "Canvas.h"


//const int DATA_DIMENSION = 6;

Canvas cvs(640, 480, (char*)"Try Out Canvas Class");

// Draw n-gon with the given number of sides
void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
    // assumes global Canvas object, cvs
    if (n < 3) return;  // bad number of sides
    double angle = rotAngle * 3.14159265 / 180;     // initial angle
    double angleInc = 2 * 3.14159265 / n;           // angle increment

    cvs.moveTo(radius + cx, cy);

    for (int k = 0; k < n; k++)
    {
        angle += angleInc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void drawCircle(Point2 center, float radius)
{
    const int numVerts = 50;
    ngon(numVerts, center.getX(), center.getY(), radius, 0);
}

// Prepare the display
void display()
{
    cvs.clearScreen();
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);
    cvs.moveTo(0, -10.0);
    cvs.lineTo(0, 10.0);
    RealRect box(-2.0, 2.0, -1.0, 1.0);
    box.draw();
    //glFlush();
    ngon(10, 0, 0, 3, 0);
    glFlush();
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// void main(int argc, char** argv)
int main()
{
    // Window was previously opened in Canvas constructor
    cvs.setBackgroundColor(1.0, 1.0, 1.0);  // Set background to white
    cvs.setColor(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
