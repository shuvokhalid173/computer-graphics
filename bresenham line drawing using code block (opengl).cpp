/// In the name of ALLAH , the Beneficent , the Merciful ///

#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>

void drawLine(int x0,int y0,int x1,int y1){
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,.0);
    glVertex2d(x0 , y0);
    int dx = abs (x1 - x0);
    int dy = abs (y1 - y0);
    int tdx = 2 * dx;
    int tdy = 2 * dy;
    int pk = tdy - dx;
    int diff = tdy - tdx;
    int x = x0;
    int y = y0;
    printf ("%d %d %d \n" , pk , x , y);
    for (int i = 0; i < dx; i++) {
        if (pk > 0) {
            x++; y++;
            glVertex2i(x , y);
            pk += diff;
        }
        else {
            x++;
            glVertex2i(x , y);
            pk += tdy;
        }
        printf ("%d %d %d \n" , pk , x , y);
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
    glPointSize(5.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(20 , 10 , 80 , 70);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640 , 480);
    glutInitWindowPosition(10 , 10);
    glutCreateWindow("Bresenham line drawing ..");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

