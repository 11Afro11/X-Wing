//Objeto3D.h

#ifndef OBJETO3D_
#define OBJETO3D_

#include <vector>
#include <cstring>
#include <GL/glut.h>
#include "Colors.h"
#include "math.h"

class Objeto3D{
	protected:

		std::vector<GLfloat> vertices;
		std::vector<int> caras;
		Colors color;
		GLfloat medio[3];
		GLfloat lado;
		GLfloat angulo, x, y, z;
		// std::vector<GLfloat> colores;


	public:

		Objeto3D();

		Objeto3D(const Objeto3D & otro){
			CopiarDatos(otro);
		}

		void AniadeCara(int vect){
			caras.push_back(vect);
		}
		//metodo para dibujar los 3 primeros modos
		void Dibujar(int mode, int colour);

		//metodo para dibujar en ajedrez
		void DibujaAjedrez();

		//metodo que dibuja cada cara de un color sin repetirlo
		void DibujaVaricolor();

		void Dibujado(int mode, int col, int secundario);

		//metodo que cambia a un color aleatorio
		int CambiaColor();

		int Division();
		char Eje();

		std::vector<GLfloat> DevuelveVert(){
			return vertices;
		}

		// void Resize(int i);

		Objeto3D & operator = (const Objeto3D & otro);

		void CopiarDatos (const Objeto3D & otro);


		float BoundingBox();

		void TraslacionEscalada();

		void Escalar(GLfloat esc);

		void Escalar(GLfloat x, GLfloat y, GLfloat z);

		void Rotar(GLfloat ang, GLfloat x, GLfloat y, GLfloat z);


		void Trasladar(GLfloat x, GLfloat y, GLfloat z);

		void Movimiento(GLfloat x, GLfloat y, GLfloat z);


};
#endif
