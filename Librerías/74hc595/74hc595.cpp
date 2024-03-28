/*
  Archivo HC595CC.cpp
  Este archivo contiene la implementación de la clase HC595CC y la clase HC595CA, 
  que proporciona funcionalidades para controlar un display de 7 segmentos 
  con cátodo común y ánodo común respectivamente mediante un 
  registro de desplazamiento 74HC595.
  
  Autor: Alexdevrep
  Fecha: 28/03/2024
  Más contenido interesante en :
    -GitHub: https://www.github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -Mi blog de Wordpress: https://www.eltallerdealexdevrep.000webhostapp.com/
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA
*/

#include "74hc595.h"

//Instanciamos la clase HC595CC (Cátodo común)
HC595CC::HC595CC(int serPin, int rclkPin, int srclkPin) {
    _serPin = serPin;
    _rclkPin = rclkPin;
    _srclkPin = srclkPin;
}

//Instanciamos la clase HC595CA (Ánodo común)
HC595CA::HC595CA(int serPin, int rclkPin, int srclkPin) {
    _serPin = serPin;
    _rclkPin = rclkPin;
    _srclkPin = srclkPin;
}

//Métodos de la clase HC595CC
//Método begin para displays de cátodo común
void HC595CC::begin() {
    pinMode(_serPin, OUTPUT);
    pinMode(_rclkPin, OUTPUT);
    pinMode(_srclkPin, OUTPUT);
    digitalWrite(_rclkPin, LOW);
    shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero0);
    digitalWrite(_rclkPin, HIGH);
}

//Método escribirNumero() para displays de cátodo común
void HC595CC::escribirNumero(int numero) {
    switch (numero) {
        case 0:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero0);
            digitalWrite(_rclkPin, HIGH);
            break;
        case 1:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero1);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 2:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero2);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 3:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero3);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 4:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero4);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 5:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero5);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 6:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero6);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 7:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero7);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 8:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero8);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 9:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, CC_numero9);
            digitalWrite(_rclkPin, HIGH);
            break;
    }
}
//Método error para mostrar el mensaje E cuando numero sea mayor de 9 o menor que 0
void HC595CC::error(const byte CC_error) {
    digitalWrite(_rclkPin, LOW);
    shiftOut(_serPin, _srclkPin, MSBFIRST, CC_error);
    digitalWrite(_rclkPin, HIGH);
}

//Métodos de la clase HC595CA
//Método begin para displays de ánodo común
void HC595CA::begin() {
    pinMode(_serPin, OUTPUT);
    pinMode(_rclkPin, OUTPUT);
    pinMode(_srclkPin, OUTPUT);
    digitalWrite(_rclkPin, LOW);
    shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero0);
    digitalWrite(_rclkPin, HIGH);
}

//Métoto escribirNumero para displays de ánodo común
void HC595CA::escribirNumero(int numero) {
    switch (numero) {
        case 0:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero0);
            digitalWrite(_rclkPin, HIGH);
            break;
        case 1:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero1);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 2:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero2);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 3:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero3);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 4:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero4);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 5:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero5);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 6:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero6);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 7:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero7);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 8:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero8);
            digitalWrite(_rclkPin, HIGH);
            break;
       case 9:
            digitalWrite(_rclkPin, LOW);
            shiftOut(_serPin, _srclkPin, MSBFIRST, AC_numero9);
            digitalWrite(_rclkPin, HIGH);
            break;
    }
}

//Método error para mostrar el mensaje E cuando numero sea mayor de 9 o menor que 0
void HC595CA::error(const byte AC_error) {
    digitalWrite(_rclkPin, LOW);
    shiftOut(_serPin, _srclkPin, MSBFIRST, AC_error);
    digitalWrite(_rclkPin, HIGH);
}


   

