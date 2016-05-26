#include "Bombilla.h"


Bombilla::Bombilla(GLenum idLuz, GLfloat radius, GLint slices, GLint stacks) : Esfera(radius, slices, stacks) {
	this->idLuz = idLuz;

	this->setColor(1.0f, 1.0f, 1.0f);

	//LUCES
	glDisable(this->idLuz);
	glMatrixMode(GL_MODELVIEW);
	{
		//glLoadIdentity();
		//Definir componentes del foco
		GLfloat color[] = { 1.0f, 0.0f, 0.8f, 1.0f };
		glLightfv(this->idLuz, GL_AMBIENT, color);
		glLightfv(this->idLuz, GL_DIFFUSE, color);
		GLfloat spec[] = { 0.8f, 0.0f, 0.8f, 1.0f };
		glLightfv(this->idLuz, GL_SPECULAR, spec);
		
	}
		
	
}

void Bombilla::enciende(){
	glEnable(this->idLuz);
}

void Bombilla::apaga(){
	glDisable(this->idLuz);
}

void Bombilla::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		glMultMatrixf(dameMatrizAfin());
		GLfloat pos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		glLightfv(this->idLuz, GL_POSITION, pos);
	}
	glPopMatrix();
	Esfera::dibuja();
		
}


Bombilla::~Bombilla()
{
}


