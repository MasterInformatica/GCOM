#ifndef QuadNode_H_
#define QuadNode_H_

#include <vector>

#include "Objeto3D.h"
#include "Arbol.h"

class QuadNode {
public:
	//----------------------------
	const int MAXELEMS = 2;
	//----------------------------

	QuadNode(GLfloat esquinaNOx, GLfloat esquinaNOz, GLfloat esquinaSEx, GLfloat esquinaSEz);
	virtual ~QuadNode();

	bool addElement(Arbol* obj);

	void dibuja();
	//Dibuja solamente los elementos de dentro del rectangulo dado.
	void dibuja(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz);
private:
	QuadNode(){}

	QuadNode *NE, *NO, *SE, *SO; //Otros hijos
	std::vector<Arbol*>* elementos; //por si guardamos los elementos en vez los hijos (nodo hoja)
	
	bool interseccionCilindro(GLfloat radio, GLfloat posx, GLfloat posz);

	//Corrdenadas que describen al nodo
	GLfloat esquinaNOx, esquinaNOz;
	GLfloat esquinaSEx, esquinaSEz;


	/* Devuelve:
	 1) si interseca
	 0) esta contenido
	 -1) si no
	*/
	int intersecaRectangulo(GLfloat NOx, GLfloat NOz, GLfloat SEx, GLfloat SEz);
};


#endif //QuadNode_H_