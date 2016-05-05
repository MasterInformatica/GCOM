 
#include "Malla.h"
 
Malla::Malla(int nV, int nN, int nC, PuntoVector3D** v, PuntoVector3D** n, Cara** c) {
	numeroVertices=nV;
    vertice=v;
    numeroNormales=nN;
    normal=n;
    numeroCaras=nC;
    cara=c;    
}

Malla::Malla() {}

Malla::~Malla() {
    for (int i=0; i<numeroVertices; i++)
        delete vertice[i];
    delete[] vertice;

    for (int i=0; i<numeroNormales; i++)
        delete normal[i];
    delete[] normal;

    for (int i=0; i<numeroCaras; i++)
        delete cara[i];
    delete[] cara;
}

int Malla::getNumeroVertices() {
    return numeroVertices;
}

int Malla::getNumeroNormales() {
    return numeroNormales;
}

int Malla::getNumeroCaras() {
    return numeroCaras;
}

void Malla::dibuja() {	 	 
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	{
		glColor3fv(this->color);
		glMultMatrixf(dameMatrizAfin());

		for (int i = 0; i < numeroCaras; i++) {
			switch (this->modo){
			case ARMAZON:
			case PUNTOS:
				glBegin(GL_LINE_LOOP);
				break;
			case RELLENO:
			default:
				glBegin(GL_POLYGON);
				break;
			}

			for (int j = 0; j < cara[i]->getNumeroVertices(); j++) {
				int iN = cara[i]->getIndiceNormalK(j);
				int iV = cara[i]->getIndiceVerticeK(j);
				glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
				glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
			}
			glEnd();
		}
	}
	glPopMatrix();
}

 

