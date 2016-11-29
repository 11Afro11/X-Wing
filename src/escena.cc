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

    rotar2 = 0;
    shoot = 0;
    tapa = 0;
    base = 0;
    timer = 0;
    velAla = velR2giro = velR2ejec = velShoot = velMov = 1;

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

    // if(rotar2 < 0){
    //   xwing.SetAngulo(rotar2);
    //   rotar2--;
    //   if(rotar2 < -20){
    //     rotar2 = 0;
    //   }
    //   return 0;
    // }

    unsigned char Tecla = toupper(Tecla1);

    switch(Tecla){

    	case 'Q': return 1;


      case 'W': //palante
  			xwing.moveFoward(velMov);
  			return 0;

      case 'S': //patras
  			xwing.moveBack(velMov);
  			return 0;

    // case 'V': //patras
    //
		// 	xwing.Volver();
    //
		// 	return 0;

    case 'D': //derecha
      shoot-=2;
      xwing.turnRight(velMov);

      return 0;

    case 'A': //izquierda

      xwing.turnLeft(velMov);

      return 0;

    case 'P': //rotate r2

    if(rotar2 == 0){
      numAnimacion = 6;
      rotar2 = 1;
    }
    else{
      numAnimacion = 0;
      rotar2 = 0;
    }

      return 0;


    case 'O': //eject

      numAnimacion = 4;
			// xwing.Ejecta();

			return 0;
    case 'I': //new R2

      numAnimacion = 5;
			// xwing.Nuevo();

			return 0;

    case 'Y': //animation

      numAnimacion = 7;
			// xwing.Nuevo();

			return 0;

    case 'Z': //shoot
      if(shoot == 0){
        numAnimacion = 3;
        shoot = 1;
      }
      else{
        numAnimacion = 0;
        xwing.disparado();
        shoot = 0;
      }

			return 0;

    case 'M': //close wing

      numAnimacion = 1;
      if(shoot == 1){
        xwing.disparado();
        shoot = 0;
      }
			// xwing.SetAngulo(1);

			return 0;

    case 'N'://open wing

      numAnimacion = 2;
      if(shoot == 1){
        xwing.disparado();
        shoot = 0;
      }
			// xwing.SetAngulo(-1);

			return 0;

    case 'R': //aumenta animacion general
      velAla = velAla*2;
      velShoot = velShoot*2;
      velR2ejec = velR2ejec*2;
      velMov = velMov*2;
      velR2giro = velR2giro*2;
    return 0;

    case 'T': //disminuye animacion general
      velAla = velAla/2;
      velShoot = velShoot/2;
      velR2ejec = velR2ejec/2;
      velMov = velMov/2;
      velR2giro = velR2giro/2;
    return 0;

    case 'F': //aumenta animacion ala
      velAla = velAla*2;
    return 0;

    case 'G': //disminuye animacion ala
      velAla = velAla/2;
    return 0;

    case 'C': //aumenta animacion movimiento
      velMov = velMov*2;
    return 0;

    case 'V': //disminuye animacion movimiento
      velMov = velMov/2;
    return 0;

    case 'B': //aumenta animacion disparo
      velShoot = velShoot*2;
    return 0;

    case 'H': //disminuye animacion disparo
      velShoot = velShoot/2;
    return 0;

    case 'U': //aumenta animacion rotacion
      velR2giro = velR2giro*2;
    return 0;

    case 'J': //disminuye animacion rotacion
      velR2giro = velR2giro/2;
    return 0;
    case 'K': //aumenta animacion ejeccion
      velR2ejec = velR2ejec*2;
    return 0;

    case 'L': //disminuye animacion ejeccion
      velR2ejec = velR2ejec/2;
    return 0;

    case '7':
      xwing.SetDibMode(0);
    return 0;

    case '8':
      xwing.SetDibMode(1);
    return 0;

    case '9':
      xwing.SetDibMode(2);
    return 0;

    case '4':
      xwing.SetDibMode(3);
    return 0;

    case '5':
      xwing.SetDibMode(5);
    return 0;



		default: return 0;



    }
}

void Escena::Animar(){
  dibujar();
  switch(numAnimacion){
    case 1:
      xwing.SetAngulo(velAla);
      if(xwing.cerrada())
        numAnimacion = 0;
    break;
    case 2:
      xwing.SetAngulo(-velAla);
      if(xwing.abierta())
        numAnimacion = 0;
    break;

    case 3:
      xwing.Disparar(velShoot);
    break;

    case 4:
      xwing.Ejecta(velR2ejec);
      if(xwing.limite()){
        xwing.Nuevo();
        numAnimacion = 0;
      }
    break;
    case 5:
      xwing.Ejecta(velR2ejec);
      if(xwing.posicion()){
        numAnimacion = 0;
      }
    break;
    case 6:
      xwing.moveR2(velR2giro);
    break;

    case 7:
      if(timer >= 0 and timer <= 20 or timer > 50 and timer <= 70){
        xwing.moveFoward(velMov);
        timer++;
      }
      if(timer > 20 and timer <= 50){
        xwing.turnLeft(velMov);
        timer++;
      }
      if(timer > 70 and timer <= 120){
        xwing.Disparar(velShoot);
        timer++;
      }
      if(timer > 120 and timer <= 140){
        xwing.disparado();
        shoot = 0;
        xwing.SetAngulo(-velAla);
        timer++;
      }
      if(timer > 140){
        timer = 0;
        // numAnimacion = 0;
      }
    default: break;

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
