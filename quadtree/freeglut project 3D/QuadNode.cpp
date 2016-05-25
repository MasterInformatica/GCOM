#include "QuadNode.h"
#include <algorithm>
#include <math.h>

QuadNode::QuadNode(GLfloat esquinaNOx, GLfloat esquinaNOz, GLfloat esquinaSEx, GLfloat esquinaSEz){
	this->NE = NULL;
	this->NO = NULL;
	this->SE = NULL;
	this->SO = NULL;

	this->elementos = new std::vector<Arbol*>();

	this->esquinaNOx = esquinaNOx;
	this->esquinaNOz = esquinaNOz;
	this->esquinaSEx = esquinaSEx;
	this->esquinaSEz = esquinaSEz;
}


QuadNode::~QuadNode(){
	if (this->NE != NULL) delete this->NE;
	if (this->NO != NULL) delete this->NO;
	if (this->SE != NULL) delete this->SE;
	if (this->SO != NULL) delete this->SO;

	if (this->elementos != NULL){
		for (std::vector<Arbol*>::iterator it = this->elementos->begin();
			it != this->elementos->end(); it++){
			delete *it;
		}
		delete this->elementos;
	}
}


bool QuadNode::addElement(Arbol* obj){
	GLfloat posx = obj->getX();
	GLfloat posz = obj->getZ();

	if (!interseccionCilindro(obj->getRadio(), posx, posz))
		return false;


	if (this->elementos!=NULL && this->elementos->size() < QuadNode::MAXELEMS){ //todavía entra
		this->elementos->push_back(obj);
	}
	else if (this->elementos == NULL) { //insertamos en los hijos
		return (this->NO->addElement(obj) || this->NE->addElement(obj) || this->SO->addElement(obj) || this->SE->addElement(obj));
			
	}
	else{
		GLfloat sizex = abs(this->esquinaSEx - this->esquinaNOx);
		GLfloat sizez = abs(this->esquinaSEz - this->esquinaNOz);

		//creamos los nodos, y vaciamos nuestros elementos en los hijos
		this->NO = new QuadNode(this->esquinaNOx, 
								this->esquinaNOz,
			                    this->esquinaNOx + (sizex / 2.0f), 
								this->esquinaNOz + (sizez / 2.0f));

		this->NE = new QuadNode(this->esquinaNOx + (sizex / 2.0f),
								this->esquinaNOz,
								this->esquinaSEx, 
								this->esquinaNOz + (sizez / 2.0f));

		this->SO = new QuadNode(this->esquinaNOx, 
								this->esquinaNOz + (sizez / 2.0f),
			                    this->esquinaNOx + (sizex / 2.0f),
								this->esquinaSEz);

		this->SE = new QuadNode(this->esquinaNOx + (sizex / 2.0f), 
								this->esquinaNOz + (sizez / 2.0f),
								this->esquinaSEx, 
								this->esquinaSEz);
		
		this->elementos->push_back(obj);
		//insertamos el nuevo elemento
		
		for (std::vector<Arbol*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
			//TODO: la posicion no está bien puesta
			if (this->NO->addElement(*it) || this->NE->addElement(*it) || this->SO->addElement(*it) || this->SE->addElement(*it))
				continue;
		}

		//delete this->elementos; //OJO: espero que esto no destruya los elementos de dentro
		this->elementos = NULL;
	}
	return true;
}

bool QuadNode::interseccionCilindro(GLfloat radio, GLfloat posx, GLfloat posz){
	//Comprobamos que estamos en los bordes
	if ((posz + radio) >= this->esquinaNOz 
		&& (posx - radio) <= this->esquinaSEx
		&& (posz - radio) <= this->esquinaSEz
		&&(posx + radio) >= this->esquinaNOx) return true; //izq

	//podemos estar en las esquinas
	if (sqrt((posx - this->esquinaNOx)*(posx - this->esquinaNOx) + 
		     (posz - this->esquinaNOz)*(posz - this->esquinaNOz)) <= radio) return true;  //esquina no
	if (sqrt((posx - this->esquinaSEx)*(posx - this->esquinaSEx) +
		(posz - this->esquinaNOz)*(posz - this->esquinaNOz)) <= radio) return true;  //esquina ne
	if (sqrt((posx - this->esquinaNOx)*(posx - this->esquinaNOx) +
		(posz - this->esquinaSEz)*(posz - this->esquinaSEz)) <= radio) return true;  //esquina So
	if (sqrt((posx - this->esquinaSEz)*(posx - this->esquinaSEz) +
		(posz - this->esquinaSEz)*(posz - this->esquinaSEz)) <= radio) return true;  //esquina Se

	return false;
}

void QuadNode::dibuja(){
	if (this->elementos != NULL){
		for (std::vector<Arbol*>::iterator it = this->elementos->begin();
			it != this->elementos->end(); it++)
			(*it)->dibuja();
	}
	else {
		if (this->NO != NULL) this->NO->dibuja();
		if (this->NE != NULL) this->NE->dibuja();
		if (this->SO != NULL) this->SO->dibuja();
		if (this->SE != NULL) this->SE->dibuja();
	}
}

void QuadNode::dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz){
	int interseccion = this->intersecaRectangulo(NOx, NOz, SEx, SEz);
	if (interseccion == 0){ //contenido
		this->dibuja();
		return;
	}
	else if (interseccion == 1) { //interseco
		if (this->elementos != NULL){ //SOY NODO HOJA: pinto
			for (std::vector<Arbol*>::iterator it = this->elementos->begin();
				it != this->elementos->end(); it++)
				(*it)->dibuja();
		}
		else { //NO SOY NODO HOJA: mando check a los hijos
			if (this->NO != NULL) this->NO->dibuja(NOx, NOz, SEx, SEz);
			if (this->NE != NULL) this->NE->dibuja(NOx, NOz, SEx, SEz);
			if (this->SO != NULL) this->SO->dibuja(NOx, NOz, SEx, SEz);
			if (this->SE != NULL) this->SE->dibuja(NOx, NOz, SEx, SEz);
		}
		return;
	}
	else //no interseco
		return;

}

/* Devuelve:
	1) si interseca
	0) esta contenido
	-1) si no
*/
int QuadNode::intersecaRectangulo(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz){
	GLfloat x1, x2, z1, z2;
	x1 = std::max(NOx, this->esquinaNOx);
	z1 = std::max(NOz, this->esquinaNOz);

	x2 = std::min(SEx, this->esquinaSEx);
	z2 = std::min(SEz, this->esquinaSEz);

	//contenido
	if (x1 == this->esquinaNOx && z1 == this->esquinaNOz &&
		x2 == this->esquinaSEx && z2 == this->esquinaSEz)
		return 0;
	
	//intersección
	if (x1 <= x2 && z1 <= z2)	
		return 1;

	return -1;
}