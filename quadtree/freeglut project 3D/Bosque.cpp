#include "Bosque.h"
#include "Abeto.h"
#include "Roble.h"
#include "Pino.h"
#include "Alamo.h"
#include "CopaArbol.h"
#include <time.h>
#include <iostream>



Bosque::Bosque(){

	this->conQuad = false;

	Arbol* obj;
	GLfloat xInit = 0 - (Bosque::numX / 2)*Bosque::separacion;
	GLfloat x = (Bosque::numX / 2)*Bosque::separacion + 5;
	GLfloat z = (Bosque::numZ)*Bosque::separacion + 5;
	this->quad = new QuadNode(-1.0*x,-1.0*z,x,4);
	
	srand(time(NULL));

	for (int i = 0; i < Bosque::numX; i++){
		for (int j = 0; j < Bosque::numZ; j++){
			//rand para ver si existe
			if (rand() %100 < 10) continue;
			
			//rand para el tipo de elemnto
			int elem = rand() % 4;
			switch (elem){
			case 0:
				//abeto
				obj = new Abeto(xInit + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 1:
				//roble
				obj = new Roble(xInit + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 2:
				//pino
				obj = new Pino(xInit + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 3:
				//alamo
				obj = new Alamo(xInit + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			}
			this->quad->addElement(obj);
			this->introduceObjeto(obj);
		}
	}

}

void Bosque::cambiaQuad(){
	this->conQuad = !this->conQuad;

	std::cout << "El quad esta " << ((this->conQuad) ? "activado" : "desactivado") << std::endl;
}

void Bosque::dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz){
	if (this->conQuad)
	//	this->quad->dibuja();
		this->quad->dibuja(NOx, NOz, SEx, SEz);
	else
		ObjetoCompuesto::dibuja();
}

Bosque::~Bosque(){
	delete this->quad;
}

