#ifndef PLY_
#define PLY_
#include <iostream>
#include "Objeto3D.h"
#include "file_ply_stl.h"

class Ply : public Objeto3D{ //hereda de Objeto3D
public:
	Ply(char * cadena);
};
#endif
