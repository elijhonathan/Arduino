// Definindo os pinos dos LEDs vermelhos
const int redLEDs[] = {7, 6, 5, 4};

// Definindo os pinos dos LEDs verdes
const int greenLEDs[] = {13, 12, 11, 10};

// Definindo o pino do buzzer
const int buzzer = 2;

// Tempo de atraso entre cada LED (em milissegundos)
const int delayTime = 1000;

// Frequências para os sons
const int beepFrequency = 1000; // Frequência do beep padrão
const int startFrequency = 2000; // Frequência do beep de início

void setup() {
  // Configurando os pinos dos LEDs vermelhos como saída
  for (int i = 0; i < 4; i++) {
    pinMode(redLEDs[i], OUTPUT);
  }

  // Configurando os pinos dos LEDs verdes como saída
  for (int i = 0; i < 4; i++) {
    pinMode(greenLEDs[i], OUTPUT);
  }

  // Configurando o pino do buzzer como saída
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Acendendo os LEDs vermelhos um a um com beep
  for (int i = 0; i < 4; i++) {
    digitalWrite(redLEDs[i], HIGH);
    tone(buzzer, beepFrequency);
    delay(200); // Duração do beep
    noTone(buzzer);
    delay(delayTime - 200); // Espera pelo tempo restante
  }

  // Todos os LEDs verdes acendem e som de início
  for (int i = 0; i < 4; i++) {
    digitalWrite(greenLEDs[i], HIGH);
  }

  tone(buzzer, startFrequency);
  delay(1000); // Duração do beep de início
  noTone(buzzer);

  // Aguardar antes de apagar todos os LEDs para reiniciar o ciclo
  delay(5000);

  // Apagar todos os LEDs vermelhos e verdes
  for (int i = 0; i < 4; i++) {
    digitalWrite(redLEDs[i], LOW);
    digitalWrite(greenLEDs[i], LOW);
  }

  // Pausa antes de reiniciar o ciclo
  delay(2000);
}
