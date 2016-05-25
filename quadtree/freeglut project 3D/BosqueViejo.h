#ifndef BosqueViejo_H_
#define BosqueViejo_H_


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

/* Dibuja 4 tipos de árboles distintos y los coloca en la escena.
 */
class BosqueViejo {
public:
	BosqueViejo();
	~BosqueViejo();
	void dibuja();
private:
	void dibujaAbeto();
	void dibujaPino();
	void dibujaRoble();
	void dibujaAlamo();

	void dibujaTronco(float rBase, float h, int meridianos, int paralelos);
	
	GLUquadricObj* q;
};

#endif //BosqueViejo_H_