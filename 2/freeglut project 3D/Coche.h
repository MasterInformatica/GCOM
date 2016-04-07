#ifndef Coche_H_
#define Coche_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>

#include "Cubo.h"

#define PI 3.14159265359

/* Dibuja un coche en el origen compuesto por una carroceria (cubo), ruedas (cilindro + tapa), luces (cilindros).
 */
class Coche {
public:
	Coche();
	~Coche();
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

#endif //Coche_H_