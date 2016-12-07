/// In the name of ALLAH , the Beneficent , the Merciful ///

#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void drawLine (int x0 , int y0 , int x1 , int y1) {
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);
    int dx = x1 - x0;
    int dy = y1 - y0;
    int limit = max (abs (dx) , abs (dy));
    double m = (double)dy / (double)dx;
    double x = (double)x0;
    double y = (double)y0;
    for (int i = 0; i < limit; i++) {
        if (m < 1) {
            glVertex2d(x , floor (y));
            y += m;
            x++;
        }
        else {
            glVertex2d(floor (x) , y);
            y++;
            x += (1.0 / m);
        }
        cout << x << " " << y << endl;
    }

    glEnd();
    glutSwapBuffers();
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100,0.0,100.0);
}
void display(void)
{
    glPointSize(2.0);
    drawLine(2 , 3 , 50 , 50);

}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("DDA Line Drawing!");
    init();glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

