#ifndef Pino_H_
#define Pino_H_

#include "ObjetoCompuesto.h"
#include "Arbol.h"
class Pino : public Arbol {
public:
	Pino(GLfloat posX, GLfloat posZ, GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Pino(){}

	virtual GLfloat getRadio();
	virtual GLfloat getX();
	virtual GLfloat getZ();

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	GLfloat posx, posz;
	int stacks, slices;
};

#endif //Pino_H_