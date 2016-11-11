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

    // Ply xwing("./ply/xwin.ply");
    // obj.push_back(xwing);
    // Ply cabina("./ply/Cabina.ply");
    // obj.push_back(cabina);
    // Ply cabinaHierro("./ply/CabinaHierro.ply");
    // obj.push_back(cabinaHierro);
    // Ply puntita("./ply/Puntita.ply");
    // obj.push_back(puntita);
    // Ply wing("./ply/wing.ply");
    // obj.push_back(wing);
    // Ply cosarara("./ply/CosaRara.ply");
    // obj.push_back(cosarara);
    // Ply cosatrasera("./ply/CosaDeAtras.ply");
    // obj.push_back(cosatrasera);
    // Ply r2d2("./ply/R2D2.ply");
    // obj.push_back(r2d2);


    // Body cuerpo;
    // obj.push_back(cuerpo);


    // for(int i = 0; i < obj.size(); i++){
    //   obj[i].BoundingBox();
    // }
    // cuerpo.BoundingBox();



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
  cuerpo.Dibujar(mode,col);
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



    unsigned char Tecla = toupper(Tecla1);

    // if(Tecla != 'Z'){
    // 	obj.DisableCullFace();
    // 	mitad = 0;
    // }
    // if(mitad == 0) obj.DisableCullFace();
    // else if(mitad == 1) obj.EnableCullFace();



    switch(Tecla){

    	case 'Q': return 1;



    	// case 'N':
    	// 	indice++;
      //   bool cond;
      //   if(flag == 0)cond = indice > obj.size()-1;
      //   else cond = indice > objr.size()-1;
    	// 	if(cond){
		  //   	indice = 0;
      //     if(flag == 0)
      //       flag = 1;
      //     else
      //       flag = 0;
		  //   }
    	// 	return 0;
    	// case 'B':
    	// 	indice--;
      //   int pos;
      //   if(flag == 0)pos = objr.size()-1;
      //   else pos = obj.size()-1;
    	// 	if(indice < 0){
		  //   	indice = pos;
      //     if(flag == 0)
      //       flag = 1;
      //     else
      //       flag = 0;
		  //   }
    	// 	return 0;



    	case 'L': //lineas

			mode = 1;

			return 0;



		case 'S': //solido

			mode = 0;

			return 0;



		case 'D': //punto

			mode = 2;

			return 0;

		case 'A': //ajedrez

			mode = 3;

			return 0;



		// case 'V': //varicolor
    //
		// 	mode = 4;
    //
		// 	return 0;
    //
		// case 'M': //Cambiacolor
    //
		// 	mode = 0;
		// 	col = obj[0].CambiaColor();
    //
		// 	return 0;
    //
    // case 'X': //Cambiacolor
    //   objr[indice].Resize(1);
    //   objr[indice].BoundingBox();
    //
		// 	return 0;
    //
    // case 'Z': //Cambiacolor
    //   objr[indice].Resize(0);
    //   objr[indice].BoundingBox();
    //
		// 	return 0;
    //
    // case 'T': //Cambiacolor
    //
    //   objr[indice].ConSinTapa(tapa);
    //   objr[indice].BoundingBox();
    //   if(tapa == 0)
    //     tapa = 1;
    //   else
    //     tapa = 0;
    //   return 0;
    //
    // case 'Y': //Cambiacolor
    //
    //   objr[indice].ConSinBase(base);
    //   objr[indice].BoundingBox();
    //   if(base == 0)
    //     base = 1;
    //   else
    //     base = 0;
    //   return 0;



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
