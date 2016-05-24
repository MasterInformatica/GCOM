#include "CopaArbol.h"
#include "Esfera.h"
#include "Cilindro.h"
#include "Objeto3D.h"
#include "Disco.h"
#include <iostream>
#include <string>

CopaArbol::CopaArbol(TipoCopa type, GLfloat radio, int stacks, int slices){
	this->type = type;
	this->valSpecular = 0.0f;


	Objeto3D* obj;

	switch (type){
	case UnaEsfera:
		obj = new Esfera(radio, slices, stacks);
		this->introduceObjeto(obj);
		break;
	case DosEsferas:
		obj = new Esfera(radio, slices, stacks);
		obj->traslada(-0.6*radio, 0.0f, 0.0f);
		this->introduceObjeto(obj);

		obj = new Esfera(radio, slices, stacks);
		obj->traslada(0.6*radio, 0.0f, 0.0f);
		this->introduceObjeto(obj);
		break;
	case UnCono:
		obj = new Cilindro(radio, 0.0f, radio*2.0, slices, stacks);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);
		this->introduceObjeto(obj);

		obj = new Disco(0.0f, radio, slices, stacks);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);
		this->introduceObjeto(obj);
		break;
	case DosConos:
		obj = new Cilindro(radio, 0.0f, radio*2.0, slices, stacks);
		obj->traslada(0.0f, -0.4*radio, 0.0f);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);

		this->introduceObjeto(obj);

		obj = new Disco(0.0f, radio, slices, stacks);
		obj->traslada(0.0f, -0.4*radio, 0.0f);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);
		this->introduceObjeto(obj);



		obj = new Cilindro(radio, 0.0f, radio*2.0, slices, stacks);
		obj->traslada(0.0f, 0.4*radio, 0.0f);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);

		this->introduceObjeto(obj);

		obj = new Disco(0.0f, radio, slices, stacks);
		obj->traslada(0.0f, 0.4*radio, 0.0f);
		obj->rota(-90, 1.0f, 0.0f, 0.0f);
		this->introduceObjeto(obj);
		break;
	}

	this->setColor(0.0f, 0.8f, 0.6f);
}

void CopaArbol::cambiarMaterial(GLfloat x){
	GLfloat val = this->valSpecular + x;
	this->valSpecular = (val > 1.0f) ? 1.0 : 
			                	((val < 0.0f) ? 0.0f : val);
}

void CopaArbol::dibuja(){
	std::cout << "Imprimo un: " << this->valSpecular << std::endl;
	GLfloat col[] = { this->valSpecular, this->valSpecular, this->valSpecular, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, col);

	ObjetoCompuesto::dibuja();

	GLfloat col2[] = {0.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, col2);
}

CopaArbol::~CopaArbol()
{
}
