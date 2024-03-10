
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