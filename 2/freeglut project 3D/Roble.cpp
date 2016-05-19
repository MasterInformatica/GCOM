#include "Roble.h"
#include "Tronco.h"
#include "CopaArbol.h"

Roble::Roble(GLfloat radioTronco, GLfloat alturaTronco, GLfloat radioCopa, int stacks, int slices){
	this->radioCopa = radioCopa;
	this->radioTronco = radioTronco;
	this->alturaTronco = alturaTronco;
	
	this->stacks = stacks;
	this->slices = slices;
	//--------------------------------------------------------------------------------------------
	Objeto3D* obj;
	obj = new Tronco(radioTronco, radioTronco*0.8, alturaTronco, slices, stacks);
	obj->traslada(0.0f, alturaTronco / 2.0, 0.0f);
	this->introduceObjeto(obj);

	obj = new CopaArbol(TipoCopa::UnaEsfera, radioCopa, stacks, slices);
	obj->traslada(0.0f, alturaTronco, 0.0f);
	this->introduceObjeto(obj);
}

