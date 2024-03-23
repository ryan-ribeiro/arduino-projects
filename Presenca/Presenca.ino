int PIR = 5;
int LeituraPIR = 0;
int Led = 8;

void setup() {
  Serial.begin(115200);
  pinMode(PIR, INPUT);

}

void loop() {
  LeituraPIR = digitalRead(PIR);

  if(LeituraPIR == 1) {
    digitalWrite(Led, HIGH);
  }
  delay(5000);
  digitalWrite(Led, LOW);

}
