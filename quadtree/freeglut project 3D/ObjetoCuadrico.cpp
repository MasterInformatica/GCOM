#include "ObjetoCuadrico.h"

ObjetoCuadrico::ObjetoCuadrico(){
	q = gluNewQuadric();
}


ObjetoCuadrico::~ObjetoCuadrico(){
	gluDeleteQuadric(this->q);
}


