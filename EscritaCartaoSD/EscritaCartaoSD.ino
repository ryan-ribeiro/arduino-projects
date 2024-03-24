    #include <SPI.h>
    #include <SD.h>

    int pinoCS = 53; // Pin 53 para Mega / Pin 10 para UNO

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
      File data = SD.open("arquivo.txt", FILE_WRITE);

      if (data) {
        data.print("Leitura 1: " + dados + "/t" + dados2);
        data.println("");
        data.close();
      } else {
        Serial.println("Erro ao abrir o arquivo");
      }

      delay(5000);
    }
