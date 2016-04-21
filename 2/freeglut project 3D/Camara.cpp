 
#include "Camara.h"
#include <cstdio>
#include <cmath>

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
       
	perspective = false;

    left=-10; right=-left; bottom=-10; top=-bottom; 
	Near=1; Far=1000;
	fovy=5; aspect=2.5; 
	velocidadGiro = 0.05;
	setView();  
	setProjection();
	setCameraCoordinateSystem();		     
}

void Camara::setView() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Define la matriz de vista con el comando gluLookAt()     
	gluLookAt(this->eye->getX(), this->eye->getY(), this->eye->getZ(),
			  this->look->getX(), this->look->getY(), this->look->getZ(),
			  this->up->getX(), this->up->getY(), this->up->getZ());
}

void Camara::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n  

	// n = || eye-look ||
	n = this->eye->clonar();
	n->restar(this->look);
	n->normalizar();
		
	// u = || up x n ||
	u = this->up->productoVectorial(this->n);
	u->normalizar();

	// v = n x u
	v = this->n->productoVectorial(this->u);
}


void Camara::setProjection() {
	//OJO: este método no cambia de modo de perspectiva, solamente refresca la proyeccion

	/* Notas al pie:
	ORTOGONAL
	  1) gluOrtho2D( left, right, bottom, top) es equivalente a glOrtho(left, right,  bottom, top, -1, 1);
	  2) glOrtho(left, right, bottom, top, Near, Far); (cabecera de funcion)
	PERSPECTIVA
	  3) glFrustum(left, right, bottom, top, Near, Far); (cabecera de funcion)
	  4) gluPerspective(fovy, aspect, near, far).
	        Donde fovy es apertura en el eje v, y aspect la proporcion del plano cercano
    */
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	if (this->perspective)
		glFrustum(left, right, bottom, top, Near, Far);
	else
		glOrtho(left, right, bottom, top, Near, Far);
	
}


void Camara::switchProjection(){
	this->perspective = !this->perspective;
	setProjection();
}
void Camara::setModelViewMatrix() {
    glMatrixMode(GL_MODELVIEW);		 
    GLfloat m[16];  
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]=-eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0; m[7]=0; m[11]=0; m[15]=1;
    glLoadMatrixf(m); 
}

void Camara::giraX() {
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje
	GLfloat r = sqrt(eye->getZ()*eye->getZ() + eye->getY()*eye->getY());
	GLfloat theta = atan2(eye->getY(), eye->getZ());

	//printf("The arc tangent for (z=%f, y=%f) is %f degrees\n", eye->getZ(), eye->getY(), theta);

	//incremento del angulo
	theta += this->velocidadGiro;

	//Calculo del nuevo eye
	eye->setY(r*sinf(theta));
	eye->setZ(r*cosf(theta));

    setView();
    setCameraCoordinateSystem();     
}

void Camara::giraY() {
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
	GLfloat r = sqrt(eye->getZ()*eye->getZ() + eye->getX()*eye->getX());
	GLfloat theta = atan2(eye->getX(), eye->getZ());

	//incremento del angulo
	theta += this->velocidadGiro;

	//Calculo del nuevo eye
	eye->setX(r*sinf(theta));
	eye->setZ(r*cosf(theta));

	setView();
	setCameraCoordinateSystem();
}

void Camara::giraZ() {
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
	GLfloat r = sqrt(eye->getY()*eye->getY() + eye->getX()*eye->getX());
	GLfloat theta = atan2(eye->getY(), eye->getX());

	//incremento del angulo
	theta += this->velocidadGiro;

	//Calculo del nuevo eye
	eye->setY(r*sinf(theta));
	eye->setX(r*cosf(theta));

	setView();
	setCameraCoordinateSystem();
}

