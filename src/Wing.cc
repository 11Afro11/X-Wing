
#include "Wing.h"

Wing::Wing(){
  Ply aux("./ply/wing.ply");
  ala = aux;
  posz = 0;
  posx =0;
  posy = 0;
  rotacion = 0;
  disp = 0;
  disparo = false;
  std::vector<GLfloat> v3;
  v3.push_back(0);
  v3.push_back(1);
  v3.push_back(-4);

  v3.push_back(0);
  v3.push_back(1);
  v3.push_back(4);

  ObjetoDeRevolucion cil3(v3, 100, 'z');

  bala = cil3;
  // bala.Trasladar(7, 7, 0);

  ala.BoundingBox();
  bala.BoundingBox();
  bala.Escalar(80);
  bala.Trasladar(95.9, 43.2, -68);
  dib = 5;
}


void Wing::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        // glRotatef(rotacion, 0,0,1);
        glRotatef(-90, 1,0,0);
        // ala.Rotar(-90, 1,0,0);
        ala.Dibujado(dib, 0, 11);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,disp);
        if(disparo)
          bala.Dibujado(dib, 1,1);
    glPopMatrix();
  glPopMatrix();

}

void Wing::Disparar(float val){
  disparo = true;
  disp += 5*val;
  if(disp > 200){
    disp = 0;
    disparo = false;
  }
}

void Wing::disparado(){
  disp = 0;
  disparo = false;
}

void Wing::SetDibMode(int par){
  dib = par;
}
