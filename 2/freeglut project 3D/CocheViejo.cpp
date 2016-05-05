#include "CocheViejo.h"


CocheViejo::CocheViejo() {
	this->altura = 3; // Altura del cubo. Toodas las medidas son relativas a esta.
	this->radio = this->altura / 3;
	
	q = gluNewQuadric();
	
	carroceria = new Cubo(this->altura);
	
	desplazamiento_x = 0;
}


CocheViejo::~CocheViejo() {
	delete carroceria;
	gluDeleteQuadric(q);
}


void CocheViejo::mover(float x) {
	desplazamiento_x += x;
}


void CocheViejo::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	//Mvto del coche entero
	glTranslated(this->desplazamiento_x, 0, 0);
		//carroceria
		this->dibujaCarroceria();
		//luces
		this->dibujaLuces();

		//ruedas
		this->dibujaRuedas();

	glPopMatrix();
}


void CocheViejo::dibujaCarroceria() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslated(0.0f, this->altura / 2 + this->radio, 0.0f); //situa encima del origen + ruedas
		glColor3f(1.0f, 0.0f, 1.0f);
		carroceria->dibuja();

	glPopMatrix();
}


void CocheViejo::dibujaLuces() {
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 1.0f, 0.0f);
	
	//mover delante y arriba (comuna a las dos luces)
	glPushMatrix();
	glTranslated(this->altura/2, 0.8*((this->altura)+(this->radio)), 0);

		//Luz izq
		glPushMatrix();
		glTranslated(0.0f, 0.0f, 0.2*this->altura);
		glRotated(90,0,1,0);
			gluCylinder(this->q, 0.3*this->radio, 0.4*this->radio, 0.2*this->altura, 25, 25);

		glPopMatrix();


		//Luz dcha
		glPushMatrix();
		glTranslated(0.0f, 0.0f, -0.2*this->altura);
		glRotated(90,0,1,0);
			gluCylinder(this->q, 0.3*this->radio, 0.4*this->radio, 0.2*this->altura, 25, 25);

		glPopMatrix();


	glPopMatrix();
}


void CocheViejo::dibujaRuedas() {
	
	//Por cada desplazamiento_x, se gira 15 grados la rueda
	float theta = desplazamiento_x * 15;
	
	float pos = altura / 2.0;
	glMatrixMode(GL_MODELVIEW);


	// rueda delantera derecha
	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(pos, radio, pos);
		gluCylinder(q, radio, radio, radio, 20, 20);
	
		glTranslated(0, 0, radio); //cubierta
		glRotated(-theta, 0.0, 0.0, 1.0);
			gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(-pos, radio, pos);
		gluCylinder(q, radio, radio, radio, 20, 20);
	
		glTranslated(0, 0, radio);
		glRotated(-theta, 0.0, 0.0, 1.0);
			gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(pos, radio, -pos-radio);
		gluCylinder(q, radio, radio, radio, 20, 20);
	
		glRotated(-theta, 0.0, 0.0, 1.0);
			gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();



	glPushMatrix();
	glColor3f(0, 0, 0);

	glTranslated(-pos, radio, -pos-radio);
		gluCylinder(q, radio, radio, radio, 20, 20);
	
		glRotated(-theta, 0.0, 0.0, 1.0);
			gluPartialDisk(q, 0, radio, 20, 20, 0.0, 340.0);

	glPopMatrix();

	glPopMatrix();
}