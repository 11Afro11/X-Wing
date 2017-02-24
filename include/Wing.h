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
	Objeto3D fayer;
	float posz;
	float posx;
	float posy;
	float rotacion;
	float disp;
	bool disparo;
	float fuego;
	int dib;
	bool encendido;
public:
	Wing();
	void Dibujar(int mode, int colour);
	void Disparar(float val);
	void disparado();
	void SetDibMode(int par);
	void prenderFuego();
	void apagarFuego();
	void enciendeApaga(bool mecha){
		encendido = mecha;
	}
};

#endif
