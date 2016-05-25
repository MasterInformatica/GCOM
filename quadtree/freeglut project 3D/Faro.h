#ifndef Faro_H_
#define Faro_H_
#include "ObjetoCompuesto.h"

/**
 * Dibuja el faro con el origen en el centro, y mirando hacia el eje +X
 */
class Faro : public ObjetoCompuesto {
public:
	Faro(GLenum idLuz, GLfloat rMax, GLfloat rMin, GLfloat ancho, int slices = 25, int stacks = 25);
	~Faro();
	void enciende();
	void apaga();

	virtual void dibuja();
private:
	GLfloat rMax, rMin, ancho;
	int slices, stacks;
	GLenum idLuz;
};

#endif //Faro_H_