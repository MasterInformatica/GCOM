#ifndef CocheViejo_H_
#define CocheViejo_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

#include "Cubo.h"

#define PI 3.14159265359

/* Dibuja un coche en el origen compuesto por una carroceria (cubo), ruedas (cilindro + tapa), luces (cilindros).
 */
class CocheViejo {
public:
	CocheViejo();
	~CocheViejo();
	void dibuja();
	void mover(float x);

private:
	void dibujaLuces();
	void dibujaRuedas();
	void dibujaCarroceria();


	float altura;
	float radio;


	Cubo* carroceria;
	GLUquadricObj* q;
	float desplazamiento_x;
};

#endif //CocheViejo_H_