
#include "XWing.h"

XWing::XWing(){
  angAla = 0;
  rotacion = 0;
}


void XWing::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        ala1.Rotar(rotacion*6, 0,1,0);
        ala1.Rotar(-angAla-20, 0,0,1);
        ala1.Rotar(-90, 1,0,0);
        ala1.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala2.Rotar(rotacion*6, 0,1,0);
        ala2.Rotar(angAla+20, 0,0,1);
        ala2.Rotar(-90, 1,0,0);
        ala2.Escalar(-1, 1, 1);
        ala2.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala3.Rotar(rotacion*6, 0,1,0);
        ala3.Rotar(angAla+20, 0,0,1);
        ala3.Rotar(-90, 1,0,0);
        ala3.Escalar(1, 1, -1);
        ala3.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala4.Rotar(rotacion*6, 0,1,0);
        ala4.Rotar(-angAla-20, 0,0,1);
        ala4.Rotar(-90, 1,0,0);
        ala4.Escalar(-1, 1, -1);
        ala4.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        cuerpo.Rotar(rotacion);
        cuerpo.Dibujar(mode, 0);
    glPopMatrix();
  glPopMatrix();

}

void XWing::BoundingBox(){
}

void XWing::Mueve(float val1, float val2, float val3){
  cuerpo.Mueve(val1, val2, val3);
  ala1.Mueve(val1, val2, val3);
  ala2.Mueve(val1, val2, val3);
  ala3.Mueve(val1, val2, val3);
  ala4.Mueve(val1, val2, val3);

}

void XWing::Rotar(float ang){
  rotacion += ang;

}
