
#include "XWing.h"

# define M_PI           3.14159265358979323846  /* pi */
XWing::XWing(){
  angAla = 0;
  rotacion = 0;
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
  glPopMatrix();

}

void XWing::BoundingBox(){
}

void XWing::Mueve(float val1, float val2, float val3){

  posx += 0.5*sin((rotacion*M_PI)/180);
  posy = val2;
  posz += 0.5*cos((rotacion*M_PI)/180);
  // if(val3>0 and posz <0 or val3 < 0 and posz>0){
  //   posz *= -1;
  // }
  // cuerpo.Mueve(val1, val2, val3);
  // ala1.Mueve(val1, val2, val3);
  // ala2.Mueve(val1, val2, val3);
  // ala3.Mueve(val1, val2, val3);
  // ala4.Mueve(val1, val2, val3);

}

void XWing::turnLeft() {
    rotacion = (rotacion + 5) % 360;
}

void XWing::turnRight() {
    rotacion = (rotacion - 5) % 360;
}

void XWing::Rotar(float ang){
  rotacion = ang;

  vdirector[0] = sin((rotacion*M_PI)/180)*vdirector[2] + cos((rotacion*M_PI)/180)*vdirector[0];


  // posz+=val3;
  vdirector[2] = cos((rotacion*M_PI)/180)*vdirector[2] - sin((rotacion*M_PI)/180)*vdirector[0];
  // ala1.Vuelve();
  // ala2.Vuelve();
  // ala3.Vuelve();
  // ala4.Vuelve();
  // cuerpo.Volver();
  // ala1.Rotar(rotacion);
  // ala2.Rotar(rotacion);
  // ala3.Rotar(rotacion);
  // ala4.Rotar(rotacion);
  // cuerpo.Rotar(rotacion);
  // ala1.Recoloca();
  // ala2.Recoloca();
  // ala3.Recoloca();
  // ala4.Recoloca();
  // cuerpo.Recoloca();


}

void XWing::AplicaMovimiento(){
  cuerpo.Mueve(posx, posy, posz);
  ala1.Mueve(posx, posy, posz);
  ala2.Mueve(posx, posy, posz);
  ala3.Mueve(posx, posy, posz);
  ala4.Mueve(posx, posy, posz);
}

void XWing::AplicaRotacion(){
  // float aux1, aux2, aux3;
  // Volver(aux1, aux2, aux3);
  ala1.Rotar(rotacion*M_PI/180, 0, 1, 0);
  ala2.Rotar(rotacion*M_PI/180, 0, 1, 0);
  ala3.Rotar(rotacion*M_PI/180, 0, 1, 0);
  ala4.Rotar(rotacion*M_PI/180, 0, 1, 0);
  cuerpo.Rotar(rotacion*M_PI/180);
  // Mueve(aux1,aux2,aux3);
}

void XWing::Volver(float &aux1, float &aux2, float &aux3){
  ala1.Vuelve();
  ala2.Vuelve();
  ala3.Vuelve();
  ala4.Vuelve();
  cuerpo.Volver();
  aux1 = posx;
  aux2 = posy;
  aux3 = posz;
  posx = 0;
  posy = 0;
  posz = 0;
}
