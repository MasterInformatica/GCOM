#ifndef Esfera_H_
#define Esfera_H_
#include "ObjetoCuadrico.h"
class Esfera : public ObjetoCuadrico {
public:
	Esfera(GLfloat radius, GLint slices = 20, GLint stacks = 20);
	~Esfera();

	void dibuja();
	virtual GLfloat getRadio();
private:
	GLfloat radius;
	GLint slices;
	GLint stacks;
};

#endif //Esfera_H_