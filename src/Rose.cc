#include "Rose.h"


Rose::Rose():Objeto3D(){
	_file_ply ply;
	ply.open("./ply/rose.ply");
	ply.read(vertices, caras);

	for(int i = 0; i < vertices.size(); i++){
		vertices[i] = vertices[i]*2;
	}
}