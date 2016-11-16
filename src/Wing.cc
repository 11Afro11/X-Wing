
#include "Wing.h"

Wing::Wing(){
  Ply aux("./ply/wing.ply");
  ala = aux;
  posz = 0;
  posx =0;
  posy = 0;
  rotacion = 0;

  ala.BoundingBox();


}


void Wing::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        // glRotatef(rotacion, 0,0,1);
        glRotatef(-90, 1,0,0);
        // ala.Rotar(-90, 1,0,0);
        ala.Dibujar(mode, 0);
    glPopMatrix();
  glPopMatrix();

}
