
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
  cosa.Trasladar(0,-10,0);
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
        base.Dibujado(0, 11);
    glPopMatrix();
    glPushMatrix();
        // cabina.Rotar(rotacion, 0, 1, 0);
        cabina.Rotar(-90, 1,0,0);
        cabina.Dibujado(6, 11);
    glPopMatrix();
    glPushMatrix();
        // hierro.Rotar(rotacion, 0, 1, 0);
        hierro.Rotar(-90,1,0,0);
        hierro.Dibujado(11, 11);
    glPopMatrix();
    glPushMatrix();
        // puntita.Rotar(rotacion, 0, 1, 0);
        puntita.Rotar(-90,1,0,0);
        puntita.Dibujado(0, 11);
    glPopMatrix();
    glPushMatrix();
        // cosa.Rotar(rotacion, 0, 1, 0);
        cosa.Rotar(-90,1,0,0);
        cosa.Dibujado(11, 11);
    glPopMatrix();
    glPushMatrix();
        // atras.Rotar(rotacion, 0, 1, 0);
        atras.Rotar(-90,1,0,0);
        atras.Dibujado(11, 11);
    glPopMatrix();
  glPopMatrix();

}
