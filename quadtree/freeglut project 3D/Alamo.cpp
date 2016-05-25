#include "Alamo.h"
#include "Tronco.h"
#include "CopaArbol.h"

Alamo::Alamo(GLfloat radioTronco, GLfloat alturaTronco, GLfloat radioCopa, int stacks, int slices){
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

	obj = new CopaArbol(TipoCopa::DosEsferas, radioCopa, stacks, slices);
	obj->traslada(0.0f, alturaTronco, 0.0f);
	this->introduceObjeto(obj);
}

