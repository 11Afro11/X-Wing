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
	float posz;
	float posx;
	float posy;
	float rotacion;
public:
	Wing();
	void Dibujar(int mode, int colour);
	void Escalar(GLfloat x, GLfloat y, GLfloat z){
		ala.Escalar(x, y, z);
	}

	void Rotar(GLfloat ang, GLfloat x, GLfloat y, GLfloat z){
		ala.Rotar(ang, x, y, z);
	}


};

#endif
