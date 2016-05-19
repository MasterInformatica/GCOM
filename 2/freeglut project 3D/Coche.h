#ifndef Coche_H_
#define Coche_H_

#include "ObjetoCompuesto.h"
class Coche : public ObjetoCompuesto {
public:
	Coche(GLfloat size,GLenum idLuz1,GLenum idLuz2);
	~Coche();
	void mover(float x);
	void girar(float x);

	void enciedeFoco();
	void apagaFoco();
private:
	GLfloat size;
	GLfloat radioRuedas, anchoRuedas;
	GLfloat radioFocos, anchoFocos;
	int posRuedas[4];
	int posFaros[2];

	GLfloat desplazamiento;
	GLfloat giro;
	GLfloat angRuedas;

};

#endif //Coche_H_