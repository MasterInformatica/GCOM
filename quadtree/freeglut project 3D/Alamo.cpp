#include "Alamo.h"
#include "Tronco.h"
#include "CopaArbol.h"

Alamo::Alamo(GLfloat posX, GLfloat posZ, GLfloat radioTronco, GLfloat alturaTronco, GLfloat radioCopa, int stacks, int slices){
	this->posx = posX;
	this->posz = posZ;

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

	this->traslada(posX, 0.0f, posZ);
}

GLfloat Alamo::getRadio(){
	//Aunque no ea exacto, vamos a suponer que las esferas de la copa solo intersecan en un punto (i.e, están pegadas, no superpuestas)
	return 2 * radioCopa;
}

GLfloat Alamo::getX(){
	return this->posx;
}
GLfloat Alamo::getZ(){
	return this->posz;
}

