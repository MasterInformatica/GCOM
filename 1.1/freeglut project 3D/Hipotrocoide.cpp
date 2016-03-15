#include "Hipotrocoide.h"
#include <math.h>
#include <iostream>
using namespace std;
#define PI 3.14159265359

Hipotrocoide::Hipotrocoide(int nP, int nQ, float a, float b , float c )  {
	this->nP = nP;
	this->nQ = nQ;
	this->a = a; this->b = b; this->c = c;
	generaPerfil();
	//genera malla
	generaMalla();
}

Hipotrocoide::~Hipotrocoide(){
	for (int i = 0; i < nP; i++)
		delete perfil[i];

	delete[] perfil;
}

void Hipotrocoide::generaPerfil(float radio){
	perfil = new PuntoVector3D*[nP];
	float incremento = 2*PI / nP;

	for (int i = 0; i < nP; i++)
		perfil[nP-i-1] = new PuntoVector3D(
							radio * cos(i*incremento),
							radio * sin(i*incremento),
							0, 
							1);
}

void Hipotrocoide::generaMalla(){
	this->numeroVertices = nP * (nQ+1);
	this->numeroCaras = nQ * nP;
	this->numeroNormales = this->numeroCaras;

	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//copia del perfil

	//Incremento de la rotacion en radianes
	double incremento = 8*PI / nQ;


	/* Calculo de los vértices de la malla*/
	double theta = 0;
	int indice = 0;

	for (int i = 0; i <= nQ; i++){
		theta += incremento;

		for (int j = 0; j < nP; j++){
			vertice[indice] = this->transformaPunto(perfil[j], theta);
			indice++;
		}
	}

	/* Construccion de caras */
	int indiceCara = 0;
	indice = 0;

	int cotaCaraPerfil = nP;
	for (int i = 0; i < nQ; i++){
		for (int j = 0; j < cotaCaraPerfil; j++){
			indice = nP * i + j;

			VerticeNormal** vn = new VerticeNormal*[4];

			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + nP), indiceCara);
			vn[2] = new VerticeNormal((j + 1) % nP + (i + 1)*nP, indiceCara);
			vn[3] = new VerticeNormal((j + 1) % nP + (i*nP), indiceCara);

			cara[indiceCara] = new Cara(4, vn);
			PuntoVector3D* v1 = vertice[vn[1]->getIV()]->clonar();
			v1->restar(vertice[vn[0]->getIV()]);

			PuntoVector3D* v2 = vertice[vn[3]->getIV()]->clonar();
			v2->restar(vertice[vn[0]->getIV()]);


			normal[indiceCara] = v1->productoVectorial(v2);
			delete v1; delete v2;

			indiceCara++;
		}
	}
}

void Hipotrocoide::cambiaModoRelleno(bool modo){
	this->modoRelleno = modo;
}

PuntoVector3D* Hipotrocoide::curva(float t){
	float dif = a - b;

	float cos1 = cos(t),
		sin1 = sin(t);
	float cos2 = cos(dif / b * t),
		sin2 = sin(dif / b * t);

	return new PuntoVector3D(
		dif*cos1 + c * cos2,
		0,
		dif*sin1 - c*sin2,
		1);
	//return new PuntoVector3D(3*cos1, 0, sin1,1);
}

PuntoVector3D* Hipotrocoide::primeraDerivada(float t){
	float dif = a - b;

	float cos1 = cos(t), 
		  sin1 = sin(t);
	float cos2 = cos(dif/b * t),
		  sin2 = sin(dif/b * t);

	return new PuntoVector3D (
		-1 * dif*sin1 - c * sin2*dif / b,
		 0,  
		 dif*cos1 - c*cos2*dif / b,
		 0 );
	//return new PuntoVector3D(-3*sin1, 0.0, cos1,0);
}

PuntoVector3D* Hipotrocoide::segundaDerivada(float t){
	float dif = a - b;

	float cos1 = cos(t),
		  sin1 = sin(t);
	float cos2 = cos(dif / b * t),
	      sin2 = sin(dif / b * t);

	return new PuntoVector3D(
		-1*dif*cos1 - c*cos2*dif*dif/(b*b),
		0,
		-1*dif*sin1 + c*sin2*dif*dif/(b*b),
		0);
	//return new PuntoVector3D(-3*cos1, 0, -1*sin1,0);
}


float* Hipotrocoide::marcoFrenet(float t){
	float* frenet = new float[16];
	
	PuntoVector3D* C0 = curva(t);
	PuntoVector3D* C1 = primeraDerivada(t);
	PuntoVector3D* C2 = segundaDerivada(t);

	//B(t) = ||C1(t) x C2(t)||
	PuntoVector3D* B = C1->productoVectorial(C2);
	B->normalizar();

	//T(t) = ||C1(t)||
	C1->normalizar();
	
	//N(t) = B(t) x T(t)
	PuntoVector3D* N = B->productoVectorial(C1);


	//frenet = (N(t), B(t), T(t), C(t))
	frenet[0] = N->getX(); frenet[1] = N->getY(); frenet[2] = N->getZ(); frenet[3] = 0;
	frenet[4] = B->getX(); frenet[5] = B->getY(); frenet[6] = B->getZ(); frenet[7] = 0;
	frenet[8] = C1->getX(); frenet[9] = C1->getY(); frenet[10] = C1->getZ(); frenet[11] = 0;
	frenet[12] = C0->getX(); frenet[13] = C0->getY(); frenet[14] = C0->getZ(); frenet[15] = 1;

	delete B;
	delete N;

	return frenet;
}


PuntoVector3D* Hipotrocoide::transformaPunto(PuntoVector3D* pto, float t){
	float* frenet = marcoFrenet(t);
	float trans[4] = { 0, 0, 0, 0 };
	float ptoF[4] = { pto->getX(), pto->getY(), pto->getZ(), 1 };
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			trans[j] += frenet[4 * i + j] * ptoF[i];
		}
	}

	delete [] frenet;
	return new PuntoVector3D(trans[0], trans[1], trans[2], trans[3]);
}

void Hipotrocoide::dibuja(){
	glColor3f(0.2f, 0.2f, 1.0f);

	for (int i = 0; i < numeroCaras; i++){
		if (this->modoRelleno)
			glBegin(GL_POLYGON);
		else
			glBegin(GL_LINES);
		for (int j = 0; j < cara[i]->getNumeroVertices(); j++){
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}