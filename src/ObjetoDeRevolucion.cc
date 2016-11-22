#include "ObjetoDeRevolucion.h"
#include "math.h"
#include <iostream>
#include <cstdlib>

# define M_PI           3.14159265358979323846  /* pi */


ObjetoDeRevolucion::ObjetoDeRevolucion(char * cadena, int numerodiv, char ej):Objeto3D(){

	division = numerodiv;
	eje = ej;
	_file_ply ply;
	ply.open(cadena);
	std::vector<int> nulo;

	ply.read(inicial, nulo);
	CreaObjeto();
}

ObjetoDeRevolucion::ObjetoDeRevolucion(std::vector<GLfloat> vert, int numerodiv, char ej):Objeto3D(){
	division = numerodiv;
	eje = ej;
	for(int i =0; i < vert.size(); i++){
		inicial.push_back(vert[i]);
	}
	CreaObjeto();
}

void ObjetoDeRevolucion::CreaObjeto(){
	std::cout << "He llegado"<< std::endl;
	int tam = inicial.size();
	CalculaPuntos(tam);
	CarasLaterales();
	for(int i = 0; i < tapa.size(); i++){
		caras.push_back(tapa[i]);
	}
	for(int i = 0; i < base.size(); i++){
		caras.push_back(base[i]);
	}
}

void ObjetoDeRevolucion::CalculaPuntos(int tam){
	//declaramos el angulo y el vector auxiliar
	float alpha = 2*M_PI/division;
	GLfloat aux[3];

	//Comprobamos si el vector inicial esta en el orden correcto.
	bool normal;
	switch(eje){
		case 'y':
			normal = inicial[inicial.size()-2] > inicial[1];break;
		case 'x':
			normal = inicial[inicial.size()-3] < inicial[0];break;
		case 'z':
			normal = inicial[inicial.size()-1] < inicial[2];break;
	}

	if(!normal){
		std::vector<GLfloat> vert;
		for(int i = inicial.size()-1; i >= 0; i-=3){
			aux[0] = inicial[i-2];
			aux[1] = inicial[i-1];
			aux[2] = inicial[i];
			vert.push_back(aux[0]);
			vert.push_back(aux[1]);
			vert.push_back(aux[2]);
		}
		inicial.clear();
		for(int i = 0; i < vert.size(); i++){
			inicial.push_back(vert[i]);
		}
	}

	//calculamos la posicion inicial

	switch (eje) {
		case 'y':
			aux[0] = 0;
			aux[1] = inicial[1];
			aux[2] = 0;
			break;
		case 'x':
			aux[0] = inicial[0];
			aux[1] = 0;
			aux[2] = 0;
			break;
		case 'z':
			aux[0] = 0;
			aux[1] = 0;
			aux[2] = inicial[2];
			break;
	}


	if(NecesitoBase()){
		vertices.push_back(aux[0]);
		vertices.push_back(aux[1]);
		vertices.push_back(aux[2]);
	}
	int ini=0;
	int res = 0;
	if(!NecesitoBase()){
		ini = 3;
		vertices.push_back(inicial[0]);
		vertices.push_back(inicial[1]);
		vertices.push_back(inicial[2]);
	}
	if(!NecesitoTapa())
		res = 3;


	for(int i = ini; i < tam-res; i+=3){
		for(int j = 0; j <= division; j++){
			switch (eje) {
				case 'y':
					aux[0] = cos(alpha*j)*inicial[i] + sin(alpha*j)*inicial[i+2];
					aux[1] = inicial[i+1];
					aux[2] = -sin(alpha*j)*inicial[i] + cos(alpha*j)*inicial[i+2];
					break;
				case 'x':
					aux[0] = inicial[i];
					aux[1] = cos(alpha*j)*inicial[i+1] + sin(alpha*j)*inicial[i+2];
					aux[2] = -sin(alpha*j)*inicial[i+1] + cos(alpha*j)*inicial[i+2];
					break;
				case 'z':
					aux[0] = cos(alpha*j)*inicial[i] + sin(alpha*j)*inicial[i+1];
					aux[1] = -sin(alpha*j)*inicial[i] + cos(alpha*j)*inicial[i+1];
					aux[2] = inicial[i+2];
					break;
			}
			vertices.push_back(aux[0]);
			vertices.push_back(aux[1]);
			vertices.push_back(aux[2]);
		}
	}

	switch (eje) {
		case 'y':
			aux[0] = 0;
			aux[1] = inicial[tam-2];
			aux[2] = 0;
			break;
		case 'x':
			aux[0] = inicial[tam-3];
			aux[1] = 0;
			aux[2] = 0;
			break;
		case 'z':
			aux[0] = 0;
			aux[1] = 0;
			aux[2] = inicial[tam-1];
			break;
	}

	if(NecesitoTapa()){
		vertices.push_back(aux[0]);
		vertices.push_back(aux[1]);
		vertices.push_back(aux[2]);
	}
	else if(!NecesitoTapa()){
		vertices.push_back(inicial[inicial.size()-3]);
		vertices.push_back(inicial[inicial.size()-2]);
		vertices.push_back(inicial[inicial.size()-1]);
	}

	// glScalef(40,40,40);
	// for(int i = 0; i < vertices.size(); i++){
	// 	vertices[i] *= 40;
	// }

	// if(NecesitoBase())
		Base();
	// if(NecesitoTapa())
		Tapa();

}

