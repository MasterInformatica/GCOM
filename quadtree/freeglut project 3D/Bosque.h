#ifndef Bosque_H_
#define Bosque_H_

#include "ObjetoCompuesto.h"
#include "QuadNode.h"
class Bosque :	public ObjetoCompuesto {
public:
	Bosque();
	~Bosque();

	//NUMERO DE ARBOLES Y DEMAS HISTORIAS
	 const int numX = 100;
	 const int numZ = 100;
	 const float separacion = 4.0f;

	virtual void dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz);
	void cambiaQuad();
private:
	int pos;
	bool conQuad;
	QuadNode* quad;

};

#endif //Bosque_H_