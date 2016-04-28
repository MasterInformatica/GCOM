 #include "Objeto3D.h"

Objeto3D::Objeto3D(){
	this->color[0] = 0.5f;
	this->color[1] = 0.5f;
	this->color[2] = 0.5f;

	this->mT = new TAfin();
}


void Objeto3D::setColor(GLfloat r, GLfloat g, GLfloat b){
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
}

GLfloat* Objeto3D::getColor(){
	return this->color;
}

Objeto3D::~Objeto3D(){
	delete mT;
}