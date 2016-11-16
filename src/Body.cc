
#include "Body.h"

Body::Body(){
  Ply aux("./ply/xwin.ply");
  base = aux;
  Ply aux1("./ply/Cabina.ply");
  cabina = aux1;
  Ply aux2("./ply/CabinaHierro.ply");
  hierro = aux2;
  Ply aux3("./ply/Puntita.ply");
  puntita = aux3;
  Ply aux4("./ply/CosaRara.ply");
  cosa = aux4;
  Ply aux5("./ply/CosaDeAtras.ply");
  atras = aux5;

  base.BoundingBox();
  cabina.BoundingBox();
  hierro.BoundingBox();
  puntita.BoundingBox();
  cosa.BoundingBox();
  atras.BoundingBox();

  cabina.Escalar(4);
  hierro.Escalar(3.8);
  cosa.Escalar(3.1);
  atras.Escalar(2.9);
  atras.Trasladar(0,0,5);
  atras.Trasladar(0,-17,0);
  // puntita.Trasladar(0,10,0);
  puntita.Escalar(1.19);
  puntita.Trasladar(0,-29,0);
  puntita.Trasladar(0,0,5.5);
  posz = 0;
  posx =0;
  posy = 0;
  rotacion = 0;


}


void Body::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        // base.Rotar(rotacion, 0, 1, 0);
        base.Rotar(-90, 1,0,0);
        base.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // cabina.Rotar(rotacion, 0, 1, 0);
        cabina.Rotar(-90, 1,0,0);
        cabina.Dibujar(mode,1);
    glPopMatrix();
    glPushMatrix();
        // hierro.Rotar(rotacion, 0, 1, 0);
        hierro.Rotar(-90,1,0,0);
        hierro.Dibujar(mode,2);
    glPopMatrix();
    glPushMatrix();
        // puntita.Rotar(rotacion, 0, 1, 0);
        puntita.Rotar(-90,1,0,0);
        puntita.Dibujar(mode,0);
    glPopMatrix();
    glPushMatrix();
        // cosa.Rotar(rotacion, 0, 1, 0);
        cosa.Rotar(-90,1,0,0);
        cosa.Dibujar(mode,4);
    glPopMatrix();
    glPushMatrix();
        // atras.Rotar(rotacion, 0, 1, 0);
        atras.Rotar(-90,1,0,0);
        atras.Dibujar(mode,4);
    glPopMatrix();
  glPopMatrix();

}

void Body::BoundingBox(){
  base.BoundingBox();
  cabina.BoundingBox();
}


void Body::Mueve(float val1, float val2, float val3){
  // posx = val1;
  // posy = val2;
  // posz = val3;
  base.Movimiento(val1,val2,val3);
  cabina.Movimiento(val1,val2,val3);
  hierro.Movimiento(val1,val2,val3);
  puntita.Movimiento(val1,val2,val3);
  cosa.Movimiento(val1,val2,val3);
  atras.Movimiento(val1,val2,val3);
}

void Body::Rotar(float ang){
  rotacion = ang;
  base.Rotar(rotacion, 0,1,0);
  cabina.Rotar(rotacion, 0,1,0);
  hierro.Rotar(rotacion, 0,1,0);
  puntita.Rotar(rotacion, 0,1,0);
  cosa.Rotar(rotacion, 0,1,0);
  atras.Rotar(rotacion, 0,1,0);

}

void Body::Volver(){
  base.Trasladar(-posx,-posz,-posy);
  cabina.Trasladar(-posx,-posz,-posy);
  hierro.Trasladar(-posx,-posz,-posy);
  puntita.Trasladar(-posx,-posz,-posy);
  cosa.Trasladar(-posx,-posz,-posy);
  atras.Trasladar(-posx,-posz,-posy);
  posx = 0;
  posy = 0;
  posz = 0;
}

void Body::Recoloca(){
  base.Trasladar(posx,posz,posy);
  cabina.Trasladar(posx,posz,posy);
  hierro.Trasladar(posx,posz,posy);
  puntita.Trasladar(posx,posz,posy);
  cosa.Trasladar(posx,posz,posy);
  atras.Trasladar(posx,posz,posy);
}
