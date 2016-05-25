#include "Bosque.h"
#include "Abeto.h"
#include "Roble.h"
#include "Pino.h"
#include "Alamo.h"
#include "CopaArbol.h"
#include <time.h>

const float Bosque::separacion = 3.0f;

Bosque::Bosque(){
	Objeto3D* obj;
	GLfloat posx = 0 - (Bosque::numX / 2.0)*Bosque::separacion;
	
	srand(time(NULL));

	for (int i = 0; i < Bosque::numX; i++){
		for (int j = 0; j < Bosque::numZ; j++){
			//rand para ver si existe
			if (rand() < 10) continue;

			//rand para el tipo de elemnto
			int elem = rand() % 4;
			switch (elem){
			case 0:
				//abeto
				obj = new Abeto(posx + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 1:
				//roble
				obj = new Roble(posx + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 2:
				//pino
				obj = new Pino(posx + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			case 3:
				//alamo
				obj = new Alamo(posx + (i*Bosque::separacion), -j*Bosque::separacion);
				break;
			}
		}
	}

}

Bosque::~Bosque(){
}
