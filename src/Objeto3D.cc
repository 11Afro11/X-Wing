
#include "Objeto3D.h"
#include <iostream>


Objeto3D::Objeto3D(){
	angulo = x = y = z = 0;
}

void Objeto3D::Dibujar(int mode, int colour){
	// glGenBuffers(1, &caras);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, caras);
	TraslacionEscalada();
	// glRotatef(angulo, x, y, z);
	//tipo enumerado para deibujar y para el parámetro del polygon mode
	GLenum dibujado = GL_TRIANGLES;
	GLenum parametro = GL_FILL;

	// colour = colour % color.Tam();

	GLfloat uno = color(colour,0);
	GLfloat dos = color(colour,1);
	GLfloat tres = color(colour,2);



	switch(mode)
	{
		case 0:// cubo relleno
			parametro = GL_FILL;
			dibujado = GL_TRIANGLES;
			break;
		case 1://modo alambre
			parametro = GL_LINE;
			dibujado = GL_TRIANGLES;
			break;
		case 2://modo puntos
			glPointSize(3);
			dibujado = GL_POINTS;
			parametro = GL_FILL;
			break;

	}
	//color
	glColor3f(uno, dos, tres);

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, parametro); //Ambas caras en alambres

	glDrawElements(dibujado, caras.size(), GL_UNSIGNED_INT, &caras[0]);
}


void Objeto3D::DibujaAjedrez(){
	TraslacionEscalada();
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//bucle for que pinta las caras en ajedrez
	for(int i = 0; i< caras.size(); i+=3){
		if(i %2 == 0){
			glColor3f(0.7,0.75,0.71);
			// glColorPointer(3, GL_FLOAT, 0, &colores[colour]);
		}
		else{
			glColor3f(0.0, 0.0, 1.0);
			// glColorPointer(3, GL_FLOAT, 0, &colores[colour]);
		}
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);

	}

}

void Objeto3D::Dibujado(int colour, int secundario){
	glPushMatrix();
			glPushMatrix();
					Dibujar(0,colour);
			glPopMatrix();
			glPushMatrix();
					Dibujar(1,secundario);
			glPopMatrix();
	glPopMatrix();
}

void Objeto3D::DibujaVaricolor(){
	TraslacionEscalada();
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	// Colors color;
	GLfloat uno;
	GLfloat dos;
	GLfloat tres;

	//bucle for que pinta las caras en ajedrez
	int cont = 0;
	for(int i = 0; i< caras.size(); i+=3){
		uno = color(cont,0);
		dos = color(cont,1);
		tres = color(cont,2);
		glColor3f(uno, dos, tres);
		// glColorPointer(3, GL_FLOAT, 0, &colores[colour]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &caras[i]);
		cont++;
		if(cont >= color.Tam()){
			cont = 0;
		}
	}
}


int Objeto3D::CambiaColor(){
	//colores.size();
	int tam = color.Tam()-1;
	int aleatorio = rand() % tam;
	return aleatorio;
}

Objeto3D & Objeto3D :: operator = (const Objeto3D & otro)
{
		if (this != &otro) { // Evitar autoasignación
			CopiarDatos(otro);
		}
		return (*this);  // Objeto implicito: parte
										 // izquierda de la asignación
}

void Objeto3D :: CopiarDatos (const Objeto3D & otro)
{
	// Copiar datos privados
	vertices.clear();
	caras.clear();
	color = otro.color;
	for(int i = 0; i < otro.vertices.size(); i++){
		vertices.push_back(otro.vertices[i]);
	}
	for(int i = 0; i < otro.caras.size(); i++){
		caras.push_back(otro.caras[i]);
	}
}

GLfloat Objeto3D::BoundingBox(){
	GLfloat xmin, ymin, zmin, xmax, ymax, zmax;
	xmin = ymin = zmin = 0;
	xmax = ymax = zmax = 0;

	for(int i = 0; i < vertices.size(); i+=3){
		if(vertices[i] <= xmin)
			xmin = vertices[i];
		if(vertices[i] >= xmax)
			xmax = vertices[i];
		if(vertices[i+1] <= ymin)
			ymin = vertices[i+1];
		if(vertices[i+1] >= ymax)
			ymax = vertices[i+1];
		if(vertices[i+2] <= zmin)
			zmin = vertices[i+2];
		if(vertices[i+2] >= zmax)
			zmax = vertices[i];
	}

	medio[0] = (xmin + xmax)/2;
	medio[1] = (ymin + ymax)/2;
	medio[2] = (zmin + zmax)/2;

	// GLfloat lado;

	GLfloat lado1 = sqrt((zmax -zmin)*(zmax -zmin));
	GLfloat lado2 = sqrt((xmax -xmin)*(xmax -xmin));
	GLfloat lado3 = sqrt((ymax -ymin)*(ymax -ymin));

	if(lado1 >= lado2 && lado1 >= lado3)
		lado = lado1;
	else if(lado2 >= lado1 && lado2 >= lado3)
		lado = lado2;
	else if(lado3 >= lado1 && lado3 >= lado2)
		lado = lado3;

	lado = 180/lado;

}

void Objeto3D::TraslacionEscalada(){
	glTranslatef(-medio[0], -medio[1], -medio[2]);
	// std::cout << "El lado mide: "<< lado <<std::endl;
	// for(int i = 0; i < vertices.size(); i++){
	// 	vertices[i] *= escala;
	// }
	glScalef(lado, lado, lado);
}

void Objeto3D::Escalar(GLfloat esc){
	lado =lado/esc;
}

void Objeto3D::Escalar(GLfloat x, GLfloat y, GLfloat z){
	glScalef(x, y, z);
}

void Objeto3D::Rotar(GLfloat ang, GLfloat x, GLfloat y, GLfloat z){
	glRotatef(ang, x, y, z);
}

void Objeto3D::Trasladar(GLfloat x, GLfloat y, GLfloat z){
	medio[0] += x;
	medio[1] += y;
	medio[2] += z;
}

void Objeto3D::Movimiento(GLfloat x, GLfloat y, GLfloat z){
	glTranslatef(x, y, z);
}


// void Objeto3D::Resize(int i){}
