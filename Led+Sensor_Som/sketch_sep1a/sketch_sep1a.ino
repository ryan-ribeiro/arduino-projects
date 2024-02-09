#include <Wire.h>

const int sampleWindow = 200;  // Aumentar a janela de amostragem
unsigned int sample;

#define SENSOR_PIN 35
#define PIN_QUIET 33     // Green LED
#define PIN_MODERATE 25  // Yellow LED
#define PIN_LOUD 26      // Red LED

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(PIN_QUIET, OUTPUT);
  pinMode(PIN_MODERATE, OUTPUT);
  pinMode(PIN_LOUD, OUTPUT);

  digitalWrite(PIN_QUIET, LOW);
  digitalWrite(PIN_MODERATE, LOW);
  digitalWrite(PIN_LOUD, LOW);

  Serial.begin(115200);
}

void loop() {
  unsigned long startMillis = millis();
  float peakToPeak = 0;
  unsigned int signalMax = 0;  // Inicialize com 0
  unsigned int signalMin = 1024;  // Inicialize com 1024

  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(SENSOR_PIN);

    // Verifique se o valor é válido
    if (sample < 1024) {
      if (sample > signalMax) {
        signalMax = sample;
      }
      if (sample < signalMin) {
        signalMin = sample;
      }
    }
  }

  peakToPeak = signalMax - signalMin;
  int db = map(peakToPeak, 0, 900, 49, 90);
  Serial.print("\t");
  Serial.println(db);
  digitalWrite(PIN_LOUD, LOW);

  if (db <= 55) {
    digitalWrite(PIN_QUIET, HIGH);
    digitalWrite(PIN_MODERATE, LOW);
    digitalWrite(PIN_LOUD, LOW);
    // delay(3000);
  } else if (db > 60 && db < 85) {
    digitalWrite(PIN_QUIET, LOW);
    digitalWrite(PIN_MODERATE, HIGH);
    digitalWrite(PIN_LOUD, LOW);
  } else if (db >= 85 && db <= 90) {
    digitalWrite(PIN_QUIET, LOW);
    digitalWrite(PIN_MODERATE, LOW);
    digitalWrite(PIN_LOUD, HIGH);
  } else {
    digitalWrite(PIN_QUIET, LOW);
    digitalWrite(PIN_MODERATE, LOW);
    digitalWrite(PIN_LOUD, LOW);
  }

  delay(200);
}
