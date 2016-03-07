 
#ifndef Malla_H_
#define Malla_H_

#include "PuntoVector3D.h"
#include "Cara.h"

class Malla {	 
    protected:
        int numeroVertices;
        PuntoVector3D** vertice;
        int numeroNormales;
        PuntoVector3D** normal;
        int numeroCaras;
        Cara** cara;        
    public:
        Malla(int nV, int nN, int nC, PuntoVector3D** v, PuntoVector3D** n, Cara** c);
        Malla();
        ~Malla();
        int getNumeroVertices();
        int getNumeroNormales();
        int getNumeroCaras();         
        virtual void dibuja();         
};
#endif
