#ifndef Abeto_H_
#define Abeto_H_

#include "ObjetoCompuesto.h"
#include "Arbol.h"

class Abeto : public Arbol {
public:
	Abeto(GLfloat posX, GLfloat posZ, GLfloat radioTronco = 0.5f, GLfloat alturaTronco=4.0f, GLfloat radioCopa = 1.5f, int stacks = 25, int slices=25);
	~Abeto(){}

	virtual GLfloat getRadio();
	virtual GLfloat getX();
	virtual GLfloat getZ();

private:
	GLfloat radioTronco, alturaTronco;
	GLfloat radioCopa;
	GLfloat posx, posz;

	int stacks, slices;
};

#endif //Abeto_H_