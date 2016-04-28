#ifndef Objeto3D_H_
#define Objeto3D_H_


#include "PuntoVector3D.h"
#include "TAfin.h"


enum ModoDibuja{
	RELLENO,ARMAZON,PUNTOS
};

class Objeto3D {
 protected:	
	 TAfin *mT;
	 GLfloat color[3] = { 0.5f, 0.5f, 0.5f };
	 ModoDibuja modo = RELLENO;

 public:
	 Objeto3D();
	 virtual ~Objeto3D();

	  virtual void dibuja()=0;
	  virtual void setColor(GLfloat r, GLfloat g, GLfloat b);
	  GLfloat* getColor();
	  virtual void setModoDibuja(ModoDibuja m);
	  ModoDibuja getModoDibuja(ModoDibuja m);

};

#endif //Objeto3D_H_
