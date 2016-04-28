#include "TAfin.h"

TAfin::TAfin(){
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glLoadIdentity();
		glGetFloatv(GL_MODELVIEW_MATRIX, this->m);
	glPopMatrix();
}

void TAfin::traslada(PuntoVector3D* v) {

  glMatrixMode(GL_MODELVIEW);

  glPushMatrix();

    glLoadIdentity();
    glTranslatef(v->getX(), v->getY(), v->getZ());
    GLfloat m1[16];
    //Dejar la matriz actual de modelado-vista en m1
    //Los 16 datos están enumerados por columnas
    glGetFloatv(GL_MODELVIEW_MATRIX, m1);
  
  glPopMatrix();
  
  this->postMultiplica(m1);
}

void TAfin::gira(GLfloat ang, PuntoVector3D* v){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

		glLoadIdentity();
		glRotatef(ang, v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);

	glPopMatrix();

	this->postMultiplica(m1);
}


void TAfin::escala(PuntoVector3D* v){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

		glLoadIdentity();
		glScalef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);

	glPopMatrix();

	this->postMultiplica(m1);
}


void TAfin::postMultiplica(GLfloat* m1) {

  glMatrixMode(GL_MODELVIEW);
 
  glPushMatrix();

    //Cargar m como matriz actual de modelado-vista
    glLoadMatrixf(m);

    //Post-multiplicar por m1
    glMultMatrixf(m1);

    //Dejar el resultado en m
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
  
  glPopMatrix();
}
