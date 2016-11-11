
#include "XWing.h"

XWing::XWing(){
  ala2.Escalar(-1, 1, 1);
}


void XWing::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        ala1.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        ala2.Escalar(-1, 1, 1);
        ala2.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        ala3.Escalar(1, 1, -1);
        ala3.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        ala4.Escalar(-1, 1, -1);
        ala4.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // ala.Rotar(-90, 1,0,0);
        cuerpo.Dibujar(mode, 0);
    glPopMatrix();
  glPopMatrix();

}

void XWing::BoundingBox(){
}
