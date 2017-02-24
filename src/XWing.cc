
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
        glRotatef(-angAla-20, 0,0,1);
        // glRotatef(-90, 1,0,0);
        ala.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        glRotatef(angAla+20, 0,0,1);
        // glRotatef(-90, 1,0,0);
        glScalef(-1, 1, 1);
        ala.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        glRotatef(angAla+20, 0,0,1);
        // glRotatef(-90, 1,0,0);
        glScalef(1, -1, 1);
        ala.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        glRotatef(-angAla-20, 0,0,1);
        // glRotatef(-90, 1,0,0);
        glScalef(-1, -1, 1);
        ala.Dibujar(mode, 0);
    glPopMatrix();
        // ala.Rotar(-90, 1,0,0);
        cuerpo.Dibujar(mode, 0);
        arturito.Dibujar(mode, 0);
  glPopMatrix();

}


void XWing::moveFoward(float val){

  posx += val*2*sin((rotacion*M_PI)/180);
  // posy += 2*cos((altitud*M_PI)/180)-2*sin((altitud*M_PI)/180);
  posz += val*2*cos((rotacion*M_PI)/180);

}

void XWing::moveBack(float val){

  posx -= val*2*sin((rotacion*M_PI)/180);
  // posy -= 2*cos((altitud*M_PI)/180)-2*sin((altitud*M_PI)/180);
  posz -= val*2*cos((rotacion*M_PI)/180);

}

void XWing::turnLeft(float val) {
    // if(val < 0)val=1;
    rotacion = (int)(rotacion + 5) % 360;
}

void XWing::turnRight(float val) {
    // if(val < 0)val=1;
    rotacion = (int)(rotacion - 5) % 360;
}

void XWing::up(float val){
  altitud = (int)(altitud + 5*val) % 360;
}
void XWing::down(float val){
  altitud = (int)(altitud -5*val) % 360;
}

void XWing::moveR2(float val){
  arturito.Rotar(2*val);
}

void XWing::Ejecta(float val){
  arturito.Ejecta(val);
}

void XWing::Nuevo(){
  arturito.Nuevo();
}

void XWing::Disparar(float val){
  ala.Disparar(val);
}

void XWing::disparado(){
  ala.disparado();
}



void XWing::SetAngulo(float val){
  angAla += 1*val;
  if(angAla < -20){
    angAla = -20;
  }
  if(angAla > 0){
    angAla = 0;
  }
}

bool XWing::abierta(){
  if(angAla == 20)
    return true;
  return false;
}

bool XWing::cerrada(){
  if(angAla == 0)
    return true;
  return false;
}

bool XWing::limite(){
  return arturito.limite();
}
bool XWing::posicion(){
  return arturito.posicion();
}

void XWing::SetDibMode(int par){
  cuerpo.SetDibMode(par);
  ala.SetDibMode(par);
  arturito.SetDibMode(par);

}
void XWing::prenderFuego(){
  ala.prenderFuego();
}

void XWing::apagarFuego(){
  ala.apagarFuego();
}
