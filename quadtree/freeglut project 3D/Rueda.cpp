#include "Rueda.h"
#include "DiscoParcial.h"
#include "Cilindro.h"


Rueda::Rueda(GLfloat radio, GLfloat ancho, int slices, int stacks) {
	this->radio = radio;
	this->ancho = ancho;
	this->slices = slices;
	this->stacks = stacks;

	//Contruir rueda
	DiscoParcial *tapa1, *tapa2;
	Cilindro *goma;
	tapa1 = new DiscoParcial(0, radio, 0.0f, 300.0f);
	tapa2 = new DiscoParcial(0, radio, 0.0f, 300.0f); //plano XY
	goma = new Cilindro(radio, radio, ancho);

	tapa1->traslada(0.0f, 0.0f, ancho);


	//Centrar en el (0,0,0)
	tapa1->traslada(0.0f, 0.0f, -ancho / 2.0);
	tapa2->traslada(0.0f, 0.0f, -ancho / 2.0);
	goma->traslada(0.0f, 0.0f, -ancho / 2.0);


	this->introduceObjeto(goma);
	this->introduceObjeto(tapa1);
	this->introduceObjeto(tapa2);


	this->setColor(0.0f, 0.0f, 0.0f);
	tapa1->setColor(0.0f, 1.0f, 0.0f);
	tapa2->setColor(1.0f, 0.0f, 0.0f);
}


Rueda::~Rueda(){
}
