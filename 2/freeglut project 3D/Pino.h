#ifndef Pino_H_
#define Pino_H_

#include "ObjetoCompuesto.h"
class Pino : public ObjetoCompuesto {
public:
	Pino(GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Pino(){}

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	int stacks, slices;
};

#endif //Pino_H_