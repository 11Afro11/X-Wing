#ifdef _WIN32

#include <windows.h>

#endif

#include <cstdio>

#include <iostream>

#include <GL/gl.h>

#include <GL/glut.h>

#include "escena.h"

#include "math.h"







Escena::Escena(){

    Front_plane=50;

    Back_plane=2000;

    Observer_distance = 4*Front_plane;

    Observer_angle_x = Observer_angle_y=0;

    ejes.changeAxisSize(5000);

    indice = 0;
    flag = 0;
    tapa = 0;
    base = 0;

}



void Escena::inicializar(int UI_window_width,int UI_window_height) {



	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)



	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer



	this->change_projection();

	Width=UI_window_width/10;

	Height=UI_window_height/10;

	glViewport(0,0,UI_window_width,UI_window_height);



}





//**************************************************************************

// Funcion que dibuja objetos en la escena

//***************************************************************************

void Escena::draw_objects() {
  xwing.Dibujar(mode,col);
  // wing.Dibujar(mode, col);
}







void Escena::dibujar() {



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla

	change_observer();

	draw_axis();

	draw_objects();

}



int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {



    std::cout << "Tecla" << Tecla1<< std::endl;
    // std::cout << "Mitad" << mitad<< std::endl;
    // std::cout << "Culld" << obj.Say()<< std::endl;

    if(indice < 0){
      xwing.SetAngulo(indice);
      indice--;
      if(indice < -20){
        indice = 0;
      }
      return 0;
    }

    unsigned char Tecla = toupper(Tecla1);

    switch(Tecla){

    	case 'Q': return 1;


      case 'W': //palante

  			xwing.Mueve(0,0,2);

  			return 0;

      case 'S': //patras

  			xwing.Mueve(0,0,-2);

  			return 0;

    // case 'V': //patras
    //
		// 	xwing.Volver();
    //
		// 	return 0;

    case 'D': //derecha
      xwing.Rotar(2);

      return 0;

    case 'A': //izquierda

      xwing.Rotar(-2);

      return 0;

    case 'M': //palante

			xwing.SetAngulo(1);

			return 0;

    case 'N': //palante

			xwing.SetAngulo(-1);

			return 0;

    case 'P': //palante

			indice = -1;

			return 0;

    case 'L': //lineas

			mode = 1;

			return 0;



		case 'J': //solido

			mode = 0;

			return 0;



		case 'K': //punto

			mode = 2;

			return 0;

		case 'C': //ajedrez

			mode = 3;

			return 0;


		default: return 0;



    }
}



void Escena::teclaEspecial(int Tecla1,int x,int y) {

switch (Tecla1){

	case GLUT_KEY_LEFT:Observer_angle_y--;break;

	case GLUT_KEY_RIGHT:Observer_angle_y++;break;

	case GLUT_KEY_UP:Observer_angle_x--;break;

	case GLUT_KEY_DOWN:Observer_angle_x++;break;

	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;

	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;

	}



	//std::cout << Observer_distance << std::endl;

}





//**************************************************************************

// Funcion para definir la transformaci�n de proyeccion

//***************************************************************************



void Escena::change_projection()  {

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);

}





void Escena::redimensionar(int newWidth,int newHeight) {

change_projection();

Width=newWidth/10;

Height=newHeight/10;

glViewport(0,0,newWidth,newHeight);

}





//**************************************************************************

// Funcion para definir la transformaci�n de vista (posicionar la camara)

//***************************************************************************







void Escena::change_observer() {



// posicion del observador

glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

glTranslatef(0,0,-Observer_distance);

glRotatef(Observer_angle_x,1,0,0);

glRotatef(Observer_angle_y,0,1,0);

}





//**************************************************************************

// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas

//***************************************************************************



void Escena::draw_axis()

{

ejes.draw();

}
