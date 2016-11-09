
#include "Body.h"

Body::Body(){
  Ply aux("./ply/xwin.ply");
  base = aux;
  Ply aux1("./ply/Cabina.ply");
  cabina = aux1;
  base.BoundingBox();
  cabina.BoundingBox();
}


void Body::Dibujar(int mode, int colour){
  base.Dibujar(mode, colour);
  cabina.Dibujar(mode,colour);
}

void Body::BoundingBox(){
  base.BoundingBox();
  cabina.BoundingBox();
}
