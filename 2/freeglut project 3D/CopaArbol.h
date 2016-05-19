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
private:
	TipoCopa type;
};

#endif //CopaArbol_H_