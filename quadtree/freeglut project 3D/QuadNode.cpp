#include "QuadNode.h"

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

	if (this->elementos != NULL) delete this->elementos;
}


void QuadNode::addElement(Arbol* obj){
	GLfloat posx = obj->getX();
	GLfloat posz = obj->getZ();

	if (!interseccionCilindro(obj->getRadio(), posx, posz))
		return;


	if (this->elementos->size() < QuadNode::MAXELEMS){ //todavía entra
		this->elementos->push_back(obj);
	}
	else {
		GLfloat sizex = this->esquinaSEx - this->esquinaNOx;
		GLfloat sizez = this->esquinaSEz - this->esquinaNOz;

		//creamos los nodos, y vaciamos nuestros elementos en los hijos
		this->NO = new QuadNode(this->esquinaNOx, this->esquinaNOz,
			                    this->esquinaNOx + (sizex / 2.0f), this->esquinaNOz + (sizez / 2.0f));
		this->NE = new QuadNode(this->esquinaNOx + (sizex / 2.0f), this->esquinaNOz,
								this->esquinaSEx, this->esquinaNOz + (sizez / 2.0f));
		this->SO = new QuadNode(this->esquinaNOx, this->esquinaNOz + (sizez / 2.0f),
			                    this->esquinaNOx + (sizex / 2.0f), this->esquinaSEz);
		this->SE = new QuadNode(this->esquinaNOx + (sizex / 2.0f), this->esquinaNOz + (sizex / 2.0f),
								this->esquinaSEx, this->esquinaSEz);

		//insertamos el nuevo elemento
		this->NO->addElement(obj);
		this->NE->addElement(obj);
		this->SO->addElement(obj);
		this->SE->addElement(obj);

		for (std::vector<Arbol*>::iterator it = this->elementos->begin(); it != this->elementos->end(); it++){
			//TODO: la posicion no está bien puesta
			this->NO->addElement(*it);
			this->NE->addElement(*it);
			this->SO->addElement(*it);
			this->SE->addElement(*it);
		}

		delete this->elementos; //OJO: espero que esto no destruya los elementos de dentro
		this->elementos = NULL;
	}

}

bool QuadNode::interseccionCilindro(GLfloat radio, GLfloat posx, GLfloat posz){
	//Comprobamos que estamos en los bordes
	if ((posz + radio) >= this->esquinaNOz) return true; //arriba
	if ((posx - radio) <= this->esquinaSEx) return true; //dcha
	if ((posz - radio) <= this->esquinaSEz) return true; //abajo
	if ((posx + radio) >= this->esquinaNOx) return true; //izq

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