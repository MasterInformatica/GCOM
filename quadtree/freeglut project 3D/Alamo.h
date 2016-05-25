#ifndef Alamo_H_
#define Alamo_H_

#include "ObjetoCompuesto.h"
#include "Arbol.h"
class Alamo : public Arbol {
public:
	Alamo(GLfloat posX, GLfloat posZ, GLfloat radioTronco = 0.5f, GLfloat alturaTronco = 4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices = 25);
	~Alamo(){}

	virtual GLfloat getRadio();
	virtual GLfloat getX();
	virtual GLfloat getZ();

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	GLfloat posx, posz;
	int stacks, slices;
};

#endif //Alamo_H_