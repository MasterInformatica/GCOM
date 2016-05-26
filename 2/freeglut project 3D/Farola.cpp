#include "Farola.h"
#include "Cilindro.h"
#include "Bombilla.h"

Farola::Farola(GLenum idLuz, GLfloat radio, GLfloat altura, int slices, int stacks) {
	this->idLuz = idLuz;
	this->radio = radio;
	this->altura = altura;
	this->slices = slices;
	this->stacks = stacks;

	//Palo de la farola
	Objeto3D* obj;
	obj = new Cilindro(radio*0.2, radio*0.1, altura, slices, stacks);
	//obj->traslada(0.0f, altura / 2.0, 0.0f);
	obj->rota(-90.0, 1.0f, 0.0f, 0.0f);
	obj->setColor(0.0f, 0.0f, 0.0f);
	this->introduceObjeto(obj);

	//Bola de arriba
	obj = new Bombilla(idLuz, radio, slices, stacks);
	obj->traslada(0.0f, altura + 0.8*radio, 0.0f);
	this->introduceObjeto(obj);
	
}

void Farola::enciende(){
	((Bombilla*)(this->elementos->at(1)))->enciende();
}

void Farola::apaga(){
	((Bombilla*)(this->elementos->at(1)))->apaga();
}


Farola::~Farola()
{
}
