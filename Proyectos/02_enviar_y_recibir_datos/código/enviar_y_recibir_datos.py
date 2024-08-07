'''
  Script en python para controlar un LED mediante una resistencia LDR.

  Este programa nos permite controlar el estado de un LED mediante la lectura
  e interpretación de los valores recibidos por una LDR, esto es un ejemplo
  básico donde el pricipal objetivo es el de poder enviar y recibir datos 
  del arduino a través del puerto serie

  Autor: Alexdevrep
  Fecha: 10/03/2024
  Más contenido interesante en:
    -Github: https://github.com/alexdevrep
    -Instagram: https://www.instagram.com/alexdevrep/
    -WordPress: https://eltallerdealexdevrep.com
    -Youtube: https://www.youtube.com/channel/UCNlqgVY-CaQ2Lgc5xJChaKA
'''





#Importamos las librerías necesarias
import serial
import time

# Iniciamos la conexión serial con el Arduino
arduino = serial.Serial('/dev/ttyACM0', 9600)  

# Esperamos para que el Arduino se inicialice
time.sleep(2)


#Definimos la estructura de control de nuestro programa
while True:
    #Declaramos la función que se encargará de enviar los datos al arduino
    def sensor(value):
        if value <20:
            arduino.write(b'1')
        elif value>20:
            arduino.write(b'0')
    
    # Esperamos a recibir datos del Arduino
    if arduino.in_waiting > 0:
        value = arduino.readline().decode('utf-8').strip()
        value=int(value)
        sensor(value) # Llamamos a la función previamente definida

    time.sleep(1)  # Esperamos un segundo antes de enviar el próximo dato

    #Definimos la condición de salida del bloque
    if value == 0:
        print("No hay datos sufiencientes, cerrando el programa")
        break

# Cerramos la comunicación serial con el arduino
arduino.close()
