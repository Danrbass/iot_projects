const int PinRoj = 8;
const int PinAzu = 9;
const int PinVer = 10;
const int pinTMP = A0;  // Clareza que é o pino analógico

void setup() 
{
  pinMode(PinRoj, OUTPUT);
  pinMode(PinAzu, OUTPUT);
  pinMode(PinVer, OUTPUT);

  Serial.begin(9600);

  // Estado inicial
  digitalWrite(PinRoj, LOW); 
  digitalWrite(PinAzu, LOW); 
  digitalWrite(PinVer, HIGH);
}

void loop() {
  int valorTMP = analogRead(pinTMP);

  // Converte valor para tensão (0 a 5V)
  float tensao = valorTMP * (5.0 / 1023.0);

  // Para sensor TMP36:
  float temperaturaC = (tensao - 0.5) * 100.0;

  // Mostra tudo no monitor serial
  Serial.print("Leitura bruta: ");
  Serial.print(valorTMP);
  Serial.print(" | Tensão: ");
  Serial.print(tensao);
  Serial.print(" V | Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" °C");

  // Estados padrão
  bool estadoRoj = LOW;
  bool estadoAzu = LOW;
  bool estadoVer = LOW;

  // Regras baseadas na leitura analógica
  if (valorTMP <= 125) {
    estadoAzu = HIGH;
  } 
  else if (valorTMP > 125 and valorTMP <= 160) {
    estadoVer = HIGH;
  } 
  else {
    estadoRoj = HIGH;
    
  }

  // Atualiza os LEDs
  digitalWrite(PinRoj, estadoRoj);
  digitalWrite(PinAzu, estadoAzu);
  digitalWrite(PinVer, estadoVer);

  delay(1000);  // Ajuda a estabilizar e visualizar
}