void Camara::lateral() {
	//Coloca la cámara de forma que se muestra una visión lateral 
	//de la escena (desde el eje X) 
	
	//eye encima de look
	eye->setY(look->getY());
	eye->setX(look->getX() + 30);
	eye->setZ(look->getZ());

	//Up para que se vea.
	up->setX(0.0f);
	up->setY(1.0f);
	up->setZ(0.0f);

	setView();
	setCameraCoordinateSystem();
}

void Camara::frontal() {
	//Coloca la cámara de forma que se muestra una visión frontal 
	//de la escena (desde el eje Z)  
	//eye encima de look
	eye->setY(look->getY());
	eye->setX(look->getX());
	eye->setZ(look->getZ() + 30);

	//Up para que se vea.
	up->setX(0.0f);
	up->setY(1.0f);
	up->setZ(0.0f);

	setView();
	setCameraCoordinateSystem();
}

void Camara::cenital() {
    //Coloca la cámara de forma que se muestra una visión cenital 
	//de la escena (desde el eje Y) 
	
	//eye encima de look
	eye->setY(look->getY() + 30);
	eye->setX(look->getX());
	eye->setZ(look->getZ());

	//Up para que se vea.
	up->setX(-1.0f);
	up->setY(0.0f);
	up->setZ(0.0f);

	setView();
	setCameraCoordinateSystem();
}

void Camara::rincon() {
    //Coloca la cámara de forma que se muestra
	//la escena en un rincón

	delete eye;
	eye = new PuntoVector3D(30.0f, 30.0f, 30.0f, 1.0f);

	delete look;
	look = new PuntoVector3D(0.0f, 0.0f, 0.0f, 1.0f);

	delete up;
	up = new PuntoVector3D(0.0f, 1.0f, 0.0f, 0.0f);

	setView();
	setCameraCoordinateSystem();
}
 
void Camara::roll(float ang) {
	//Rotación sobre n = {u', v', n', e'}
	//u' = cos(t)*u + sin(t)*v
	//v' = -sin(t)*u + cos(t)*v;
	//n' = n
	//e' = e

	GLfloat c = cos(ang);
	GLfloat s = sin(ang);

	PuntoVector3D *cu = u->clonar(), *su = u->clonar();
	PuntoVector3D *cv = v->clonar(), *sv = v->clonar();

	cu->escalar(c);
	su->escalar(-1 * s);
	cv->escalar(c);
	sv->escalar(s);


	delete u;
	delete v;

	u = cu; u->sumar(sv);
	delete sv;

	v = su; v->sumar(cv);
	delete cv;


    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
	//Rotación sobre u = {u', v', n', e'}
	//u' = u
	//v' = cos(t)*v + sin(t)*n;
	//n' = -sin(t)*v + cos(t)*n;
	//e' = e

	GLfloat c = cos(ang);
	GLfloat s = sin(ang);

	PuntoVector3D *cn = n->clonar(), *sn = n->clonar();
	PuntoVector3D *cv = v->clonar(), *sv = v->clonar();

	cn->escalar(c);
	sn->escalar(s);
	cv->escalar(c);
	sv->escalar(-1*s);
 
	delete n;
	delete v;

	n = cn; n->sumar(sv);
	delete sv;

	v = sn; v->sumar(cv);
	delete cv;


	setModelViewMatrix();
}

void Camara::yaw(float ang) {		

	//Rotación sobre v = {u', v', n', e'}
	//u' = cos(t)*u - sin(t)*n
	//v' = v;
	//n' = sin(t)*u + cos(t)*n;
	//e' = e

	GLfloat c = cos(ang);
	GLfloat s = sin(ang);

	PuntoVector3D *cn = n->clonar(), *sn = n->clonar();
	PuntoVector3D *cu = u->clonar(), *su = u->clonar();

	cn->escalar(c);
	sn->escalar(-1*s);
	cu->escalar(c);
	su->escalar(s);

	delete n;
	delete u;

	n = cn; n->sumar(su);
	delete su;

	u = cu; u->sumar(sn);
	delete sn;


	setModelViewMatrix();

}
