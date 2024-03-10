//Definimos el pin de entrada e inicialñizamos su valor
int sensorLDR = A0; 
int sensorValue = 0;

void setup() {
  //Inicializamos la comunicación serial 
  Serial.begin(9600);
  //Declaramos el pin 2 como salida
  pinMode(2, OUTPUT); 
}

void loop() {
  //Leemos los datos del sensor y los guardamos en una variable
  sensorValue= analogRead(sensorLDR);
  //Imprimimos esos datos en el monitor serie y son enviados al script de python
  Serial.println(sensorValue);
  delay(1000);
  // Comprobamos si hay datos disponibles para leer
  if (Serial.available() > 0) { 
    char receivedChar = Serial.read(); // Leemos el dato recibido

    if (receivedChar == '1'){
      digitalWrite(2,HIGH);

    }
    else if (receivedChar == '0'){
      digitalWrite(2,LOW);
    }
    
  }

 
}
