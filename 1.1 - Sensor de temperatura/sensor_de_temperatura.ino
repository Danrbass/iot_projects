const int PinRed = 8;
const int PinBlue = 9;
const int PinGreen = 10;
const int pinTMP = A0;  // Clareza que é o pino analógico

void setup() 
{
  pinMode(PinRed, OUTPUT);
  pinMode(PinBlue, OUTPUT);
  pinMode(PinGreen, OUTPUT);

  Serial.begin(9600);

  // Estado inicial
  digitalWrite(PinRed, LOW); 
  digitalWrite(PinBlue, LOW); 
  digitalWrite(PinGreen, HIGH);
}

void loop() {
  int valueTMP = analogRead(pinTMP);

  // Converte valor para tensão (0 a 5V)
  float tension = valueTMP * (5.0 / 1023.0);

  // Para sensor TMP36:
  float temperatureC = (tension - 0.5) * 100.0;

  // Mostra tudo no monitor serial
  Serial.print("Leitura bruta: ");
  Serial.print(valueTMP);
  Serial.print(" | Tensão: ");
  Serial.print(tension);
  Serial.print(" V | Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Estados padrão
  bool stateRed = LOW;
  bool stateBlue = LOW;
  bool stateGreen = LOW;

  // Regras baseadas na leitura analógica
  if (valueTMP <= 125) {
    stateBlue = HIGH;
  } 
  else if (valueTMP > 125 and valueTMP <= 160) {
    stateGreen = HIGH;
  } 
  else {
    stateRed = HIGH;
    
  }

  // Atualiza os LEDs
  digitalWrite(PinRed, stateRed);
  digitalWrite(PinBlue, stateBlue);
  digitalWrite(PinGreen, stateGreen);

  delay(1000);  // Ajuda a estabilizar e visualizar
}


