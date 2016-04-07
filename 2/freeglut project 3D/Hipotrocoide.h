#ifndef Hipotrocoide_H_
#define Hipotrocoide_H_

#include "Malla.h"

class Hipotrocoide : public Malla
{
public:
	Hipotrocoide(int nP, int nQ, float a = 7.0, float b = 4.0, float c = 2.0);
	~Hipotrocoide();

	void cambiaModoRelleno(bool modo);
	void dibuja();

private:
	Hipotrocoide(){};

	float a, b, c;
	int nP, nQ;

	bool modoRelleno;

	PuntoVector3D** perfil;

	void generaPerfil(float radio = 0.5);
	void generaMalla();


	PuntoVector3D* curva(float t);
	PuntoVector3D* primeraDerivada(float t);
	PuntoVector3D* segundaDerivada(float t);
	float* marcoFrenet(float t);
	PuntoVector3D* transformaPunto(PuntoVector3D* pto, float t);


};

#endif //Hipotrocoide_H_