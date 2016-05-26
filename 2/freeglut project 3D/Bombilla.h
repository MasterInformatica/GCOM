#ifndef Bombilla_H_
#define Bombilla_H_
#include "Esfera.h"

class Bombilla : public Esfera {
public:
	Bombilla(GLenum idLuz,GLfloat radius, GLint slices = 20, GLint stacks = 20);
	~Bombilla();
	virtual void dibuja();
	void enciende();
	void apaga();
private:
	GLenum idLuz;
};

#endif //Bombilla_H_