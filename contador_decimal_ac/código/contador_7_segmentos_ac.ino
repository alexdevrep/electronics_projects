/*
  Contador decimal usando el integrado 74HC595 y un display de 7 segmentos

  Este programa nos permite mostrar el valor decimal de una variable en un
  display de 7 segmentos usando el integrado 74HC595 controlado por dos botones
  que suman o restan una unidad a la variable de control (i)

  Autor: Alexdevrep
  Fecha: 24/3/2024
  Más contenido interesante en :
    -GitHub: https://www.github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -Mi blog de Wordpress: https://www.eltallerdealexdevrep.000webhostapp.com/
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA

*/

//Definimos los pines de control
#define SER 7
#define RCLK 8
#define SRCLK 9

//Definimos un valor de peso en bits a los led
#define LED0 1
#define LED1 2
#define LED2 4
#define LED3 8
#define LED4 16
#define LED5 32
#define LED6 64


/*
  Creamos la combinación de leds que forman los números decimales en nuestro display
  ver documentación completa ya que puede variar en función de como hayas conectado 
  las salidas del integrado con los ánodos o cátodos del display.
*/

#define numero0 LED6
#define numero1 LED0 + LED3 + LED4 + LED5 + LED6 
#define numero2 LED2 + LED5
#define numero3 LED4 + LED5
#define numero4 LED0 + LED3 + LED4
#define numero5 LED1 + LED4
#define numero6 LED1
#define numero7 LED3 + LED4 + LED5 + LED6
#define numero9 LED4
#define error   LED1 + LED2

//Inicializamos las variables necesarias
int i = 0;
const int botonSuma= 11;
const int botonResta= 12;

void setup() {

//Definimos los pines de entrada y salida
pinMode(SER, OUTPUT);
pinMode(RCLK, OUTPUT);
pinMode(SRCLK, OUTPUT);
pinMode(botonSuma,INPUT);
pinMode(botonResta,INPUT);

//Inicializamos el valor del display a 0 (por defecto)
digitalWrite(RCLK, LOW);
shiftOut(SER,SRCLK,MSBFIRST,numero0); //MSBFIRST= Bit más significante primero
digitalWrite(RCLK, HIGH);

}

// Función que controla la salida del integrado
void escribirNumeros(int i){
  switch(i){
    case 0:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero0); 
      digitalWrite(RCLK, HIGH);
      break;
    case 1:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero1);
      digitalWrite(RCLK, HIGH);
      break;
    case 2:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero2);
      digitalWrite(RCLK, HIGH);
      break;
    case 3:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero3);
      digitalWrite(RCLK, HIGH);
      break;
    case 4:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero4);
      digitalWrite(RCLK, HIGH);
      break;
    case 5:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero5);
      digitalWrite(RCLK, HIGH);
      break;
    case 6:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero6);
      digitalWrite(RCLK, HIGH);
      break;
    case 7:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero7);
      digitalWrite(RCLK, HIGH);
      break;
    case 8:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,LOW);
      digitalWrite(RCLK, HIGH);
      break;
    case 9:
      digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,numero9);
      digitalWrite(RCLK, HIGH);
      break;
  }
}

void loop() {
  // Bucle principal de control

  //Sumamos una unidad a la variable
  if (digitalRead(botonSuma) == HIGH && i<10  ){
    i++;
    escribirNumeros(i);
    delay(250);
  }

  //Restamos una unidad a la variable
  if(digitalRead(botonResta) == HIGH && i>-1){
    i--;
    escribirNumeros(i);
    delay(250);
  }

  //Mostramos el mensaje de error E
  if (i>9 || i<0) {
    digitalWrite(RCLK, LOW);
      shiftOut(SER,SRCLK,MSBFIRST,error); 
      digitalWrite(RCLK, HIGH);

  }

}
