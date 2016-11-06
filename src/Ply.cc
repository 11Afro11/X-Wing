#include "Ply.h"
#include "math.h"


Ply::Ply(char * cadena):Objeto3D(){
	_file_ply ply;
	ply.open(cadena);
	ply.read(vertices, caras);

	// BoundingBox();
	// glScalef(300,300,300);

	// for(int i = 0; i < vertices.size(); i++){
	// 	vertices[i] = vertices[i]*mult;
	// }
}
