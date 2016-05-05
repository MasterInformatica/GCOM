#ifndef ObjetoCuadrico_H_
#define ObjetoCuadrico_H_

#include "Objeto3D.h"

class ObjetoCuadrico : public Objeto3D {
public:
	ObjetoCuadrico();
	virtual ~ObjetoCuadrico();
	virtual void dibuja()=0;
protected:
	GLUquadric *q;
};

#endif //ObjetoCuadrico_H_