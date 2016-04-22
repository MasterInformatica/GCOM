#ifndef OBJETO3D_H_
#define OBJETO3D_H_
  // TODO revisar hecho con emacs

#include "PuntoVector3D.h"


class Objeto3D {

 private:
  TAfin* mT;
  GLColor color;

 public:
  virtual void dibuja();
  void setColor(GLColor c);
  GLColor getColor();

}

#endif
