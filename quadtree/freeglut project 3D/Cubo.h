
#ifndef Cubo_H_
#define Cubo_H_

#include "Objeto3D.h"
 
class Cubo : public Objeto3D {	 
    public:
        Cubo(GLfloat size);
        ~Cubo(); 
		void dibuja();
    private:
		GLfloat size;
};
#endif