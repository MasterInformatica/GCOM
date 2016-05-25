#ifndef Roble_H_
#define Roble_H_

#include "ObjetoCompuesto.h"
class Roble : public ObjetoCompuesto {
public:
	Roble(GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Roble(){}

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	int stacks, slices;
};

#endif //Roble_H_