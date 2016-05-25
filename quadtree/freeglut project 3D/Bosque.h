#ifndef Bosque_H_
#define Bosque_H_

#include "ObjetoCompuesto.h"
#include "QuadNode.h"
class Bosque :	public ObjetoCompuesto {
public:
	Bosque();
	~Bosque();

	//NUMERO DE ARBOLES Y DEMAS HISTORIAS
	static const int numX = 99;
	static const int numZ = 99;
	static const float separacion;

	virtual void dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz);
	void cambiaQuad();
private:
	int pos;
	bool conQuad;
	QuadNode* quad;

};

#endif //Bosque_H_