#ifndef WING_
#define WING_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "Ply.h"
#include "file_ply_stl.h"

class Wing{ //hereda de Objeto3D
private:
	Objeto3D ala;
public:
	Wing();
	void Dibujar(int mode, int colour);
	void BoundingBox();
	void Escalar(GLfloat x, GLfloat y, GLfloat z){
		ala.Escalar(x, y, z);
	}
};

#endif
