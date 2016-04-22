#ifndef TAFIN_H_
#define TAFIN_H_
  // TODO revisar hecho con emacs

#include "PuntoVector3D.h"


class TAfin {
 private:
  GLfloat[16] m;
 public:
  void traslada(PuntoVector3D* V);
  void postmultiplica(GLfloat* m1);
}

#endif
