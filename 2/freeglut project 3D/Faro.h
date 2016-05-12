#ifndef Faro_H_
#define Faro_H_
#include "ObjetoCompuesto.h"

class Faro : public ObjetoCompuesto {
public:
	Faro(GLfloat rMax, GLfloat rMin, GLfloat ancho, int slices=25, int stacks=25);
	~Faro();
private:
	GLfloat rMax, rMin, ancho;
	int slices, stacks;
};

#endif //Faro_H_