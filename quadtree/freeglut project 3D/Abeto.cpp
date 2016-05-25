#include "Abeto.h"
#include "Tronco.h"
#include "CopaArbol.h"

Abeto::Abeto(GLfloat posX, GLfloat posZ, GLfloat radioTronco, GLfloat alturaTronco, GLfloat radioCopa, int stacks, int slices){
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

	obj = new CopaArbol(TipoCopa::UnCono, radioCopa, stacks, slices);
	obj->traslada(0.0f, alturaTronco, 0.0f);
	this->introduceObjeto(obj);


	this->traslada(posX, 0.0f, posZ);
}


GLfloat Abeto::getRadio(){
	return (radioCopa > radioTronco) ? radioCopa : radioTronco;
}

GLfloat Abeto::getX(){
	return this->posx;
}
GLfloat Abeto::getZ(){
	return this->posz;
}