void ObjetoDeRevolucion::CarasLaterales(){
	int parada = vertices.size()/3;
	int sum = 1;
	int res = 2;
	if(!NecesitoBase())
		sum = 0;
	if(!NecesitoTapa())
		res = 1;
	for(int i = sum; i+division < parada-res; i++){
		caras.push_back(i);
		caras.push_back(i+1);
		caras.push_back(i+division+1);

		caras.push_back(i);
		caras.push_back(i+division+1);
		caras.push_back(i+division);

	}
}

void ObjetoDeRevolucion::Base(){
	for(int i =1; i <= division; i++){
		base.push_back(i);
		base.push_back(0);
		base.push_back(i+1);

	}
}

void ObjetoDeRevolucion::Tapa(){
	int tamanio = vertices.size()/3;

	for(int i = tamanio -division-2; i < tamanio-1; i++){
		tapa.push_back(i);
		tapa.push_back(i+1);
		tapa.push_back(tamanio-1);
	}
}

bool ObjetoDeRevolucion::NecesitoTapa(){

	switch(eje){
		case 'y':
			if(inicial[inicial.size()-3] == 0 and inicial[inicial.size()-1] == 0 and inicial[inicial.size()-2] != 0){
				return false;
			}break;
		case 'x':
			if(inicial[inicial.size()-2] == 0 and inicial[inicial.size()-1] == 0 and inicial[inicial.size()-3] != 0){
				return false;
			}break;
		case 'z':
			if(inicial[inicial.size()-2] == 0 and inicial[inicial.size()-3] == 0 and inicial[inicial.size()-1] != 0){
				return false;
			}break;
			// for(int i = inicial.size()-2; i >= 0; i-=3){
			// 	if(inicial[i-1] == 0 and inicial[i+1] == 0 and inicial[i] != 0){
			// 		return false;
			// 	}
			// }
	}
	return true;
}
bool ObjetoDeRevolucion::NecesitoBase(){
	switch(eje){
		case 'y':
			if(inicial[0] == 0 and inicial[2] == 0 and inicial[1] != 0){
				return false;
			}break;
		case 'x':
			if(inicial[1] == 0 and inicial[2] == 0 and inicial[0] != 0){
				return false;
			}break;
		case 'z':
			if(inicial[1] == 0 and inicial[0] == 0 and inicial[2] != 0){
				return false;
			}break;

			// for(int i = 1; i < inicial.size(); i+=3){
			// 	if(inicial[i-1] == 0 and inicial[i+1] == 0 and inicial[i] != 0){
			// 		return false;
			// 	}
			// }
	}
	return true;
}

void ObjetoDeRevolucion::Resize(int value){
	std::cout << "Voy a redividir"<< std::endl;
	vertices.clear();
	caras.clear();
	tapa.clear();
	base.clear();
	if(value == 0){
		division -= 10;
	}
	else{
		division+=10;
	}
	CreaObjeto();
}

void ObjetoDeRevolucion::ConSinTapa(int cond){
	if(NecesitoTapa()){
		if(cond == 0){
			caras.clear();
			CarasLaterales();
			for(int i = 0; i < base.size(); i++){
				caras.push_back(base[i]);
			}
		}
		else{
			for(int i = 0; i < tapa.size(); i++){
				caras.push_back(tapa[i]);
			}
		}
	}
}
void ObjetoDeRevolucion::ConSinBase(int cond){
	if(NecesitoBase()){
		if(cond == 0){
			caras.clear();
			CarasLaterales();
			for(int i = 0; i < tapa.size(); i++){
				caras.push_back(tapa[i]);
			}
		}
		else{
			for(int i = 0; i < base.size(); i++){
				caras.push_back(base[i]);
			}
		}
	}
}
