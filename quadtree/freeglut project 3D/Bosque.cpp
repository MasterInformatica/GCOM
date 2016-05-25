#include "Bosque.h"
#include "Abeto.h"
#include "Roble.h"
#include "Pino.h"
#include "Alamo.h"
#include "CopaArbol.h"
#include <time.h>

const float Bosque::separacion = 4.0f;

Bosque::Bosque(){

	this->conQuad = false;

	Arbol* obj;
	GLfloat xInit = 0 - (Bosque::numX / 2.0)*Bosque::separacion;

	this->quad = new QuadNode(-5000,-5000,5000,5000);
	
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
		}
	}

}

void Bosque::cambiaQuad(){
	this->conQuad = !this->conQuad;
}

void Bosque::dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz){
	if (this->conQuad)
		this->quad->dibuja(NOx, NOz, SEx, SEz);
	else
		this->quad->dibuja();
}

Bosque::~Bosque(){
	delete this->quad;
}

