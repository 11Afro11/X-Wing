
#include "XWing.h"

# define M_PI           3.14159265358979323846  /* pi */
XWing::XWing(){
  angAla = 0;
  rotacion = 0;
  altitud = 0;
  posx = posy = posz = 0;
  vdirector[0] = vdirector[1] =0;
  vdirector[2] = 1;
}


void XWing::Dibujar(int mode, int colour){
  glPushMatrix();
    // glPushMatrix();

        // AplicaMovimiento();
        // AplicaRotacion();
    glTranslatef(posx, posy, posz);
    glRotatef(rotacion, 0,1,0);
    // glPopMatrix();

    glPushMatrix();
        ala1.Rotar(-angAla-20, 0,0,1);
        // ala1.Rotar(-90, 1,0,0);
        ala1.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala2.Rotar(angAla+20, 0,0,1);
        // ala2.Rotar(-90, 1,0,0);
        ala2.Escalar(-1, 1, 1);
        ala2.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala3.Rotar(angAla+20, 0,0,1);
        // ala3.Rotar(-90, 1,0,0);
        ala3.Escalar(1, -1, 1);
        ala3.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        ala4.Rotar(-angAla-20, 0,0,1);
        // ala4.Rotar(-90, 1,0,0);
        ala4.Escalar(-1, -1, 1);
        ala4.Dibujar(mode, 0);
    glPopMatrix();
        // ala.Rotar(-90, 1,0,0);
        cuerpo.Dibujar(mode, 0);
        arturito.Dibujar(mode, 0);
  glPopMatrix();

}


void XWing::moveFoward(){

  posx += 2*sin((rotacion*M_PI)/180);
  // posy += 2*cos((altitud*M_PI)/180)-2*sin((altitud*M_PI)/180);
  posz += 2*cos((rotacion*M_PI)/180);

}

void XWing::moveBack(){

  posx -= 2*sin((rotacion*M_PI)/180);
  // posy -= 2*cos((altitud*M_PI)/180)-2*sin((altitud*M_PI)/180);
  posz -= 2*cos((rotacion*M_PI)/180);

}

void XWing::turnLeft() {
    rotacion = (rotacion + 5) % 360;
}

void XWing::turnRight() {
    rotacion = (rotacion - 5) % 360;
}

void XWing::up(){
  altitud = (altitud + 5) % 360;
}
void XWing::down(){
  altitud = (altitud -5) % 360;
}

void XWing::moveR2(){
  arturito.Rotar(2);
}

void XWing::Ejecta(){
  arturito.Ejecta();
}

void XWing::Nuevo(){
  arturito.Nuevo();
}

void XWing::Disparar(){
  ala1.Disparar();
  ala2.Disparar();
  ala3.Disparar();
  ala4.Disparar();
}



void XWing::SetAngulo(float val){
  angAla += val;
  if(angAla < -20){
    angAla = -20;
  }
  if(angAla > 0){
    angAla = 0;
  }
}
