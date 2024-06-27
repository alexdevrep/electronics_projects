#include <ESP8266WiFi.h>

//Inicializamos las variables con el nombre y contraseña de nuestra red
const char* ssid = "mi_AP";
const char* password = "mi_password";

const int numero = 2;

void setup() {
  // inicializamos el Access Point
  Serial.begin(115200);
  WiFi.softAP(ssid,password);

  //Inicializamos el pin del LED 
  pinMode(LED_BUILTIN , OUTPUT);
  

}

void loop() {
  // Obtenemos el número de dispositivos conectados (máximo 4)
  int dispositivos = WiFi.softAPgetStationNum();

  /*
   * Encendemos un el LED que incorpora la placa cuando todos 
   * los dispositivos se conectan a la red
   */
  if(dispositivos == numero){
    digitalWrite(LED_BUILTIN, LOW);
    
  }
  else{
    digitalWrite(LED_BUILTIN, HIGH);
    
  }
  delay(5000);

}
