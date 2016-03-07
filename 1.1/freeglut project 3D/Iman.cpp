#include "Iman.h"


Iman::Iman(int nQ, float rInt, float rExt){
	this->nPuntosPerfil = 4;
	this->perfil = new PuntoVector3D*[nPuntosPerfil];

	float h = rExt - rInt;
	perfil[0] = new PuntoVector3D(rInt, 0, 0, 1);
	perfil[1] = new PuntoVector3D(rExt, 0, 0, 1);
	perfil[2] = new PuntoVector3D(rExt, h, 0, 1);
	perfil[3] = new PuntoVector3D(rInt, h, 0, 1);

	revoluciona(180, nQ, true); //Genera la curva

	//generamos los polos
	int i = numeroVertices-1;
	this->poloNorte = generaPolo(vertice[0], vertice[1], vertice[2], vertice[3], 2.5);
	this->poloSur = generaPolo(vertice[i-2], vertice[i-3], vertice[i], vertice[i-1], 2.5); //comprobar este orden
}


void Iman::dibuja(){
	//Polo norte en gris
	glColor3f(0.6f, 0.6f, 0.6f);
	this->poloNorte->dibuja();


	/* Dibujar la curva a colores*/
	glColor3f(0.0f,0.0f,1.0f);

	for (int i = 0; i<numeroCaras; i++) {
		if (i==numeroCaras/2)
			glColor3f(1.0f, 0.0f, 0.0f);

		glBegin(GL_POLYGON);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}

	//Polo sur en gris
	glColor3f(0.6f, 0.6f, 0.6f);
	this->poloSur->dibuja();
}


Malla* Iman::generaPolo(PuntoVector3D* p1, PuntoVector3D* p2, PuntoVector3D* p3, PuntoVector3D* p4, float len){
	PuntoVector3D** vert = new PuntoVector3D*[8]; 
	PuntoVector3D** norm = new PuntoVector3D*[5];
	Cara** cara = new Cara*[5];
	vert[0] = p1->clonar();
	vert[1] = p2->clonar();
	vert[2] = p3->clonar();
	vert[3] = p4->clonar();

	PuntoVector3D* offset = new PuntoVector3D(0.0, 0.0, len, 0);
	for (int i = 0; i < 4; i++){
		vert[i + 4] = vert[i]->clonar();
		vert[i + 4]->sumar(offset);
	}
	delete offset;

	norm[0] = new PuntoVector3D( 0.0f, -1.0f,  0.0f,  0); //inferior
	norm[1] = new PuntoVector3D( 1.0f,  0.0f,  0.0f,  0); //dcha
	norm[2] = new PuntoVector3D( 0.0f,  1.0f,  0.0f,  0); //superior
	norm[3] = new PuntoVector3D(-1.0f,  0.0f,  0.0f,  0); //izq
	norm[4] = new PuntoVector3D( 0.0f,  0.0f,  1.0f,  0); //frente


	VerticeNormal** vn;
	//cara inferior.
	vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(0, 0);
	vn[1] = new VerticeNormal(1, 0);
	vn[2] = new VerticeNormal(5, 0);
	vn[3] = new VerticeNormal(4, 0);
	cara[0] = new Cara(4, vn);

	//cara dcha
	vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(1, 1);
	vn[1] = new VerticeNormal(2, 1);
	vn[2] = new VerticeNormal(6, 1);
	vn[3] = new VerticeNormal(5, 1);
	cara[1] = new Cara(4, vn);

	//cara sup
	vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(2, 2);
	vn[1] = new VerticeNormal(3, 2);
	vn[2] = new VerticeNormal(7, 2);
	vn[3] = new VerticeNormal(6, 2);
	cara[2] = new Cara(4, vn);

	//cara izq
	vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(3, 3);
	vn[1] = new VerticeNormal(0, 3);
	vn[2] = new VerticeNormal(4, 3);
	vn[3] = new VerticeNormal(7, 3);
	cara[3] = new Cara(4, vn);
	
	//cara frontal
	vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(6, 4);
	vn[1] = new VerticeNormal(7, 4);
	vn[2] = new VerticeNormal(4, 4);
	vn[3] = new VerticeNormal(5, 4);
	cara[4] = new Cara(4, vn);	
	

	return new Malla(8, 5, 5, vert, norm, cara);
}


Iman::~Iman(){
	delete this->poloNorte;
	delete this->poloSur;
}