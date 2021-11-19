#include <stdlib.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include<string>
// sets the gl color by giving the function the colorname as a string
// if given color not defined, white is used
void setColor(const std::string& color) {
	if (color == "blue") {
		glColor3ub(0, 0, 255);
	} else if (color == "red") {
		glColor3ub(255, 0, 0);
	} else if (color == "yellow") {
		glColor3ub(254, 217, 15);
	} else if (color == "green") {
		glColor3ub(0, 255, 0);
	} else if (color == "black") {
		glColor3ub(0, 0, 0);
	} else if (color == "brown") {
		glColor3ub(208, 165, 96);
	} else if (color == "grey") {
		glColor3ub(122, 122, 122);
	} else {
		glColor3ub(255, 255, 255);
	}
}

void drawQuad(const std::string& color)
{
	setColor(color);

	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
	glEnd();
}

void drawTriangle(const std::string& color)
{
	setColor(color);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0);
		glVertex3f(0.5, -0.5, 0);
		glVertex3f(0, 0.5, 0);
	glEnd();
}

void drawLine(const std::string& color)
{
	setColor(color);

	glBegin(GL_LINES);
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0.5, 0, 0);
	glEnd();
}

void drawCircle(const std::string& color)
{
	setColor(color);

	glBegin(GL_TRIANGLE_FAN); // create triangle fan
		glVertex2f(0, 0); // set the first vertex in the center

		for (int i = 0; i <= 50; i++)
		{
			float angle = float(i) / 50.0 * 2.0 * M_PI; // calculate angle
			float x = sinf(angle) / 2.0; // to get a radius of 0.5 -> division
			float y = cosf(angle) / 2.0;

			glVertex2f(x, y); // set the vertex
		}
	glEnd();
}

void drawPolygon(const std::string& color) 
{
	setColor(color);
	
	glBegin(GL_POLYGON);
		glVertex3f(-0.2, 0.2, 0.0);
		glVertex3f(0.4, 0.1, 0.0);
		glVertex3f(-0.2, -0.3, 0.0);
		glVertex3f(-0.6, -0.1, 0.0);
	glEnd();
}

void drawToes() 
{
	glScalef(0.25, 0.25, 0);

	glPushMatrix();
		glTranslatef(-2.2, -0.6, 0); // single toe
		glRotatef(35, 0, 0, 1);
		drawLine("black");
	glPopMatrix();

	glPushMatrix(); // single toe
		glTranslatef(-1.7, -0.6, 0); // single toe
		glRotatef(35, 0, 0, 1);
		drawLine("black");
	glPopMatrix();

	glPushMatrix(); // single toe
		glTranslatef(-1.3, -0.8, 0); // single toe
		glRotatef(35, 0, 0, 1);
		drawLine("black");
	glPopMatrix();

	glPushMatrix(); // single toe
		glTranslatef(-0.8, -0.8, 0); // single toe
		glRotatef(35, 0, 0, 1);
		drawLine("black");
	glPopMatrix();
}

void drawFeet() 
{
	glPushMatrix(); // feet
		glTranslatef(0, -1.4, 0);

		glPushMatrix();
			glScalef(1.2, 1.3, 0);
			drawQuad("yellow");

			glRotatef(90, 0, 0, 1);
			drawLine("black");
		glPopMatrix(); // undo scaling

		glPushMatrix(); //toes
			glPushMatrix(); // left toes
				glTranslatef(-0.4, -0.74, 0);
				drawPolygon("yellow");
				drawToes();
			glPopMatrix(); // end left toe

			glPushMatrix(); //right toes
				glTranslatef(0.4, -0.74, 0);
				glScalef(-1, 1, 0);
				drawPolygon("yellow");
				drawToes();
			glPopMatrix(); // end right toe
		glPopMatrix(); // end toes

	glPopMatrix(); // end feet
}

void drawArms() 
{
	glPushMatrix(); //arms
		glScalef(0.5, 0.5, 0);
		glTranslatef(0, -1.5, 0);

		glPushMatrix(); // left hand
			glRotatef(-10, 0, 0, 1);
			glTranslatef(-1.5, 0, 0);
			drawPolygon("yellow");
		glPopMatrix(); // end left hand

		glPushMatrix(); // right hand
			glRotatef(10, 0, 0, 1);
			glTranslatef(1.5, 0, 0);
			glScalef(-1, 1, 0);
			drawPolygon("yellow");
		glPopMatrix(); // end right hand

	glPopMatrix(); // end arms
}

