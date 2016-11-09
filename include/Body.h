#ifndef BODY_
#define BODY_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "Ply.h"
#include "file_ply_stl.h"

class Body{ //hereda de Objeto3D
private:
	Objeto3D base;
	Objeto3D cabina;
public:
	Body();
	void Dibujar(int mode, int colour);
	void BoundingBox();
};

#endif
