#include "ObjetoCompuesto.h"


ObjetoCompuesto::ObjetoCompuesto() {
	this->elementos = new std::vector<Objeto3D*>();
}


ObjetoCompuesto::~ObjetoCompuesto()
{
	for (std::vector<Objeto3D*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
		delete *it;
	}

	delete this->elementos;
}


void ObjetoCompuesto::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{
		glMultMatrixf(this->mT->m);
		for (std::vector<Objeto3D*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
			(*it)->dibuja();
		}
	}
	glPopMatrix();
}

void ObjetoCompuesto::setModoDibuja(ModoDibuja m){
	this->modo = m;
	for (std::vector<Objeto3D*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
		(*it)->setModoDibuja(m);
	}

}

void ObjetoCompuesto::setColor(GLfloat r, GLfloat g, GLfloat b){
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
	for (std::vector<Objeto3D*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
		(*it)->setColor(r, g, b);
	}
}