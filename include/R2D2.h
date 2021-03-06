#ifndef R2D2_
#define R2D2_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "Ply.h"
#include "file_ply_stl.h"

class R2D2{ //hereda de Objeto3D
private:
	Objeto3D r2;
	float posz;
	float posx;
	float posy;
	float rotacion;
	int dib;
public:
	R2D2();
	void Dibujar(int mode, int colour);
	void Escalar(GLfloat x, GLfloat y, GLfloat z){
		r2.Escalar(x, y, z);
	}

	void Rotar(GLfloat ang){
		rotacion += ang;
	}
	void moveR2();
	void Ejecta(float val);
	void Nuevo();
	bool limite();
	bool posicion();
	void SetDibMode(int par);



};

#endif
