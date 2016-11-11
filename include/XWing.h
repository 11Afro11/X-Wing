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
public:
	XWing();
	void Dibujar(int mode, int colour);
	void BoundingBox();
};

#endif
