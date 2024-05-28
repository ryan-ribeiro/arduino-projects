int buttonState = 0;
int buttonPin = 11;

int cont = 0;
int dezenaSegundo = 0;

void setup() {

  // pinos das unidades do segundo (X0, X1, X2, X3, ... X9)
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  // pinos das dezenas do segundo (0X, 1X, 2X, 3X, ... 6X)
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);

  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState) {
    display();
  }
}

void display(void) {

  if(cont == 0) {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);

    displayDezenaSegundo();

    delay(100);
  }

  if(cont == 1) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);

    delay(1000);
  }

  if(cont == 2) {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);

  delay(1000);
  }

  if(cont == 3) {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);

  delay(1000);
  }

  if(cont == 4) {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  delay(1000); 
  }

  if(cont == 5) {
  digitalWrite(2,LOW);


  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  delay(1000); 
  }

  if(cont == 6) {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  delay(1000); 
  }

  if(cont == 7) {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);

  delay(1000); 
  }

  if(cont == 8) {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000); 
  }

  if(cont == 9) {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  cont = -1;
  dezenaSegundo++;

  delay(1000);
  }
  cont++;
}



void displayDezenaSegundo(void) {
  if(dezenaSegundo == 0) {
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      digitalWrite(27,LOW);
      digitalWrite(28,HIGH);
      
      delay(1000);
    }

    if(dezenaSegundo == 1) {
      digitalWrite(22,HIGH);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,HIGH);
      digitalWrite(26,HIGH);
      digitalWrite(27,HIGH);
      digitalWrite(28,HIGH);

      delay(1000);
    }

    if(dezenaSegundo == 2) {
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,HIGH);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      digitalWrite(27,HIGH);
      digitalWrite(28,LOW);

      delay(1000);
    }

    if(dezenaSegundo == 3) {
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,HIGH);
      digitalWrite(27,HIGH);
      digitalWrite(28,LOW);

      delay(1000);
    }

    if(dezenaSegundo == 4) {
      digitalWrite(22,HIGH);
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,HIGH);
      digitalWrite(26,HIGH);
      digitalWrite(27,LOW);
      digitalWrite(28,LOW);

      delay(1000); 
    }

    if(dezenaSegundo == 5) {
      digitalWrite(22,LOW);
      digitalWrite(23,HIGH);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,HIGH);
      digitalWrite(27,LOW);
      digitalWrite(28,LOW);

      delay(1000); 
    }

    if(dezenaSegundo == 6) {
      digitalWrite(22,LOW);
      digitalWrite(23,HIGH);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
      digitalWrite(27,LOW);
      digitalWrite(28,LOW);

      dezenaSegundo = 0;
      cont = 0;
      
      delay(1000); 
    }
}