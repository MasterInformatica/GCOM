#ifndef Tronco_H_
#define Tronco_H_
#include "Cilindro.h"


class Tronco : public Cilindro {
public:
	Tronco(GLfloat baseR, GLfloat topR, GLfloat altura, GLint slices = 20, GLint stacks = 20);
	~Tronco();
};

#endif //Tronco_H_