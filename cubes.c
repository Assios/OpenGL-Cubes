#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

void draw1(int a, int b);

void init(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 0.2, 1.0, 0.0, 0.0 };
	glClearColor(0.5, 0.1, 0.2, 0.3);
	glShadeModel(GL_FLAT);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

float angle = 0.0;
float trans = 0.0;
int timer = 0;
float x_rotate = 0.0;
float y_rotate = 0.0;

int xpos;
int ypos;
int prevxpos;
int prevypos;

void mouse(int x, int y) {
	xpos = x;
	ypos = y;

	glutPostRedisplay();
}

void rotate(int a) {
        angle += 1.0f;
        if (angle >= 360) {
                angle = 0;
        }

        glutPostRedisplay();
        glutTimerFunc(25, rotate, a);
}

void move(int a) {
	if (timer < 350) {
		trans += 0.01f;
		timer++;
	}

	glutPostRedisplay();
	glutTimerFunc(25, move, a);
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
float y = 0.00;
void draw0(int size, int type) {
	if (type == 0)
		//To not change color when it's the number 10
		glColor3f (0.8, 1.0, 0.1);

	glPushMatrix();
	glTranslatef(-trans, y, 0.0);
	glScalef(1.0, 2.0, 1.0);
	glutSolidTorus(0.05, 0.2, 50, 50);
	glPopMatrix();
	if (timer < 100)
		y = y+0.002;
	else if (timer < 200)
		y = y-0.002;
	else if (timer < 300)
		y = y+0.002;
	else if (timer < 350)
		y = y-0.002;
}

void draw1(int size, int type) {
	if (type == 0)
		//To not change color when it's the number 10
		glColor3f(1.0, 0.0, 0.2);
	glTranslatef(trans, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.1, -0.18, 0.0);
	glScalef(0.8, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(0.1, 0.2, 0.0);
	glRotatef(60.0, 0.0, 0.0, 1.0);
	glScalef(0.2, 0.03, 0.03);
	drawCube(size, 9);
	glPopMatrix();
}

void draw4(int size) {
	glPushMatrix();
	glColor3f (1.0, 0.0, 0.6);
	glTranslatef(trans, 0.0, 0.0);
	if (timer < 350)
		glRotatef(angle, 0.0, 1.0, 0.0);
	else
		glRotatef(-10, 0.0, 1.0, 0.0);

	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);

	glTranslatef(0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.05, 0.2, 0.9);
	glScalef(0.5, 0.03, 0.03);
	drawCube(size, 9);
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
	glColor3f (0.2, 1.0, 0.1);

	glPushMatrix();

	glTranslatef(trans, 0.0, 0.0);
	if (timer < 350)
		glRotatef(angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.05, 0.2, 50, 50);
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0);
	glutSolidTorus(0.05, 0.2, 50, 50);
	glPopMatrix();
	glPopMatrix();
}

void draw10(int size) {
	glColor3f(0.3, 0.7, 0.2);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-2, 0.0, 0.0);
	draw1(1, 1);
	draw0(1, 1);
	glPopMatrix();
	glPopMatrix();
}

void display() {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();

	gluLookAt (0.0, 0.0, 4.0,
			   0.0, 0.0, 0.0,
			   0.0, 1.0, 0.0);

	glScalef (1.0, 1.0, 1.0);


	//FOR ROTATING SCREEN
	glRotatef(xpos, 0.0f, 1.0, 0.0f);

	glRotatef(ypos, 1.0f, 0.0, 0.0f);

	for (int i = 0; i < 5; i++) {
		glPushMatrix();
			//rotate to get the right perspective
			glRotatef( 1.0, 5.0, 0.0, 0.0 );
			glTranslatef(2 - 1.0 * i, 0.0f, 0.0f);
			drawCube(0.5, i);
			glLineWidth(2.5);
		glPopMatrix();
	}

	//Draw 0
	glPushMatrix();
	glTranslatef(3.0, -1.0, 0.0);
	draw0(1, 0);
	glPopMatrix();

	//Draw 1
	glPushMatrix();
	glTranslatef(-3.0, 1.0, 0.0);
	draw1(1, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, 1.0, 0.0);
	draw4(1);
	glPopMatrix();

	//Draw number 8
	glPushMatrix();
	glTranslatef(-4.0, 1.0, 0.0);
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
	glutTimerFunc(25, move, 0);

	glutPassiveMotionFunc(mouse);

	glutMainLoop();
	return 0;
}
