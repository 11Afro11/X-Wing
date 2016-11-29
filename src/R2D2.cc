
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
  dib = 3;

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
        r2.Dibujado(dib,3, 11);
    glPopMatrix();
  glPopMatrix();

}

void R2D2::Ejecta(float val){
  posy += 1*val;
}

void R2D2::Nuevo(){
  posy = -20;
}

bool R2D2::limite(){
  if(posy > 100){
    return true;
  }
  return false;
}

bool R2D2::posicion(){
  if(posy = -10)
    return true;
  return false;
}
void R2D2::SetDibMode(int par){
  dib = par;
}
