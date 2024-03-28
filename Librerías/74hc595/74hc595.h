/*
  Archivo HC595CC.h
  Este archivo contiene la declaración de la clase HC595CC y la clase HC595CA, 
  que proporciona funcionalidades para controlar un display de 7 segmentos 
  con cátodo común y ánodo común respectivamente mediante un registro de 
  desplazamiento 74HC595.
  
  Autor: Alexdevrep
  Fecha: 28/03/2024
  Más contenido interesante en :
    -GitHub: https://www.github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -Mi blog de Wordpress: https://www.eltallerdealexdevrep.000webhostapp.com/
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA
*/

#ifndef HC595_H
#define HC595_H
#include <Arduino.h>

//Definimos el peso de los leds en bits
#define LED0 1
#define LED1 2
#define LED2 4
#define LED3 8
#define LED4 16
#define LED5 32
#define LED6 64

//Definimos la combinaciones de led que se van  a poner a nivel alto
const byte CC_numero0 = LED0 + LED1 + LED2 + LED3 + LED4 + LED5; 
const byte CC_numero1 = LED1 + LED2 ;
const byte CC_numero2 = LED0 + LED1 + LED6 + LED4 + LED3;
const byte CC_numero3 = LED0 + LED1 + LED2 + LED3 + LED6;
const byte CC_numero4 = LED1 + LED2 + LED5 + LED6;
const byte CC_numero5 = LED0 + LED2 + LED3 + LED5 + LED6;
const byte CC_numero6 = LED0 + LED2 + LED3 + LED4 + LED5 + LED6;
const byte CC_numero7 = LED0 + LED1 + LED2;
const byte CC_numero8 = LED0 + LED1 + LED2 + LED3 + LED4 + LED5 + LED6;
const byte CC_numero9 = LED0 + LED1 + LED2 + LED3 + LED5 + LED6;
const byte CC_error   = LED0 + LED3 + LED4 + LED5 + LED6;

//Definimos la combinaciones de led que se van  a poner a nivel bajo
const byte AC_numero0 = ~(LED0 + LED1 + LED2 + LED3 + LED4 + LED5); 
const byte AC_numero1 = ~(LED1 + LED2);
const byte AC_numero2 = ~(LED0 + LED1 + LED6 + LED4 + LED3);
const byte AC_numero3 = ~(LED0 + LED1 + LED2 + LED3 + LED6);
const byte AC_numero4 = ~(LED1 + LED2 + LED5 + LED6);
const byte AC_numero5 = ~(LED0 + LED2 + LED3 + LED5 + LED6);
const byte AC_numero6 = ~(LED0 + LED2 + LED3 + LED4 + LED5 + LED6);
const byte AC_numero7 = ~(LED0 + LED1 + LED2);
const byte AC_numero8 = ~(LED0 + LED1 + LED2 + LED3 + LED4 + LED5 + LED6);
const byte AC_numero9 = ~(LED0 + LED1 + LED2 + LED3 + LED5 + LED6);
const byte AC_error   = ~(LED0 + LED3 + LED4 + LED5 + LED6);

//Clase para displays de cátodo común
class HC595CC {
public:
    HC595CC(int serPin, int rclkPin, int srclkPin);
    //Definimos los métodos de la clase
    void begin();
    void escribirNumero(int numero);
    void error(const byte CC_error);

private:
    int _serPin;
    int _rclkPin;
    int _srclkPin;
    
};

//Clase para displays de ánodo común

class HC595CA {
public:
    HC595CA(int serPin, int rclkPin, int srclkPin);
    //Definimos los métodos de la clase
    void begin();
    void escribirNumero(int numero);
    void error(const byte AC_error);

private:
    int _serPin;
    int _rclkPin;
    int _srclkPin;
      
};

#endif

