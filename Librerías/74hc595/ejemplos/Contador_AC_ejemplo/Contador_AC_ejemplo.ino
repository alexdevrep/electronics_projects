/*
  Ejemplo de uso de la librería 74hc595.h

  Este programa nos permite comprobar el correcto funcionamiento 
  de la librería 74hc595.h para controlar el comportamiento de un display 
  de 7 segmentos de ánodo común mediante el uso del integrado 74HC595, 
  en este ejemplo podemos ver todos los métodos disponibles para la 
  clase HC595CC.

  Autor: Alexdevrep
  Fecha: 28/3/2024
  Más contenido interesante en :
    -GitHub: https://www.github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -Mi blog de Wordpress: https://www.eltallerdealexdevrep.000webhostapp.com/
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA

*/

//Incluimos la librería necesaria
#include <74hc595.h>

//Declaramos las variables necesarias para el control del programa
int numero =0;
const int botonSuma = 11;
const int botonResta = 12;

//Creamos un objeto de la clase lo llamamos display y lo inicializamos con los valores 7,8 y 9
HC595CA display(7, 8, 9); // Pines SER, RCLK, SRCLK

void setup() {
  //Inicializamos los pines de entrada y la librería
  pinMode(botonSuma, INPUT);
  pinMode(botonResta, INPUT);
  display.begin();
  //Definimos que al inicializar el programa se nos muestre el número 0 en el display
  display.escribirNumero(AC_numero0);
}

void loop() {
  // Bucle principal de control

  //Sumamos una unidad a la variable
  if (digitalRead(botonSuma) == HIGH && numero<10){
    numero++;
    display.escribirNumero(numero);
    delay(250);
  }

  //Restamos una unidad a la variable
  if(digitalRead(botonResta) == HIGH && numero>-1){
    numero--;
    display.escribirNumero(numero);
    delay(250);
  }

  //Mostramos el mensaje de error E
  if (numero>9 || numero<0) {
   display.error(AC_error);

  }
  
}
