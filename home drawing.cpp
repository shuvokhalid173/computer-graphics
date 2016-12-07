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

void Home__ (void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(180, 250);
		glVertex2i(100,290);
		glVertex2i(20, 250);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2i(20, 250);
		glVertex2i(180, 250);
		glVertex2i(20, 250);
		glVertex2i(20, 50);
		glVertex2i(20, 50);
		glVertex2i(180, 50);
		glVertex2i(180, 50);
		glVertex2i(180, 250);
	glEnd();
    glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2i(70, 200);
		glVertex2i(130, 200);
		glVertex2i(70, 200);
		glVertex2i(70, 50);
		glVertex2i(70, 50);
		glVertex2i(130, 50);
		glVertex2i(130, 50);
		glVertex2i(130, 200);
	glEnd();
    glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2i(30, 190);
		glVertex2i(60, 190);
		glVertex2i(30, 190);
		glVertex2i(30, 150);
		glVertex2i(30, 150);
		glVertex2i(60, 150);
		glVertex2i(60, 150);
		glVertex2i(60, 190);
	glEnd();
    glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
        glVertex2i(140, 190);
		glVertex2i(170, 190);
        glVertex2i(140, 190);
		glVertex2i(140, 150);
		glVertex2i(140, 150);
		glVertex2i(170, 150);
		glVertex2i(170, 150);
		glVertex2i(170, 190);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(640 , 480);
	glutCreateWindow("Home_drawing");
	init();
	glutDisplayFunc(Home__);
	glutMainLoop();
	return 0;
}

