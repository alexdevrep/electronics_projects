/*
  Programa Arduino para controlar un LED mediante comunicación serial.

  Este programa espera recibir un carácter desde la comunicación serial
  a través del puerto USB. Si recibe '1', enciende el LED incorporado en
  la placa de Arduino. Si recibe '0', apaga el LED.

  Conexiones:
  - LED incorporado en el pin LED_BUILTIN (pin 13 en la mayoría de las placas).

  Autor: Alexdevrep
  Fecha: 01/03/2024
  Más contenido interesante en:
    -Github: https://github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -WordPress: https://eltallerdealexdevrep.com
*/
void setup()
{
  // Iniciamos la comunicación Serial
  Serial.begin(9600);
  /*
    Declaramos el Led como salida en este caso usaremos el que
    ya viene en nuestra placa de arduino
  */
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {                              // Comprobamos si hay datos disponibles para ser leidos
    char option = Serial.read(); // Leemos los datos recibidos
    if (option == '1')
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (option == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
