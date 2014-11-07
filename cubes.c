#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

void init(void) {
	glClearColor(0.2, 0.1, 0.2, 0.1);
	glShadeModel(GL_FLAT);
}

float angle = 0.0;


void rotate(int a) {
        angle += 1.0f;
        if (angle >= 360) {
                angle = 0;
        }

        glutPostRedisplay();
        glutTimerFunc(25, rotate, a);
}

void move(int a) {
	
}

void drawCube(float size, int direction) {
	glPushMatrix();
    glTranslatef(0.5, 1.0, 0.0);
    glPopMatrix();

    if (direction%2==0)
    	glRotatef(angle, 0.0, 1.0, 0.0);
    else if (direction==1 || direction==3)
    	glRotatef(-angle, 0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
		glNormal3f(0.0f, size, 0.0f);	
		glVertex3f(-0.5*size, 0.5*size, 0.5*size);
		glVertex3f(0.5*size, 0.5*size, 0.5*size);
		glVertex3f(0.5*size, 0.5*size, -0.5*size);
		glVertex3f(-0.5*size, 0.5*size, -0.5*size);
	 
		glNormal3f(0.0f, 0.0f, 1.0*size);
		glVertex3f(0.5*size, -0.5*size, 0.5*size);
		glVertex3f(0.5*size, 0.5*size, 0.5*size);
		glVertex3f(-0.5*size, 0.5*size, 0.5*size);
		glVertex3f(-0.5*size, -0.5*size, 0.5*size);

		glNormal3f(1.0*size, 0.0f, 0.0f);
		glVertex3f(0.5*size, 0.5*size, -0.5*size);
		glVertex3f(0.5*size, 0.5*size, 0.5*size);
		glVertex3f(0.5*size, -0.5*size, 0.5*size);
		glVertex3f(0.5*size, -0.5*size, -0.5*size);
	 
		glNormal3f(-1.0*size, 0.0f, 0.0f);
		glVertex3f(-0.5*size, -0.5*size, 0.5*size);
		glVertex3f(-0.5*size, 0.5*size, 0.5*size);
		glVertex3f(-0.5*size, 0.5*size, -0.5*size);
		glVertex3f(-0.5*size, -0.5*size, -0.5*size);
	 
		glNormal3f(0.0f, -1.0*size, 0.0f);
		glVertex3f(0.5*size, -0.5*size, 0.5*size);
		glVertex3f(-0.5*size, -0.5*size, 0.5*size);
		glVertex3f(-0.5*size, -0.5*size, -0.5*size);
		glVertex3f(0.5*size, -0.5*size, -0.5*size);

		glNormal3f(0.0f, 0.0f, -1.0*size);
		glVertex3f(0.5*size, 0.5*size, -0.5*size);
		glVertex3f(0.5*size, -0.5*size, -0.5*size);
		glVertex3f(-0.5*size, -0.5*size, -0.5*size);
		glVertex3f(-0.5*size, 0.5*size, -0.5*size); 
	glEnd();
}

//DRAW NUMBERS
void draw1(int size) {
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.1, -0.18, 0.9);
	glScalef(0.8, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(0.1, 0.2, 0.9);
	glRotatef(60.0, 0.0, 0.0, 1.0);
	glScalef(0.2, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();
}

void draw4(int size) {
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);

	glTranslatef(0.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.6, 0.03, 0.03);
	drawCube(size, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.9);
	glScalef(0.6, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.2, -0.18, 0.9);
	glScalef(0.8, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();
	glPopMatrix();
}

void draw7(int size) {
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glRotatef(60.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.2, -0.18, 0.9);
	glScalef(0.8, 0.03, 0.03);
	drawCube(size, 9);

	glPopMatrix();

	glTranslatef(0.2, 0.29, 0.0);
	glPushMatrix();
	glScalef(0.6, 0.03, 0.03);
	drawCube(size, 5);
	glPopMatrix();
}

void draw8(int size) {
	glutSolidTorus(0.05, 0.2, 50, 50);
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0);
	glutSolidTorus(0.05, 0.2, 50, 50);
	glPopMatrix();
}

void display() {
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity ();

	gluLookAt (0.0, 0.0, 4.0,
			   0.0, 0.0, 0.0,
			   0.0, 1.0, 0.0);

	glScalef (1.0, 1.0, 1.0);

	glColor3f (0.0, 1.0, 0.6);

	for (int i = 0; i < 5; i++) {
		glPushMatrix();
			//rotate to get the right perspective
			glRotatef( 1.0, 5.0, 0.0, 0.0 );
			glTranslatef(2 - 1.0 * i, 0.0f, 0.0f);
			drawCube(0.5, i);
			glLineWidth(2.5);
		glPopMatrix();
	}

	draw4(1);

	//Draw 1
	glPushMatrix();
	glTranslatef(-1.0, 1.0, 0.0);
	draw1(1);
	glPopMatrix();

	//Draw number 8
	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	draw8(0.4);
	glPopMatrix();

	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutTimerFunc(25, rotate, 0);

	glutMainLoop();
	return 0;
}
