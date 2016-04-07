#include "Revolucion.h"

//Realiza una copia del perfil.
Revolucion::Revolucion(PuntoVector3D** perfil, int nPuntos){
	this->nPuntosPerfil = nPuntos;

	this->perfil = new PuntoVector3D* [nPuntos];
	for(int i=0; i<nPuntos; i++)
		this->perfil[i] = perfil[i]->clonar();
}


void Revolucion::revoluciona(float grados, int divisiones, bool cerrado){
	this->numeroVertices = this->nPuntosPerfil * (divisiones + 1);
	this->numeroCaras = (cerrado) ? divisiones * nPuntosPerfil : divisiones * (nPuntosPerfil-1);
	this->numeroNormales = this->numeroCaras;

	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//copia del perfil
	for (int i = 0; i < nPuntosPerfil; i++)
		vertice[i] = perfil[i]->clonar();

	//Incremento de la rotacion en radianes
	double incremento = grados / (double)divisiones;
	incremento = (2 * PI*incremento) / 360.0; //grados a radianes

	/* Calculo de los vértices de la malla*/
	double theta=0;
	int indice = nPuntosPerfil;

	for (int i = 1; i <= divisiones; i++){
		theta += incremento;
		double c = cos(theta);
		double s = sin(theta);

		for (int j = 0; j < nPuntosPerfil; j++){
			double x = c*perfil[j]->getX() + s*perfil[j]->getZ();
			double y = perfil[j]->getY();
			double z = -s*perfil[j]->getX() + c*perfil[j]->getZ();

			/* respecto a un eje arbitrario (ux, uy, uz)
			x = (c+ux*ux*(1-c)) + (ux*uy*(1-c)-uz*s) + (ux*uz*(1-c)+uy*s);
			y = (uy*ux*(1-c)+uz*s) + (c+uy*uy*(1-c)) + (uy*uz*(1-c)-ux*s);
			z = (uz*ux*(1-c)-uy*s) + (uz*uy*(1-c)+ux*s) + (c+uz*uz*(1-c));
			*/

			vertice[indice] = new PuntoVector3D(x, y, z, 1);
			indice++;
		}
	}

	/* Construccion de caras */
	int indiceCara = 0;
	indice = 0;

	int cotaCaraPerfil = (cerrado) ? nPuntosPerfil : nPuntosPerfil - 1;
	for (int i = 0; i < divisiones; i++){
		for (int j = 0; j < cotaCaraPerfil; j++){
			indice = nPuntosPerfil * i + j;

			VerticeNormal** vn = new VerticeNormal* [4];

			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + nPuntosPerfil), indiceCara);
			vn[2] = new VerticeNormal((j + 1) % nPuntosPerfil + (i+1)*nPuntosPerfil, indiceCara);
			vn[3] = new VerticeNormal((j + 1) % nPuntosPerfil + (i*nPuntosPerfil), indiceCara);

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

Revolucion::~Revolucion(){
	for(int i=0; i<this->nPuntosPerfil; i++)
		delete this->perfil[i];

	delete this->perfil;
}