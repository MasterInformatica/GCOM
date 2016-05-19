#include "Bosque.h"
#include "Abeto.h"
#include "Roble.h"
#include "Pino.h"
#include "Alamo.h"

Bosque::Bosque(){
	Objeto3D* obj;
	
	obj = new Abeto();
	obj->traslada(6.0, 0.0, 6.0);
	this->introduceObjeto(obj);

	obj = new Pino();
	obj->traslada(6.0, 0.0, -6.0);
	this->introduceObjeto(obj);

	obj = new Roble();
	obj->traslada(-6.0, 0.0, 6.0);
	this->introduceObjeto(obj);

	obj = new Alamo();
	obj->traslada(-6.0, 0.0, -6.0);
	this->introduceObjeto(obj);
}


Bosque::~Bosque(){
}
