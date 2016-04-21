 
#ifndef CamaraH
#define CamaraH

#include "PuntoVector3D.h"
 
class Camara {
	private:
		PuntoVector3D *eye, *up, *look, *u, *v, *n;				
        GLfloat left, right, bottom, top, Near, Far;                
        GLdouble fovy, aspect; 		 
		bool perspective;

		void setView();	
		void setCameraCoordinateSystem();
        void setModelViewMatrix();


		GLfloat velocidadGiro;

	public:				
		Camara();		 
                                                                     
        void giraX();
        void giraY();
        void giraZ();
        void lateral();
        void frontal();
        void cenital();
        void rincon(); 
		void setProjection();
		void switchProjection();
		void roll(float ang);
        void pitch(float ang);
        void yaw(float ang);    
		void actualizaVolumenVista(GLdouble L, GLdouble R, GLdouble B, GLdouble T);
};
#endif
