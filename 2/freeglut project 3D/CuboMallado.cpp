#include "CuboMallado.h"
 
CuboMallado::CuboMallado(float size) {
	float desp = size / 2;

	numeroVertices=8;
	vertice=new PuntoVector3D*[numeroVertices];
    numeroNormales=6;
	normal=new PuntoVector3D*[numeroNormales];
    numeroCaras=6;
    cara=new Cara*[6];

	// Vértices de abajo
	vertice[0]=new PuntoVector3D(desp, -desp, desp, 1);
	vertice[1]=new PuntoVector3D(desp, -desp, -desp, 1);
	vertice[2]=new PuntoVector3D(-desp, -desp, -desp, 1);
	vertice[3]=new PuntoVector3D(-desp, -desp, desp, 1);
	// Vértices de arriba
	vertice[4]=new PuntoVector3D(desp, desp, desp, 1);
	vertice[5]=new PuntoVector3D(desp, desp, -desp, 1);
	vertice[6]=new PuntoVector3D(-desp, desp, -desp, 1);
	vertice[7]=new PuntoVector3D(-desp, desp, desp, 1);

	// Normales caras frontal y trasera	 
	normal[0]=new PuntoVector3D(0.0f, 0.0f, 1.0f, 0);
	normal[1]=new PuntoVector3D(0.0f, 0.0f, -1.0f, 0);
	// Normales caras lateral izquierda y derecha
	normal[2]=new PuntoVector3D(1.0f, 0.0f, 0.0f, 0);
	normal[3]=new PuntoVector3D(-1.0f, 0.0f, 0.0f, 0);
	// Normales caras superior e inferior
	normal[4]=new PuntoVector3D(0.0f, 1.0f, 0.0f, 0);
	normal[5]=new PuntoVector3D(0.0f, -1.0f, 0.0f, 0);

	// Caras frontal y trasera
	VerticeNormal** aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(0, 0);
	aVN[1]=new VerticeNormal(4, 0);
	aVN[2]=new VerticeNormal(7, 0);
	aVN[3]=new VerticeNormal(3, 0);
	cara[0]=new Cara(4, aVN);

	aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(1, 1);
	aVN[1]=new VerticeNormal(2, 1);
	aVN[2]=new VerticeNormal(6, 1);
	aVN[3]=new VerticeNormal(5, 1);
	cara[1]=new Cara(4, aVN);

	// Caras lateral izquierda y derecha
	aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(0, 2);
	aVN[1]=new VerticeNormal(1, 2);
	aVN[2]=new VerticeNormal(5, 2);
	aVN[3]=new VerticeNormal(4, 2);
	cara[2]=new Cara(4, aVN);

	aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(2, 3);
	aVN[1]=new VerticeNormal(3, 3);
	aVN[2]=new VerticeNormal(7, 3);
	aVN[3]=new VerticeNormal(6, 3);
	cara[3]=new Cara(4, aVN);

	// Caras superior e inferior
	aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(4, 4);
	aVN[1]=new VerticeNormal(5, 4);
	aVN[2]=new VerticeNormal(6, 4);
	aVN[3]=new VerticeNormal(7, 4);
	cara[4]=new Cara(4, aVN);

	aVN=new VerticeNormal*[4];
	aVN[0]=new VerticeNormal(0, 5);
	aVN[1]=new VerticeNormal(3, 5);
	aVN[2]=new VerticeNormal(2, 5);
	aVN[3]=new VerticeNormal(1, 5);
	cara[5]=new Cara(4, aVN);	 
}

CuboMallado::~CuboMallado() {
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

void CuboMallado::dibuja() {
	for (int i=0; i<numeroCaras; i++) {		
		glBegin(GL_POLYGON);
		for (int j=0; j<cara[i]->getNumeroVertices(); j++) {
			int iN=cara[i]->getIndiceNormalK(j);
			int iV=cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());            				 
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}


 