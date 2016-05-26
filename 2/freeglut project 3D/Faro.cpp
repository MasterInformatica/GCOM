#include "Faro.h"
#include "Disco.h"
#include "Cilindro.h"

Faro::Faro(GLenum idLuz, GLfloat rMax, GLfloat rMin, GLfloat ancho, int slices, int stacks){
	this->rMax = rMax;
	this->rMin = rMin;
	this->ancho = ancho;
	this->slices = slices;
	this->stacks = stacks;
	this->idLuz = idLuz;

	//Creacion del faro
	Disco *tapa1, *tapa2;
	Cilindro *casquillo;
	tapa1 = new Disco(0, rMin);
	tapa2 = new Disco(0, rMax);
	casquillo = new Cilindro(rMin, rMax, ancho);

	tapa2->traslada(0.0f, 0.0f, ancho);
	
	//Centrar en el (0,0,0)
	tapa1->traslada(0.0f, 0.0f, -ancho / 2.0);
	tapa2->traslada(0.0f, 0.0f, -ancho / 2.0);
	casquillo->traslada(0.0f, 0.0f, -ancho / 2.0);

	this->introduceObjeto(casquillo);
	this->introduceObjeto(tapa1);
	this->setColor(0.0f, 1.0f, 0.0f);

	this->introduceObjeto(tapa2);
	tapa2->setColor(1.0f, 1.0f, 1.0f);


	//LUCES
	glDisable(this->idLuz);

	//Definir foco
	glLightf(this->idLuz, GL_SPOT_CUTOFF, atan2(this->rMax, this->ancho)*360/6.28);
	glLightf(this->idLuz, GL_SPOT_EXPONENT, 4.0);
	//Definir componentes del foco
	GLfloat color[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glLightfv(this->idLuz, GL_AMBIENT, color);
	glLightfv(this->idLuz, GL_DIFFUSE, color);
	glLightfv(this->idLuz, GL_SPECULAR, color);
}

void Faro::enciende(){
	glEnable(this->idLuz);
}

void Faro::apaga(){
	glDisable(this->idLuz);
}

void Faro::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		//Elementos del faro
		glMultMatrixf(dameMatrizAfin());
	
		//Bombillas del faro
		GLfloat pos[] = { 0.0f, 0.0f, this->ancho / -2.0f };
		glLightfv(this->idLuz, GL_POSITION, pos);

		GLfloat dir[] = { 0.0f, 0.0f, 1.0f };
		glLightfv(this->idLuz, GL_SPOT_DIRECTION, dir);
		
		for (std::vector<Objeto3D*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
			(*it)->dibuja();
		}

	
	}
	glPopMatrix();
}


Faro::~Faro(){
}
