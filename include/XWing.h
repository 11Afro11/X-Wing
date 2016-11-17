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
	int rotacion;
	int altitud;
	float posx, posy, posz;
	float vdirector[3];
public:
	XWing();
	void Dibujar(int mode, int colour);
	void moveFoward();
	void moveBack();
	void turnLeft();
	void turnRight();
	void up();
	void down();
	void SetAngulo(float val);
	void moveR2();
	void Ejecta();
	void Nuevo();
	void Disparar();
};

#endif
