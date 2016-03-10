#ifndef Iman_H_
#define Iman_H_

#include "Revolucion.h"

class Iman : public Revolucion{
public:
	Iman(int nQ, float rInt, float rExt, float h);
	virtual ~Iman();

	void dibuja();

private:
	Malla* generaPolo(PuntoVector3D* p1, PuntoVector3D* p2, PuntoVector3D* p3, PuntoVector3D* p4, float len);

	Malla* poloNorte;
	Malla* poloSur;
};


#endif //Iman_H_