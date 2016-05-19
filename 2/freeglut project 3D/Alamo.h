#ifndef Alamo_H_
#define Alamo_H_

#include "ObjetoCompuesto.h"
class Alamo : public ObjetoCompuesto {
public:
	Alamo(GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Alamo(){}

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	int stacks, slices;
};

#endif //Alamo_H_