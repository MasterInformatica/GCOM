#ifndef Disco_H_
#define Disco_H_

#include "ObjetoCuadrico.h"
class Disco : public ObjetoCuadrico {
public:
	Disco(GLfloat inR, GLfloat outR, GLint slices = 20, GLint stacks = 20);
	~Disco();

	void dibuja();
	virtual GLfloat getRadio();
private:
	GLfloat inR;
	GLfloat outR;
	GLint slices;
	GLint stacks;
};

#endif //Disco_H_