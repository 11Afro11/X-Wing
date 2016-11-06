
#include "Body.h"

Body::Body():Objeto3d(){
  _file_ply ply;
	ply.open("./ply/xwin.ply");
	ply.read(vertices, caras);
  glRotatef(90, 0,0,1);
}
