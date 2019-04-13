#include <iostream>
#include <utility>

#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "data.h"

using namespace std;

//author: C.M.H.

unsigned char frame[windowW * windowH * 3];

void OnKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;
    }
}

void DrawPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x >= windowW || y >= windowH)
        return;

    unsigned int index = 3 * (y * windowW + x);
    frame[index] = r;
    frame[index + 1] = g;
    frame[index + 2] = b;
}

//author: C.M.H.
void line( int x1,  int y1,  int x2,  int y2, unsigned char r, unsigned char g, unsigned char b)
{
    int dx  = x2 - x1,
    dy  = y2 - y1,
    y   = y1,
    epsilon = 0; // epsilon as error.

    /*
     * As we know, a Bresenham's Algo must work together for 8 octants. Starts from 12 o' clock, I named the first
     * octants as #1, then #2; the 3'o clock's as #3, #4, lastly end with #8.
     *
     * Obviously, Case 2 and Case 1 is the basis of all cases. Case 2 could generate #3, #7, #6 and Case 1 do the rest.
     *
     * Case 2, I learn from class note, and I do the rest all by myself.
     */

    /* First four groups: based on Case 2 */

    if(0 <= dy && dy <= dx){ // 0 < m < 1, case 2
        //std::cout << "case 2" << std::endl;
        for(int x = x1; x <= x2; x+=1){
            DrawPixel(x,y,r,g,b);
            epsilon += dy;
            if ( (epsilon << 1) >= dx )  { //Some little optimization, avoiding division with left-shift.
                y++;  epsilon -= dx;
            }
        }
    }

    if(dy >=0 && dy <= -dx){ // 0 > m > -1, case 7

        // Case 7 is mirror of 2, around y-axis.  So change For Loop's order, and dx, dy into abs.

        //std::cout << "case 7" << std::endl;
        dx = -dx;
        for(int x = x1; x >= x2; x-=1){
            DrawPixel(x,y,r,g,b);
            epsilon += dy;
            if ( (epsilon << 1) >= dx )  {
                y++;  epsilon -= dx;
            }
        }
    }

    else if(dy <= 0 && -dy <= dx){ // -1 < m < 0, case 3

        // 3 is mirror of 2, around x-axis. So y++ => y--, and dx, dy into abs.

        //std::cout << "case 3" << std::endl;
        dy = -dy;
        for(int x = x1; x <= x2; x+=1){
            DrawPixel(x,y,r,g,b);
            epsilon += dy;
            if ( (epsilon << 1) >= dx )  {
                y--;  epsilon -= dx;
            }
        }
    }

    //Another version of case 3 is regard it as case 7's reverse. So exchange the end points.
    //Bresenham(x2,y2, x1, y1);

    else if(dy <= 0 && dx <= dy){ // -1 < m < 0, case 6
        //case 6 is just a reverse of case 2. So exchange the end points.
        line(x2,y2, x1, y1,r,g,b);
    }


    /* Another four groups: based on Case 1
     *
     * The design idea of Case 1 is, it's a mirror around line y = x.
     *
     * So simply exchange x,y, and all is done.
     * However, just call Bre(y1,x1,y2,x2) won't work for it.
     */

    else if(0 <= dx && dx <= dy){ // m > 1, case 1

        //Case 1 is case 2's sibling: Change every x and y, but don't change Draw(x,y).

        //std::cout << "case 1" << std::endl;

        int x = x1;
        for(int y = y1; y <= y2; y+=1){
            DrawPixel(x,y,r,g,b);
            epsilon += dx;
            if ( (epsilon << 1) >= dy )  {
                x++;  epsilon -= dy;
            }
        }
    }

    else if(dx <= 0 && -dx <= dy){ // m < -1, case 8

        //Case 8 is case 1's mirror around y-axis. Simply change the order of for loop; Abs dx, dy; and x = x1 => x = x2;

        //std::cout << "case 8" << std::endl;

        dx = -dx;
        int x = x2;
        for(int y = y2; y >= y1; y-=1){
            DrawPixel(x,y,r,g,b);
            epsilon += dx;
            if ( (epsilon << 1) >= dy )  {
                x++;  epsilon -= dy;
            }
        }
    }

    else if(dx <= 0 && dy <= dx){ // m < -1, case 5
        //case 5 is just a reverse of case 1. So exchange the end points.
        line(x2,y2, x1, y1,r,g,b);
    }

    else if(0 <= dx && dy <= -dx){ // m < -1, case 4
        //case 4 is just a reverse of case 8. So exchange the end points.
        line(x2,y2, x1, y1,r,g,b);
    }
}

void line( int x1,  int y1,  int x2,  int y2)
{
    line (x1, y1, x2, y2, 0, 0, 0);
}

void Draw();

void OnDisplay() {
    memset(frame, 255, windowW * windowH * 3);
    //main print function
    Draw();
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(windowW, windowH, GL_RGB, GL_UNSIGNED_BYTE, (GLubyte*)&frame);
    glutSwapBuffers();
    glFlush();
}

