#ifndef CopaArbol_H_
#define CopaArbol_H_

#include "ObjetoCompuesto.h"
enum TipoCopa{
	UnaEsfera,
	DosEsferas,
	UnCono,
	DosConos
};


class CopaArbol : public ObjetoCompuesto {
public:
	CopaArbol(TipoCopa type, GLfloat radio, int stacks=25, int slices=25);
	~CopaArbol();
	void cambiarMaterial(GLfloat x);
	virtual void dibuja();
private:
	TipoCopa type;
	GLfloat valSpecular;
};

#endif //CopaArbol_H_