#include "Tronco.h"


Tronco::Tronco(GLfloat baseR, GLfloat topR, GLfloat altura, GLint slices, GLint stacks) :
Cilindro(baseR, topR, altura, slices, stacks){

	this->rota(-90, 1.0f, 0.0f, 0.0f);
	this->traslada(0.0f, -altura / 2.0f, 0.0f);

	this->setColor(0.5f, 0.5f, 0.0f);
}

Tronco::~Tronco(){}
