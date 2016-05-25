#ifndef Objeto3D_H_
#define Objeto3D_H_


#include "PuntoVector3D.h"
#include "TAfin.h"


enum ModoDibuja{
	RELLENO,ARMAZON,PUNTOS
};

class Objeto3D {
 protected:	
	 TAfin *matriz;
	 GLfloat color[3] ;
	 ModoDibuja modo = RELLENO;

 public:
	 Objeto3D();
	 virtual ~Objeto3D();

	  virtual void dibuja()=0;


	  void traslada(PuntoVector3D* punto);
	  void traslada(GLfloat fX, GLfloat fY, GLfloat fZ);
	  void escala(GLfloat fX, GLfloat fY, GLfloat fZ);
	  void rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ);
	  GLfloat* dameMatrizAfin();
	  
	  virtual void setColor(GLfloat r, GLfloat g, GLfloat b);
	  GLfloat* getColor();
	  virtual void setModoDibuja(ModoDibuja m);
	  ModoDibuja getModoDibuja(ModoDibuja m);



};

#endif //Objeto3D_H_
