#ifndef Farola_H_
#define Farola_H_

#include "ObjetoCompuesto.h"
class Farola : public ObjetoCompuesto {
public:
	Farola(GLenum idLuz, GLfloat radio = 1.0f, GLfloat altura = 8.0f, int slices = 20, int stacks = 20);
	~Farola();
	
	void enciende();
	void apaga();
private:

	GLfloat radio, altura;
	int slices, stacks;
	GLenum idLuz;
};

#endif //Farola_H_