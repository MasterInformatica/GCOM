#ifndef Abeto_H_
#define Abeto_H_

#include "ObjetoCompuesto.h"

class Abeto : public ObjetoCompuesto {
public:
	Abeto(GLfloat radioTronco = 0.5f, GLfloat alturaTronco=4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices=25);
	~Abeto(){}

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	int stacks, slices;
};

#endif //Abeto_H_