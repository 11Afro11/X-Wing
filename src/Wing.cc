
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
        // ala.Rotar(-90, 1,0,0);
        ala.Dibujar(mode, 0);
    glPopMatrix();
  glPopMatrix();

}

void Wing::BoundingBox(){
  ala.BoundingBox();
}
