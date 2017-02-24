
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
  std::vector<GLfloat> v4;
  float alpha = 2*M_PI/100;
  GLfloat uno, dos, tres;
  for(int j = 0; j <= 100; j++){
      uno = cos(alpha*j) + sin(alpha*j);
      dos = -sin(alpha*j) + cos(alpha*j);
      tres = 0;
      v4.push_back(uno);
      v4.push_back(dos);
      v4.push_back(tres);
  }

  ObjetoDeRevolucion esf(v4, 100, 'x');
  fayer = esf;

  ObjetoDeRevolucion cil3(v3, 100, 'z');

  bala = cil3;
  // bala.Trasladar(7, 7, 0);

  ala.BoundingBox();
  bala.BoundingBox();
  fayer.BoundingBox();
  bala.Escalar(80);
  fayer.Escalar(10);
  // fayer.Trasladar(-19,0,0);
  // fayer.Trasladar(0,-30,0);
  // fayer.Trasladar(0,0,125);
  bala.Trasladar(95.9, 43.2, -68);
  dib = 5;
  fuego = 0;
  encendido = false;
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
    glPushMatrix();
        // glTranslatef(0,0,disp);
        // if(disparo)
          glTranslatef(20, 30, -125);
          glScalef(0.5, 0.5, 0.5+fuego);
          if(encendido)
            fayer.Dibujado(dib, 1,1);
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

void Wing::prenderFuego(){
  fuego++;
}

void Wing::apagarFuego(){
  fuego--;
}
