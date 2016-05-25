#ifndef Bosque_H_
#define Bosque_H_

#include "ObjetoCompuesto.h"
class Bosque :	public ObjetoCompuesto {
public:
	Bosque();
	~Bosque();
	void cambiarMaterial(GLfloat x);
private:
	int pos;
};

#endif //Bosque_H_