 #include "Objeto3D.h"

Objeto3D::Objeto3D(){
	this->color[0] = 0.5f;
	this->color[1] = 0.5f;
	this->color[2] = 0.5f;

	this->matriz = new TAfin();
}



void Objeto3D::traslada(PuntoVector3D* punto) {
	traslada(punto->getX(), punto->getY(), punto->getZ());
}

void Objeto3D::traslada(GLfloat fX, GLfloat fY, GLfloat fZ) {
	matriz->traslada(fX, fY, fZ);
}

void Objeto3D::escala(GLfloat fX, GLfloat fY, GLfloat fZ) {
	matriz->escala(fX, fY, fZ);
}

void Objeto3D::rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ) {
	matriz->rota(alfa, fX, fY, fZ);
}


GLfloat* Objeto3D::dameMatrizAfin() {
	return matriz->dameMatrizModelado();
}


void Objeto3D::setColor(GLfloat r, GLfloat g, GLfloat b){
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
}

GLfloat* Objeto3D::getColor(){
	return this->color;
}

void Objeto3D::setModoDibuja(ModoDibuja m){
	modo = m;
}

ModoDibuja Objeto3D::getModoDibuja(ModoDibuja m){
	return modo;
}

Objeto3D::~Objeto3D(){
	delete matriz;
}
