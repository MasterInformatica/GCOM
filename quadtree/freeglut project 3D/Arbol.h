#ifndef Arbol_H_
#define Arbol_H_

#include "ObjetoCompuesto.h"
class Arbol : public ObjetoCompuesto {
public:
	Arbol();
	virtual ~Arbol();

	virtual GLfloat getRadio() = 0;
	virtual GLfloat getX() = 0;
	virtual GLfloat getZ() = 0;
};

#endif //Arbol_H_