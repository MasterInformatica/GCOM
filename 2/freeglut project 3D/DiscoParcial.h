#ifndef DiscoParcial_H_
#define DiscoParcial_H_

#include "ObjetoCuadrico.h"
class DiscoParcial : public ObjetoCuadrico {
public:
	DiscoParcial(GLfloat inR, GLfloat outR, GLfloat startAng, GLfloat endAng, GLint slices = 20, GLint stacks = 20);
	~DiscoParcial();

	void dibuja();
private:
	GLfloat inR;
	GLfloat outR;
	GLfloat startAng;
	GLfloat endAng;

	GLint slices;
	GLint stacks;

};

#endif //DiscoParcial_H_