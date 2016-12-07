/// In the name of ALLAH , the Beneficent , the Merciful ///

#include <iostream>
#include <stdio.h>
#include <cstring>
#include<windows.h>
#include <GL/glut.h>

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void Rectangle__ (void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2i (100 , 100);
		glVertex2i (300 , 100);
		glVertex2i (300 , 100);
		glVertex2i (100 , 300);
		glVertex2i (100 , 300);
		glVertex2i (100 , 100);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(640 , 480);
	glutCreateWindow("Triangle_drawing");
	init();
	glutDisplayFunc(Rectangle__);
	glutMainLoop();
	return 0;
}

