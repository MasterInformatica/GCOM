#include "Faro.h"
#include "Disco.h"
#include "Cilindro.h"

Faro::Faro(GLfloat rMax, GLfloat rMin, GLfloat ancho, int slices, int stacks){
	this->rMax = rMax;
	this->rMin = rMin;
	this->ancho = ancho;
	this->slices = slices;
	this->stacks = stacks;

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
	this->introduceObjeto(tapa2);

	this->setColor(0.0f, 1.0f, 0.0f);

	
	
}


Faro::~Faro(){
}
