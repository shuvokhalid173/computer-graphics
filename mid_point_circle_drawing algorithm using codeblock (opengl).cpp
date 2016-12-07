/// In the name of ALLAH , the Beneficent , the Merciful ///


#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
const float PI=3.14;

void gooo (int x , int y , int x0 , int y0) {
    glVertex2i (x0 + x, y0 + y ) ;
    glVertex2i (x0 - x ,  y0 + y);
    glVertex2i (x0 + x, y0 - y);
    glVertex2i (x0 - x, y0 - y ) ;
    glVertex2i (x0 + y, y0 + x);
    glVertex2i (x0 - y , y0 + x);
    glVertex2i (x0 + y , y0 - x);
    glVertex2i (x0 - y , y0 - x);
}

void drawLine(int x0 , int y0 , int r){
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    int pk = 1 - r;
    int tx = 0;
    int ty = 2 * r;
    int x = 0;
    int y = r;
    gooo (x , y , x0 , y0);
    while (x < y) {
        if (pk < 0) {
            x++;
            ///glVertex2i(x , y);
            pk += 1 + (2 * x);
        }
        else {
            x++; y--;
            ///glVertex2i(x , y);
            pk += 1 + (2 * x) - (2 * y);
        }
        gooo (x , y , x0 , y0);
        printf ("%d %d\n" , x , y);
    }
    glEnd();
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,100.0,0.0,100,0.0,100.0);
}
void display(void)
{
    glPointSize (5.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(50 , 50 , 15);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(400 , 400);
    glutInitWindowPosition(10 , 10);
    glutCreateWindow("Midpoint_circle Drawing!");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

