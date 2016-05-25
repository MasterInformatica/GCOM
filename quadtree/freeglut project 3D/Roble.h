#ifndef Roble_H_
#define Roble_H_

#include "ObjetoCompuesto.h"
#include "Arbol.h"
class Roble : public Arbol {
public:
	Roble(GLfloat posX, GLfloat posZ, GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Roble(){}

	virtual GLfloat getRadio();
	virtual GLfloat getX();
	virtual GLfloat getZ();

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	GLfloat posx, posz;
	int stacks, slices;
};

#endif //Roble_H_