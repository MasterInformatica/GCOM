#ifndef Revolucion_H_
#define Revolucion_H_

#include "Malla.h"
#include "PuntoVector3D.h"

#define PI 3.14159265359

class Revolucion : public Malla {
public:
	Revolucion() {};
	Revolucion(PuntoVector3D** perfil, int nPuntos);
	virtual ~Revolucion();

	void revoluciona(float grados, int divisiones, bool cerrado);

protected:
	PuntoVector3D** perfil;
	int nPuntosPerfil;
};


#endif //Revolucion_H_