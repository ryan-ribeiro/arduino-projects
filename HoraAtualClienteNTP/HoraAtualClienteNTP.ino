#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <NTPClient.h> //https://github.com/taranais/NTPClient
#include <WiFiUdp.h>

const char* ssid = "Danilo";
const char* password = "qwer@123";

WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Conectando no WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConectado!\n");

  ntp.begin();

  //GMT em segundos
  // +1 = 3600
  // +8 = 28800
  // -1 = -3600
  // -3 = -10800 (BRASIL)
  ntp.setTimeOffset(-10800);
}

void loop() {
  ntp.update();
  Serial.println(ntp.getFormattedTime());
}
