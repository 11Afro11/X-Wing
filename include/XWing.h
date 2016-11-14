#ifndef XWING_
#define XWING_
#include <iostream>
#include <GL/glut.h>
#include "Objeto3D.h"
#include "Body.h"
#include "Wing.h"
#include "Ply.h"
#include "file_ply_stl.h"

class XWing{ //hereda de Objeto3D
private:
	Body cuerpo;
	Wing ala1, ala2,ala3, ala4;
	float angAla;
	float rotacion;
public:
	XWing();
	void Dibujar(int mode, int colour);
	void BoundingBox();
	void Mueve(float val1, float val2, float val3);
	void SetAngulo(float val){
		angAla += val;
		if(angAla < -20){
			angAla = -20;
		}
		if(angAla > 0){
			angAla = 0;
		}
	}
	void Rotar(float ang);
};

#endif
