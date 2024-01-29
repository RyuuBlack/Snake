#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

using namespace std;

void gotoxy(int x,int y){

    printf("%c[%d;%df",0x1B,y,x);

}


/*
  * * prioridad de tipo 1
  Función encargada de dibujar el mapa.

*/ 
void map(){

  int x = 2;
  int y = 4;
  int tamanoMapX = 134;
  int tamanoMapY = 30;


  //-----------------------------------------------------------------------

    // marco superior
  for(int i = 0 ; i <= tamanoMapX ; i++){
    gotoxy(x,y);
    printf("%c",205);
    x++;
  }

  //-----------------------------------------------------------------------

  // marco Derecho
  for(int i = 0 ; i <= tamanoMapY ; i++){
    gotoxy(x,y);
    printf("%c",186);
    y++;
  }

  //-----------------------------------------------------------------------

    // marco Izquierdo
  x = 2;
  y = 4;

  for(int i = 0 ; i <= tamanoMapY ; i++){
    gotoxy(x,y);
    printf("%c",186);
    y++;
  }

  //-----------------------------------------------------------------------

    // esquina superior iz

  x = 2;
  y = 4;

  gotoxy(x,y);
  printf("%c",201);

  //-----------------------------------------------------------------------

    // esquina superior der

  x = 3+ tamanoMapX;
  y = 4;

  gotoxy(x,y);
  printf("%c",187);

  //-----------------------------------------------------------------------

    // marco Inferior
  x = 2;
  y = tamanoMapY + 4;

  
  for(int i = 0 ; i <= tamanoMapX ; i++){
    gotoxy(x,y);
    printf("%c",205);
    x++;
  }

  //-----------------------------------------------------------------------

    // esquina inferior der

  x = 3 + tamanoMapX;
  y = tamanoMapY + 4;

  gotoxy(x,y);
  printf("%c",188);

  //-----------------------------------------------------------------------

    // esquina inferior iz

  x = 2;
  y = tamanoMapY + 4;

  gotoxy(x,y);
  printf("%c",200);

}


/*
  * prioridad de tipo 1
  Función encargada de mostrar la puntuación del jugador

*/
void score(int score){

  int x = 125;
  int y = 2;

  gotoxy(x,y);

  printf("Score : %d",score);
}


/*
  ! prioridad de tipo 2
  Funsión encargada de mover la serpiente

*/

void snake_move(){


  int x = 10; // posicion inicial de la serpiente en el eje X
  int y = 10; // posicion inicial de la serpiente en el eje Y

  int dirX = 1; // direccion inicial positiva en X
  int dirY = 1; // direccion inicial positiva en Y

  gotoxy(x,y);
  cout<<"*";

  char tecla; 

  while(x<=134 && x>=2 && y<=30 && y>=4){

    // kbhit() es una función que determina si se está precionando una tecla del teclado.
    if (kbhit()){
      
      tecla = getch(); // getch() determina que tecla se esta oprimiendo en el teclado.

    }

    gotoxy(x,y);
    cout<<" ";

    if ( tecla == 's'){

      dirY = 1;
      dirX = 0;

    } 

    if (tecla == 'a'){

      dirX = -1;
      dirY = 0;

    }

    if (tecla == 'd'){

      dirX=1;
      dirY = 0;

    }

    if (tecla == 'w'){

      dirX=0;
      dirY = -1;

    }

    if (dirY == 1){
      y++;
    }

    if (dirY == -1){
      y--;
    }

    if (dirX == 1){
      x=x+2;
    }

    if (dirX == -1){
      x=x-2;
    }

    gotoxy(x,y);
    
    cout<<"*";
    sleep(1); // agrega 1 segundo de espera
  }

}


/*
  * prioridad de tipo 1
  Función encargada de iniciar el juego.

*/
int main(){

  printf("\e[?25l"); // elimina el cursor
  system("clear"); // limpia la consola
  
  map(); // llamada a la funcion map

  int my_score = 3; // puntuación de ejemplo
  score(my_score); // llamada a la funcion score

  snake_move(); // llamada a la funcion snake_move

  cout <<"\n";
  system("pause>>null");
  return 0;

} 


