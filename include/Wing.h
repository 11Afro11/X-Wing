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
	void BoundingBox();
	void Escalar(GLfloat x, GLfloat y, GLfloat z){
		ala.Escalar(x, y, z);
	}
	void Rotar(GLfloat ang, GLfloat x, GLfloat y, GLfloat z){
		// Vuelve();
		ala.Rotar(ang, x, y, z);
		// Mueve(posx, posy, posz);
	}
	void Mueve(float val1, float val2, float val3){
		posx = val1;
		posy = val2;
		posz = val3;
		ala.Trasladar(posx, posz, posy);
	}
	void Vuelve(){
		ala.Trasladar(-posx, -posy, -posz);
	}
};

#endif
