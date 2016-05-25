#include "Cilindro.h"

Cilindro::Cilindro(GLfloat baseR, GLfloat topR, GLfloat altura, GLint slices, GLint stacks){
	this->baseR = baseR;
	this->topR = topR;
	this->altura = altura;
	this->slices = slices;
	this->stacks = stacks;
}


Cilindro::~Cilindro()
{
}

GLfloat Cilindro::getRadio(){
	return (this->baseR > this->topR) ? this->baseR : this->topR;
}


void Cilindro::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		glColor3fv(this->color);
		glMultMatrixf(dameMatrizAfin());
		switch (this->modo){
		case ARMAZON:
			gluQuadricDrawStyle(this->q, GLU_LINE);
			break;
		case PUNTOS:
			gluQuadricDrawStyle(this->q, GLU_POINT);
			break;
		case RELLENO:
		default:
			gluQuadricDrawStyle(this->q, GLU_FILL);
			break;
		}
		gluCylinder(this->q, baseR, topR, altura, slices, stacks);
	}
	glPopMatrix();
}