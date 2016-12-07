/// In the name of ALLAH , the Beneficent , the Merciful ///

#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Set display window colour to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

int n;
int x , y;

void rect__ (int x , int y ) {
    glBegin(GL_LINES);
    int arr[123] = {x , x , x, x + 50 , x + 50 , x + 50 , x + 50 , x};
    int brr[123] = {y , y + 45 , y , y , y , y + 45 , y + 45 , y + 45};
    for (int i = 0; i < 8; i++)
        glVertex2i(arr[i] , brr[i]);
	glEnd();
}
void rect__shear (int x , int y , int shx , int shy) {
    glBegin(GL_LINES);
    int arr[123] = {x , x , x, x + 50 , x + 50 , x + 50 , x + 50 , x};
    int brr[123] = {y , y + 45 , y , y , y , y + 45 , y + 45 , y + 45};
    for (int i = 0; i < 8; i++) {
        int a = arr[i] + (shx * brr[i]);
        int b = brr[i] + (shy * arr[i]);
        printf ("%d %d\n" , a , b);
        glVertex2d (a , b);
    }
	glEnd();
}

void gooo (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glColor3f(1.0, 0.0, 0.0);
	rect__ (x , y);
	rect__shear (x , y , 4 , 4);
	glFlush();
}

void pentagon (int x , int y) {
    glBegin(GL_LINES);
    int arr[123] = {x , x + 10 , x + 10 , x + 30 , x + 30 , x + 40 , x + 40 , x + 20 , x + 20 , x};
    int brr[123] = {y , y + 40 , y + 40 , y + 25 , y + 25 , y + 10 , y + 10 , y - 10 , y - 10 , y};
    for (int i = 0; i < 10; i++)
        glVertex2i (arr[i] , brr[i]);
	glEnd();
}

void pentagon_shear (int x , int y , int shx , int shy) {
    glBegin(GL_LINES);
    int arr[123] = {x , x + 10 , x + 10 , x + 30 , x + 30 , x + 40 , x + 40 , x + 20 , x + 20 , x};
    int brr[123] = {y , y + 40 , y + 40 , y + 25 , y + 25 , y + 10 , y + 10 , y - 10 , y - 10 , y};
    for (int i = 0; i < 10; i++) {
        int a = arr[i] + (shx * brr[i]);
        int b = brr[i] + (shy * arr[i]);
        printf ("%d %d\n" , a , b);
        glVertex2d (a , b);
    }
	glEnd();
}
void goooo (void) {
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glColor3f(1.0, 0.0, 0.0);
	pentagon (x , y);
	pentagon_shear (x , y , 4 , 4);
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(10 , 10);
	glutInitWindowSize(640 , 480);
	glutCreateWindow("shearing");
	init();
    scanf ("%d" , &n);
    scanf ("%d%d" , &x , &y);
    if (n == 4) {
        glutDisplayFunc(gooo);
    }
    else if (n == 5) {
        glutDisplayFunc(goooo);
    }
	glutMainLoop();

	return 0;
}

