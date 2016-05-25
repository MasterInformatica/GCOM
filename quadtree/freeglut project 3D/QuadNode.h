#ifndef QuadNode_H_
#define QuadNode_H_

#include <vector>

#include "Objeto3D.h"
#include "Arbol.h"

class QuadNode {
public:
	//----------------------------
	static const int MAXELEMS = 1;
	//----------------------------

	QuadNode(GLfloat esquinaNOx, GLfloat esquinaNOz, GLfloat esquinaSEx, GLfloat esquinaSEz);
	virtual ~QuadNode();

	void addElement(Arbol* obj);

private:
	QuadNode(){}

	QuadNode *NE, *NO, *SE, *SO; //Otros hijos
	std::vector<Arbol*>* elementos; //por si guardamos los elementos en vez los hijos (nodo hoja)
	bool interseccionCilindro(GLfloat radio, GLfloat posx, GLfloat posz);

	//Corrdenadas que describen al nodo
	GLfloat esquinaNOx, esquinaNOz;
	GLfloat esquinaSEx, esquinaSEz;
};


#endif //QuadNode_H_