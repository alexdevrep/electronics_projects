'''
  Script en python para controlar un LED mediante comunicación serial.

  Este programa nos permite dar instrucciones a la terminal 
  y lo envía por USB a través de lacomunicación serial.
  Si escribimos '1' enciende el LED incorporado en la placa de Arduino. 
  Si escribimos '0' apaga el LED incorporado en la placa de Arduino.
  Si escribimos 'SALIR' finaliza el programa y se cierra la comunicación.

  Autor: Alexdevrep
  Fecha: 01/03/2024
  Más contenido interesante en:
    -Github: https://github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
'''

#Importamos las librerías necesarias para poder conectarnos con arduino 
import serial
import time

#Guardamos en una variable los datos de nuestra conexión con arduino 
arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

#Creamos la estructura de control necesaria para el programa
while True:
    def toogle(key):
        if key == '1':
            arduino.write(b'1') #Enviamos al arduino los datos en bytes (b)
        elif key == '0':
            arduino.write(b'0')
        elif key == 'SALIR':
            print("Cerrando el terminal, programa finalizado.")
        
       
    #Creamos un input en el que nosotros le pasamos el valor deseado al programa
    toogle_key=input("Por favor indique que quiere hacer con el LED: ")
    toogle(toogle_key)
    
    #Creamos la condición de Salida al bucle while
    if toogle_key == 'SALIR': 
        break
#Cerramos la comunicación con Arduino
arduino.close()
