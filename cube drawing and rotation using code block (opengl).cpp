/// In the name of ALLAH , the Beneficent , the Merciful ///

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#define PI 3.14159265
using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	
	glMatrixMode(GL_PROJECTION);		
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

int x , y;
int theta;

void rectangle1 (int x , int y) {
    glBegin(GL_LINES);
		 int r1x[123] = {x , x , x , x + 20 , x + 20 , x + 20 , x + 20 , x};
		 int r1y[123] = {y + 15 , y , y , y , y , y + 15 , y + 15 , y + 15};
		 for (int i = 0; i < 8; i++) {
            int a , b;
            a = r1x[i];
            b = r1y[i];
            glVertex2i(a , b);
		 }

	glEnd();
}

void rectangle2 (int x , int y) {
    glBegin(GL_LINES);
		int r2x[123] = {x + 5 , x + 5 , x + 5 , x + 25 , x + 25 , x + 25 , x + 25 , x + 5};
		int r2y[123] = {y + 10 , y - 5 , y - 5 , y - 5 , y - 5 , y + 10 , y + 10 , y + 10};
		for (int i = 0; i < 8; i++){
            int a , b;
            a = r2x[i];
            b = r2y[i];
            glVertex2i(a , b);
		}

	glEnd();
}

void rectangle3 (int x , int y) {
    glBegin(GL_LINES);
    int r3x[123] = {x , x + 5 , x , x + 5 , x + 25 , x  + 20 , x + 20 , x + 25};
    int r3y[123] = {y , y - 5 , y + 15 , y + 10 , y - 5 , y , y + 15 , y + 10};
    for (int i = 0; i < 8; i++){
        int a = r3x[i];
        int b = r3y[i];
        glVertex2i(a , b);
    }
	glEnd();
}

void cube_ (int x , int y) {
    rectangle1(x , y);
	rectangle2 (x , y);
	rectangle3 (x , y);
}

void new_rect1 (int x , int y , int t) {
    cout << "1.     " << endl << endl;
    glBegin(GL_LINES);
		 int r1x[123] = {x , x , x , x + 20 , x + 20 , x + 20 , x + 20 , x};
		 int r1y[123] = {y + 15 , y , y , y , y , y + 15 , y + 15 , y + 15};
		 for (int i = 0; i < 8; i++) {
            int a , b;
            a = r1x[i];
            b = r1y[i];
            double sin_ = sin (t * PI / 180.0);
            double cos_ = cos (t * PI / 180.0);
            double xp = (a * cos_) - (b * sin_);
            double yp = (a * sin_) + (b * cos_);
            cout << floor (xp) << " " <<  floor (yp) << endl;
            glVertex2d(floor (xp) , floor (yp));
		 }

	glEnd();
}

void new_rect2 (int x , int y , int t) {
    cout << endl << "2. " << endl;
    glBegin(GL_LINES);
		int r2x[123] = {x + 5 , x + 5 , x + 5 , x + 25 , x + 25 , x + 25 , x + 25 , x + 5};
		int r2y[123] = {y + 10 , y - 5 , y - 5 , y - 5 , y - 5 , y + 10 , y + 10 , y + 10};
		for (int i = 0; i < 8; i++){
            int a , b;
            a = r2x[i];
            b = r2y[i];
            double sin_ = sin (t * PI / 180.0);
            double cos_ = cos (t * PI / 180.0);
            double xp = (a * cos_) - (b * sin_);
            double yp = (a * sin_) + (b * cos_);
            cout << floor (xp) << " " <<  floor (yp) << endl;
            glVertex2d(floor (xp) , floor (yp));
		}

	glEnd();
}

void new_rect3 (int x , int y , int t) {
    cout << endl << " 3..." << endl;
    glBegin(GL_LINES);
    int r3x[123] = {x , x + 5 , x , x + 5 , x + 25 , x  + 20 , x + 20 , x + 25};
    int r3y[123] = {y , y - 5 , y + 15 , y + 10 , y - 5 , y , y + 15 , y + 10};
    for (int i = 0; i < 8; i++){
        int a = r3x[i];
        int b = r3y[i];
        double sin_ = sin (t * PI / 180.0);
            double cos_ = cos (t * PI / 180.0);
            double xp = (a * cos_) - (b * sin_);
            double yp = (a * sin_) + (b * cos_);
            cout << floor (xp) << " " <<  floor (yp) << endl;
            glVertex2d(floor (xp) , floor (yp));
    }
	glEnd();
}

void rotate_cube (int x , int y , int t) {
    new_rect1 (x , y , t);
    new_rect2 (x , y , t);
    new_rect3 (x , y , t);
}

void gooo (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glColor3f(1.0, 0.0, 0.0);
	cube_(x , y);
	rotate_cube (x , y , theta);
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(10 , 10);
	glutInitWindowSize(640 , 480);
	glutCreateWindow("cube drawing");
	init();
	printf ("enter initial point \n");
	scanf ("%d%d" , &x , &y);
	printf ("enter the degree of angle you want to rotate ");
	scanf ("%d" , &theta);
	glutDisplayFunc(gooo);
	glutMainLoop();

	return 0;
}

