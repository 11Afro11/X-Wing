
#include "R2D2.h"

R2D2::R2D2(){
  Ply aux("./ply/R2D2.ply");
  r2 = aux;
  posz = -18;
  posx =0;
  posy = -10;
  rotacion = 0;
  r2.BoundingBox();
  r2.Escalar(6.5);
  r2.Trasladar(0,22,0);

}


void R2D2::Dibujar(int mode, int colour){
  glPushMatrix();

    glTranslatef(posx, posy, posz);
    // r2.Trasladar(0,2,10);
    glRotatef(rotacion, 0,1,0);
    glPushMatrix();
        glRotatef(-90, 1,0,0);
        // ala.Rotar(-90, 1,0,0);
        // r2.Trasladar(0,2,10);
        r2.DibujaAjedrez();
    glPopMatrix();
  glPopMatrix();

}

void R2D2::Ejecta(){
  posy += 4;
}

void R2D2::Nuevo(){
  posy = -10;
}
