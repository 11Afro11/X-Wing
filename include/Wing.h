#ifndef WING_
#define WING_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "ObjetoDeRevolucion.h"
#include "Ply.h"
#include "file_ply_stl.h"

class Wing{ //hereda de Objeto3D
private:
	Objeto3D ala;
	Objeto3D bala;
	float posz;
	float posx;
	float posy;
	float rotacion;
	float disp;
	bool disparo;
public:
	Wing();
	void Dibujar(int mode, int colour);
	void Escalar(GLfloat x, GLfloat y, GLfloat z){
		ala.Escalar(x, y, z);
	}

	void Rotar(GLfloat ang, GLfloat x, GLfloat y, GLfloat z){
		ala.Rotar(ang, x, y, z);
		// bala.Rotar(ang, x, y, z);
	}
	void Disparar();


};

#endif
