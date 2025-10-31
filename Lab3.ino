//Laboratorio 3 SISTEMAS EMBEBIDOS. PULL UP Y PULL DOWN
int opcion;
int sensorVal;

void setup() {
  Serial.begin(9600);
  Serial.println("Selecciona una opción:");
  Serial.println("1. Pull-up");
  Serial.println("2. Pull-down");

  // Esperar a que el usuario ingrese una opción en el monitor serial
  while (Serial.available() == 0) {
    // Espera activa hasta que se reciba un dato
  }

  // Leer la opción
  opcion = Serial.parseInt();
  Serial.print("Opción elegida: ");
  Serial.println(opcion);

  // Configurar según la opción elegida
  switch (opcion) {
    case 1:
      Serial.println("Modo: PullUP");
      pinMode(2, INPUT_PULLUP);
      break;

    case 2:
      Serial.println("Modo: PullDown");
      pinMode(2, INPUT);
      break;

  }

  pinMode(13, OUTPUT);
}

void loop() {
  // Leer el valor del pin 2
  sensorVal = digitalRead(2);

  switch (opcion) {
    case 1:
      // Modo PullUP
          if (sensorVal == HIGH) {
              digitalWrite(13, HIGH);          
          }  
          else if(sensorVal != HIGH) {
              digitalWrite(13, LOW);
  } 
    break;

    case 2:
      // Modo Pull-down 
          if (sensorVal == LOW) {
               digitalWrite(13, LOW);
    
          }    
           else if (sensorVal == HIGH){
               digitalWrite(13, HIGH);
          }
    break;
  }
  Serial.println(sensorVal);
}
//este PULL DOWN del diaaablo 
//Lol

