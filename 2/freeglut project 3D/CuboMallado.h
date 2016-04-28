
#ifndef CuboMallado_H_
#define CuboMallado_H_

#include "Malla.h"
 
class CuboMallado : public Malla {	 
    public:
		CuboMallado(float size);
		~CuboMallado();
		void dibuja();
private:
	float size;
};
#endif