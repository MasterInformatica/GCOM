#include "Bombilla.h"


Bombilla::Bombilla(GLenum idLuz, GLfloat radius, GLint slices, GLint stacks) : Esfera(radius, slices, stacks) {
	this->idLuz = idLuz;

	this->setColor(1.0f, 1.0f, 1.0f);

	//LUCES
	glEnable(this->idLuz);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		glLoadIdentity();
		//Definir componentes del foco
		GLfloat color[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		glLightfv(this->idLuz, GL_AMBIENT, color);
		glLightfv(this->idLuz, GL_DIFFUSE, color);
		glLightfv(this->idLuz, GL_SPECULAR, color);
	}
	glPopMatrix();
		//Definir posicion del foco
		GLfloat pos[] = { 0.0f, 0.0f, 0.0f, 1.0 };
		glLightfv(this->idLuz, GL_POSITION, pos);
	
}

void Bombilla::enciende(){
	glEnable(this->idLuz);
}

void Bombilla::apaga(){
	glDisable(this->idLuz);
}


Bombilla::~Bombilla()
{
}


