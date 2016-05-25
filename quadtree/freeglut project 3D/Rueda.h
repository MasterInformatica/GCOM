#ifndef Rueda_H_
#define Rueda_H_

#include "ObjetoCompuesto.h"

class Rueda : public ObjetoCompuesto {
public:
	Rueda(GLfloat radio, GLfloat ancho, int slices = 20, int stacks = 20);
	~Rueda();
private:
	GLfloat radio, ancho;
	int slices, stacks;
};

#endif //Rueda_H_