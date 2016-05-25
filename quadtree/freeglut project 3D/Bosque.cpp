#include "Bosque.h"
#include "Abeto.h"
#include "Roble.h"
#include "Pino.h"
#include "Alamo.h"
#include "CopaArbol.h"

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
	this->pos = this->elementos->size();
	this->introduceObjeto(obj);

	obj = new Alamo();
	obj->traslada(-6.0, 0.0, -6.0);
	this->introduceObjeto(obj);
}

void Bosque::cambiarMaterial(GLfloat x){
	// no existe el tipo arbol, por lo que asumimos que en 0 esta el tronco y en 1 la copa
	ObjetoCompuesto*  obj = (ObjetoCompuesto *) this->elementos->at(this->pos);
	CopaArbol* ca = (CopaArbol *)obj->getElemeto(1);
	ca->cambiarMaterial(x);
}

Bosque::~Bosque(){
}
