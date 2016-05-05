#ifndef Coche_H_
#define Coche_H_

#include "ObjetoCompuesto.h"
class Coche : public ObjetoCompuesto {
public:
	Coche(GLfloat size);
	~Coche();
	void mover(float x);
	void girar(float x);
private:
	GLfloat size;
	GLfloat radioRuedas, anchoRuedas;
	GLfloat radioFocos, anchoFocos;
	int posRuedas[4];
	GLfloat desplazamiento;
	GLfloat giro;
	GLfloat angRuedas;

	Objeto3D* buildRueda();
	Objeto3D* buildFaro();
	

};

#endif //Coche_H_