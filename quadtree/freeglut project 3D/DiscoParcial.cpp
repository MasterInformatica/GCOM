#include "DiscoParcial.h"


DiscoParcial::DiscoParcial(GLfloat inR, GLfloat outR, GLfloat startAng, GLfloat endAng, GLint slices, GLint stacks){
	this->inR = inR;
	this->outR = outR;
	this->slices = slices;
	this->stacks = stacks;
	this->startAng = startAng;
	this->endAng = endAng;
}


DiscoParcial::~DiscoParcial()
{
}

void DiscoParcial::dibuja(){
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
		gluPartialDisk(this->q, inR ,outR, slices, stacks,startAng,endAng);
	}
	glPopMatrix();
}