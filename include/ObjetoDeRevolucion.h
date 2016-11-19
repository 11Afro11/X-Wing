#ifndef OBJETODEREVOLUCION_
#define OBJETODEREVOLUCION_
#include <iostream>
#include "Objeto3D.h"
#include "file_ply_stl.h"

class ObjetoDeRevolucion : public Objeto3D{ //hereda de Objeto3D
private:
	int division;
	std::vector<GLfloat> inicial;
	std::vector<int> tapa;
	std::vector<int> base;
	char eje;
public:
	ObjetoDeRevolucion(char * cadena, int numerodiv, char eje);
	ObjetoDeRevolucion(std::vector<GLfloat> vertices, int numerodiv, char eje);
	// ObjetoDeRevolucion(Objeto3D & otro, int divi, char ej){
	// 	division = divi;
	// 	eje = ej;
	// 	CopiarDatos(otro);
	// }
	int Cubo();
	void CreaObjeto();
	void CalculaPuntos(int tam);
	void CarasLaterales();
	// void Tapas();
	void Base();
	void Tapa();
	bool NecesitoTapa();
	bool NecesitoBase();
	void Resize(int value);
	void ConSinTapa(int cond);
	void ConSinBase(int cond);
	void Aleatorio();

	// void Redivide(int value, char ej, int division);
	//
	// ObjetoDeRevolucion & operator = (const ObjetoDeRevolucion & otro);
	//
	// void CopiarDatos (const Objeto3D & otro);
};
#endif
