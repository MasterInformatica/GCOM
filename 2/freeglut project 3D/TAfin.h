#ifndef TAfin_H_
#define TAfin_H_

#include "PuntoVector3D.h"


class TAfin {
private:
  void postMultiplica(GLfloat* m1);

public:
	TAfin();

	GLfloat m[16];
	void traslada(PuntoVector3D* v);
	void gira(GLfloat ang, PuntoVector3D* v);
	void escala(PuntoVector3D* v);
};

#endif //TAfin_H_