void drawBody() 
{
	glPushMatrix(); // body
		glScalef(2.2, 1.8, 0);
		drawCircle("yellow");

		glPushMatrix();
			glScalef(0.8, 1.2, 0);
			glTranslatef(0, -0.05, 0);
			drawCircle("white");
		glPopMatrix();

		glScalef(0.73, 1, 0);
		glTranslatef(0, -0.3, 0);
		drawLine("black");

	glPopMatrix(); // end body
}

void drawHair() 
{
	glPushMatrix(); //hair left
		glTranslatef(0, 0.9, 0);
		glRotatef(75, 0, 0, 1);
		drawLine("black");
	glPopMatrix();

	glPushMatrix(); //hair right
		glTranslatef(0.4, 0.8, 0);
		glRotatef(55, 0, 0, 1);
		drawLine("black");
	glPopMatrix();
}

void drawEyes() 
{
	glPushMatrix(); // eye
		// left eye
		glScalef(0.4, 0.4, 0);

		glPushMatrix(); //start left eye 
			//left eye
			glTranslatef(-0.5, 1, 0);
			drawCircle("white");

			// left pupille
			glScalef(0.2, 0.2, 0);
			drawCircle("black");
		glPopMatrix(); // end left eye

		glPushMatrix(); //start right eye 
			// right eye
			glTranslatef(0.5, 1, 0);
			drawCircle("white");

			//right pupille
			glScalef(0.2, 0.2, 0);
			drawCircle("black");
		glPopMatrix();	// end right eye
	glPopMatrix(); // end eyes
}

void drawEars() 
{
	glPushMatrix(); // ears
		glScalef(0.2, 0.2, 0);

		glPushMatrix(); // left ear
			glTranslatef(-1.8, 0.8, 0);
			drawCircle("yellow");

			glRotatef(155, 0, 0, 1);
			glScalef(0.5, 0.2, 0);
			glTranslatef(0, 0.5, 0);
			drawTriangle("black");
		glPopMatrix();

		glPushMatrix(); // right ear
			glTranslatef(1.8, 0.8, 0);
			drawCircle("yellow");

			glRotatef(-155, 0, 0, 1);
			glScalef(0.5, 0.2, 0);
			glTranslatef(0, 0.5, 0);
			drawTriangle("black");
		glPopMatrix();

	glPopMatrix(); // end ears
}

void drawMouth() 
{
	glPushMatrix(); // mouth
		glScalef(0.8, 0.7, 0);
		glTranslatef(0, -0.2, 0);
		drawCircle("brown");
		
		glRotatef(155, 0, 0, 1);
		glScalef(0.3, 0.1, 0);
		glTranslatef(0, 1.5, 0);
		drawTriangle("black");
	glPopMatrix(); // end mouth
}

void drawHead() 
{
	glPushMatrix(); // head
		glTranslatef(0, 1.5, 0);

		glPushMatrix(); // save translation of head before scaling
			glScalef(0.7, 1.3, 0);
			drawQuad("yellow");

			glPushMatrix(); // set top and bottom circle of head
				glScalef(1, 0.6, 0);

				glPushMatrix(); //top of head
					glTranslatef(0, 0.8, 0);
					drawCircle("yellow");
					drawHair();
				glPopMatrix();

				glPushMatrix(); // bottom of head
					glTranslatef(0, -0.8, 0);
					drawCircle("yellow");
				glPopMatrix();
			glPopMatrix(); // end of drawing head-circles
		glPopMatrix(); // end of head scaling

		drawMouth();
		drawEyes();
		drawEars();

		glPushMatrix();
			glTranslatef(0, 0.2, 0);
			glScalef(0.25, 0.25, 0);
			drawCircle("yellow");
		glPopMatrix();

	glPopMatrix(); // end head
}

void drawHomer() 
{
	drawFeet();
	drawArms();
	drawBody();
	drawHead();
}

//render method (callback-function)
void display()
{
	//clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	drawHomer();

	//don't wait! process buffered OpenGL routines
	glFlush();	
}

//initialization of the application. only started once.
void init() 
{
	//select clearing color (color that is used as 'background')
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//initialize view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.6, 2.6, -2.6, 2.6, -1.0, 1.0); // normal front camera, size halved
	// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	
	//set matrix-mode back to model-view for rendering
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	//initialize display mode (single buffer and RGBA)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//initialize window size and position. open window
	glutInitWindowSize(350, 350); 
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Homer in OpenGL");

	//call initialization routine
	init();
	
	//register callback function to display graphics
	glutDisplayFunc(display); 
	
	//enter main loop and process events
	glutMainLoop();

	return 0;
}
