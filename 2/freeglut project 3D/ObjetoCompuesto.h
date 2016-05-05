#ifndef ObjetoCompuesto_H_
#define ObjetoCompuesto_H_

#include <vector>
#include "Objeto3D.h"

class ObjetoCompuesto : public Objeto3D {
protected:
	std::vector<Objeto3D*> *elementos;
public:
	ObjetoCompuesto();
	virtual ~ObjetoCompuesto();
	virtual void dibuja();
	void introduceObjeto(Objeto3D* objeto);
	void setModoDibuja(ModoDibuja m);
	void setColor(GLfloat r, GLfloat g, GLfloat b);
};

#endif //ObjetoCompuesto_H_