#include "Disco.h"


Disco::Disco(GLfloat inR, GLfloat outR, GLint slices, GLint stacks){
	this->inR = inR;
	this->outR = outR;
	this->slices = slices;
	this->stacks = stacks;
}

GLfloat Disco::getRadio(){
	return this->outR;
}

Disco::~Disco()
{
}

void Disco::dibuja(){
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
		gluDisk(this->q, inR ,outR, slices, stacks);
	}
	glPopMatrix();
}