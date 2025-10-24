/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/
*/
const int pinLM35 = A0;

const int ledVerde = 13;
const int ledAmarillo = 12;
const int ledRojo = 11;

float temperatura;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("LM35 + LEDs - Indicador de temperatura");

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int lecturaADC = analogRead(pinLM35);
  float voltaje = lecturaADC * (5.0 / 1023.0);
  temperatura = voltaje / 0.01;

  Serial.print("Voltaje: ");
  Serial.println(voltaje);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C  ");

//LED VERDE
if(temperatura >= 15 && temperatura <= 25){ 
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
}
//led amarillo
else if(temperatura > 25 && temperatura <= 35){ 
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, HIGH);
  digitalWrite(ledRojo, LOW);
}

//led rojo
else if(temperatura >= 36){ 
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, HIGH);
}

else {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
}

  delay(1000);  // delay in between reads for stability
}

//verde, amarillo y rojo
//nuestro contacto fisico afecta al LM35 afecta nuestra temperatura

