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
	Objeto3D hierro;
	Objeto3D puntita;
	Objeto3D cosa;
	Objeto3D atras;
	float posz;
	float posx;
	float posy;
	float rotacion;
public:
	Body();
	void Dibujar(int mode, int colour);
	void BoundingBox();
	void Mueve(float val, float val2, float val3);
	void Rotar(float ang);
	void Volver();
	void Recoloca();
};
#endif
