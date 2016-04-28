#ifndef Cilindro_H_
#define Cilindro_H_
#include "ObjetoCuadrico.h"
class Cilindro : public ObjetoCuadrico {
public:
	Cilindro(GLfloat baseR, GLfloat topR, GLfloat altura, GLint slices = 20, GLint stacks = 20);

	~Cilindro();

	virtual void dibuja();
private:
	GLfloat baseR;
	GLfloat topR;
	GLfloat altura;
	GLint slices;
	GLint stacks;
};

#endif //Cilindro_H_