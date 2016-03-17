#ifndef Bosque_H_
#define Bosque_H_


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Bosque {
public:
	Bosque();
	~Bosque();
	void dibuja();
private:
	void dibujaAbeto();
	void dibujaPino();
	void dibujaRoble();
	void dibujaAlamo();

	void dibujaTronco(float rBase, float h, int meridianos, int paralelos);
	
	GLUquadricObj* q;
};

#endif //Bosque_H_