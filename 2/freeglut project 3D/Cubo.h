
#ifndef Cubo_H_
#define Cubo_H_

#include "Malla.h"
 
class Cubo : public Malla {	 
    public:
        Cubo(float size);
        ~Cubo(); 
		void dibuja();
private:
	float size;
};
#endif