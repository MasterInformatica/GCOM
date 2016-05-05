#include "Esfera.h"


Esfera::Esfera(GLfloat radius, GLint slices, GLint stacks){
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
}


Esfera::~Esfera()
{
}

void Esfera::dibuja(){
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
		gluSphere(this->q, radius, slices, stacks);
	}
	glPopMatrix();
}