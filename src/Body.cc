
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
  puntita.Escalar(1.1);
  puntita.Trasladar(0,-30,0);
  puntita.Trasladar(0,0,8);


}


void Body::Dibujar(int mode, int colour){
  glPushMatrix();
    glPushMatrix();
        // base.Rotar(-90, 1,0,0);
        base.Dibujar(mode, 0);
    glPopMatrix();
    glPushMatrix();
        // cabina.Rotar(-90, 1,0,0);
        cabina.Dibujar(mode,1);
    glPopMatrix();
    glPushMatrix();
        // hierro.Rotar(-90,1,0,0);
        hierro.Dibujar(mode,2);
    glPopMatrix();
    glPushMatrix();
        // puntita.Rotar(-90,1,0,0);
        puntita.Dibujar(mode,3);
    glPopMatrix();
    glPushMatrix();
        // cosa.Rotar(-90,1,0,0);
        cosa.Dibujar(mode,4);
    glPopMatrix();
    glPushMatrix();
        // atras.Rotar(-90,1,0,0);
        atras.Dibujar(mode,4);
    glPopMatrix();
  glPopMatrix();

}

void Body::BoundingBox(){
  base.BoundingBox();
  cabina.BoundingBox();
}
