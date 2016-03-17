#include "Coche.h"

#define PI 3.14159265359

Coche::Coche()
{
	this->altura = 5;
	this->radio = this->altura / 3;
	q = gluNewQuadric();
	carroceria = new Cubo(this->altura);
	desplazamiento_x = PI;
}


Coche::~Coche()
{
	delete carroceria;
	gluDeleteQuadric(q);
}


void Coche::mover(float x){
	desplazamiento_x += x;
}

void Coche::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Mvto del coche entero
	glTranslated(desplazamiento_x, 0, 0);

	//carroceria
	this->dibujaCarroceria();
	//luces
	this->dibujaLuces();

	//ruedas
	this->dibujaRuedas();

	glPopMatrix();

}

void Coche::dibujaCarroceria(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslated(0.0f, this->altura / 2 + this->radio, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	carroceria->dibuja();

	glPopMatrix();
}


void Coche::dibujaLuces(){

}


void Coche::dibujaRuedas(){
	float theta = desplazamiento_x / (360.0*radio);
	float pos = altura / 2.0;
	glMatrixMode(GL_MODELVIEW);


	// rueda "alante" derecha
	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(pos, radio, pos);
	gluCylinder(q, radio, radio, radio, 20, 20);
	glTranslated(0, 0, radio);
	glRotated(-theta, 0.0, 0.0, 1.0);
	gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(-pos, radio, pos);
	gluCylinder(q, radio, radio, radio, 20, 20);
	glTranslated(0, 0, radio);
	gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(pos, radio, -pos-radio);
	gluCylinder(q, radio, radio, radio, 20, 20);
	gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(-pos, radio, -pos-radio);
	gluCylinder(q, radio, radio, radio, 20, 20);
	gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();

	glPopMatrix();
}