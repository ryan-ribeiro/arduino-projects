    #include <SPI.h>
    #include <SD.h>

    int pinoCS = 53; // Pin 53 para Mega / Pin 10 para UNO
    unsigned String leitura;

    void setup() {
    Serial.begin(9600);
    delay(1000);

    if(!SD.begin(pinoCS)){
      Serial.println("Falha ao iniciar o cartão micro SD");
      return;
    }
      Serial.println("Cartão micro SD incializado com sucesso");
    }

    void loop() {
        myFile = SD.open("test.txt", FILE_READ);

        if(myFile) {
          while(myFile.available()){
            leitura = myFile.read();
            // chamar metodo POST
          }
        } else {
          Serial.println("Erro ao abrir o arquivo.");
        }
    }
