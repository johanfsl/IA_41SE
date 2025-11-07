#include "DHT.h"

#define DHTPIN 4       // Pin del DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//Declaramos las variables
float humedad, temperatura; 
int sensorVal;
const int ledAzul = 13;
const int ledAmarillo = 12;
const int ledRojo = 11;
const int ledVerde = 8;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(2, INPUT_PULLUP);  
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  Serial.println(F("Presiona el botón para iniciar la medición..."));
}

void loop() {

  sensorVal = digitalRead(2); 
  //Es para la lectura de la compuerta logica (0 y 1)
  if (sensorVal != HIGH) {
              digitalWrite(8, HIGH);
  }  
      else if(sensorVal == HIGH) {
              digitalWrite(8, LOW);
      }   
  Serial.println(!sensorVal);


// Espera hasta que el botón sea presionado
  if (sensorVal != HIGH) {

    // Lectura de sensor
    humedad = dht.readHumidity();
    temperatura = dht.readTemperature();

    // Verificar si hay error
    if (isnan(humedad) || isnan(temperatura)) {
      Serial.println(F("Error al leer el sensor DHT11!"));
      return;
    }
  
    // Mostrar resultados
    Serial.print(F("Humedad: "));
    Serial.print(humedad);
    Serial.print(F("% | Temperatura: "));
    Serial.print(temperatura);
    Serial.println(F(" °C"));

   //LEDS
    if (temperatura >= 15 && temperatura <= 25) { 
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledAmarillo, LOW);
      digitalWrite(ledRojo, LOW);
    } 
    else if (temperatura >= 26 && temperatura <= 35) { 
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledAmarillo, HIGH);
      digitalWrite(ledRojo, LOW);
    } 
    else if (temperatura > 35) { 
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledAmarillo, LOW);
      digitalWrite(ledRojo, HIGH);
    }
   
  } 
  else {
    // Mientras no se presione el botón, no mide nada
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, LOW);
  } delay(2000); // Espera 2 segundos antes de nueva lectura
  
}


