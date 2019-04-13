#include <iostream>
#include "draw.h"
#include "math.h"

void Draw()
{

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowW, windowH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hw 2 - For loop training");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glutDisplayFunc(OnDisplay);
    glutKeyboardFunc(OnKeyboard);
    glutMainLoop();

    return 0;
}

/*
void Draw()
{
    int startX = 0;
    int startY = windowH/2;
    int j = startY;
    for(int i = 0; i < windowW; i++)
    {
        line(i,100*sin((i)* M_PI/128) + j,
             i+1, 100*sin((i+1)* M_PI/128) + j);
    }
}


 */
