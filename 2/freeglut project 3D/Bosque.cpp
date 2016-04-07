#include "Bosque.h"



Bosque::Bosque(){
	q = gluNewQuadric();
}


Bosque::~Bosque(){
	gluDeleteQuadric(q);
}

void Bosque::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	
	//Abeto
	glPushMatrix();
	glTranslated(6.0, 0.0, 6.0);
	this->dibujaAbeto();

	glPopMatrix();

	//Pino
	glPushMatrix();

	glTranslated(6.0, 0.0, -6.0);
	this->dibujaPino();

	glPopMatrix();

	//Roble
	glPushMatrix();

	glTranslated(-6.0, 0.0, 6.0);
	this->dibujaRoble();

	glPopMatrix();

	//Alamo
	glPushMatrix();
	
	glTranslated(-6.0, 0.0, -6.0);
	this->dibujaAlamo();

	glPopMatrix();
}

void Bosque::dibujaAbeto(){
	float h = 2;
	dibujaTronco(0.5, h, 25, 25);
	
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.1, 1, 0.1);


	//Copa
	int radioCopa = 1.5;
	glPushMatrix();
	glTranslated(0.0, h, 0.0);
	glRotated(-90, 1, 0, 0);

	gluCylinder(this->q, radioCopa , 0, 5, 25, 25);
	glColor3f(0.3, 1, 0.65);
	gluDisk(this->q, 0, radioCopa, 25, 25);
	glPopMatrix();

}

void Bosque::dibujaPino(){
	float h = 3.75;
	dibujaTronco(0.5, h, 25, 25);

	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.1, 1, 0.1);


	int radioCopa = 1.8;
	//Copa 1
	glPushMatrix();
	glTranslated(0.0, h, 0.0);
	glRotated(-90, 1, 0, 0);

	gluCylinder(this->q, radioCopa, 0, h, 25, 25);
	gluDisk(this->q, 0, radioCopa, 25, 25);

	glPopMatrix();
	//Copa 2
	glPushMatrix();

	glTranslated(0.0, 1.5*h, 0.0);
	glRotated(-90, 1, 0, 0);

	gluCylinder(this->q, radioCopa, 0, h, 25, 25);
	gluDisk(this->q, 0, radioCopa, 25, 25);


	glPopMatrix();

}
void Bosque::dibujaRoble(){
	float h = 5;
	dibujaTronco(0.5, h, 25, 25);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(0.0, h, 0.0);

	glColor3f(0.1, 1, 0.1);
	gluSphere(this->q, 1.5, 25, 25);

	glPopMatrix();

}
void Bosque::dibujaAlamo(){
	float h = 5;
	dibujaTronco(0.5, h, 25, 25);

	glMatrixMode(GL_MODELVIEW);

	float radio = 1.5;
	//copa 1
	glPushMatrix();
	glTranslated(0.3*radio, h, -0.3*radio);

	glColor3f(0.1, 1, 0.1);
	gluSphere(this->q, radio, 25, 25);

	glPopMatrix();

	//copa 2
	glPushMatrix();
	glTranslated(-0.3*radio, h, 0.3*radio);

	glColor3f(0.1, 1, 0.1);
	gluSphere(this->q, radio, 25, 25);

	glPopMatrix();
}

void Bosque::dibujaTronco(float rBase, float h, int meridianos, int paralelos){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);

	glColor3f(0.6, 0.4, 0.2);
	gluCylinder(this->q, rBase, 0.8*rBase, h, meridianos, paralelos);
	gluDisk(this->q, 0, rBase, 25, 25);
	
	glPopMatrix();
}