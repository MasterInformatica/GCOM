#ifndef Bosque_H_
#define Bosque_H_

#include "ObjetoCompuesto.h"
class Bosque :	public ObjetoCompuesto {
public:
	Bosque();
	~Bosque();

	//NUMERO DE ARBOLES Y DEMAS HISTORIAS
	static const int numX = 10;
	static const int numZ = 10;
	static const float separacion;

private:
	int pos;
};

#endif //Bosque_H_