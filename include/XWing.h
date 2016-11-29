#ifndef XWING_
#define XWING_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "Body.h"
#include "Wing.h"
#include "R2D2.h"
#include "Ply.h"
#include "file_ply_stl.h"

class XWing{ //hereda de Objeto3D
private:
	Body cuerpo;
	Wing ala1, ala2,ala3, ala4;
	R2D2 arturito;
	float angAla;
	float rotacion;
	float altitud;
	float posx, posy, posz;
	float vdirector[3];
	int dib;
public:
	XWing();
	void Dibujar(int mode, int colour);
	void moveFoward(float val);
	void moveBack(float val);
	void turnLeft(float val);
	void turnRight(float val);
	void up(float val);
	void down(float val);
	void SetAngulo(float val);
	void moveR2(float val);
	void Ejecta(float val);
	void Nuevo();
	void Disparar(float val);
	bool abierta();
	bool cerrada();
	void disparado();
	bool limite();
	bool posicion();
	void SetDibMode(int par);
};

#endif
