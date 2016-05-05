#include "TAfin.h"

TAfin::TAfin(){
	m = new GLfloat[16];
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glLoadIdentity();
		glGetFloatv(GL_MODELVIEW_MATRIX, this->m);
	glPopMatrix();
}

TAfin::~TAfin(){
	delete[] m;
}

GLfloat* TAfin::dameMatrizModelado() {
	return m;
}

void TAfin::traslada(GLfloat X, GLfloat Y, GLfloat Z) {


  glMatrixMode(GL_MODELVIEW);

  glPushMatrix();

    glLoadIdentity();
    glTranslatef(X,Y,Z);
    GLfloat m1[16];
    //Dejar la matriz actual de modelado-vista en m1
    //Los 16 datos están enumerados por columnas
    glGetFloatv(GL_MODELVIEW_MATRIX, m1);
  
  glPopMatrix();
  
  this->postMultiplica(m1);
}

void TAfin::rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ) {

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

		glLoadIdentity();
		glRotatef(alfa, fX, fY, fZ);
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);

	glPopMatrix();

	this->postMultiplica(m1);
}


void TAfin::escala(GLfloat fX, GLfloat fY, GLfloat fZ) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

		glLoadIdentity();
		glScalef(fX, fY, fZ);
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);

	glPopMatrix();

	this->postMultiplica(m1);
}


void TAfin::postMultiplica(GLfloat* mm) {

  glMatrixMode(GL_MODELVIEW);
 
  glPushMatrix();

    //Cargar m como matriz actual de modelado-vista
    glLoadMatrixf(m);

    //Post-multiplicar por mm
    glMultMatrixf(mm);

    //Dejar el resultado en m
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
  
  glPopMatrix();
}
