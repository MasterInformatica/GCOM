#include "Cubo.h"

Cubo::Cubo(GLfloat size) {
	this->size = size;
}

Cubo::~Cubo() {
 
}

void Cubo::dibuja() {	 
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		glColor3fv(this->color);
		glMultMatrixf(this->mT->m);
		switch (this->modo){
		case ARMAZON:
		case PUNTOS:
			glutWireCube(this->size);
			break;
		case RELLENO:
		default:
			glutSolidCube(this->size);
			break;
		}
		
	}
	glPopMatrix();
}


 