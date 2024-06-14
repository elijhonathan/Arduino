// Definindo os pinos para o conjunto 1
const int green1 = 2;
const int red1 = 3;

// Definindo os pinos para o conjunto 2
const int green2 = 4;
const int red2 = 5;

// Definindo os pinos para os botões
const int button1 = 6;
const int button2 = 7;

// Duração em milissegundos
const long greenTime = 10000; // Tempo em que a luz verde fica acesa (10 segundos)
const long blinkTime = 3000;  // Tempo em que a luz vermelha pisca antes de mudar (3 segundos)
const int blinkInterval = 500; // Intervalo de piscada (500ms)
const long allGreenTime = 3000; // Tempo em que todas as luzes ficam verdes (3 segundos)

void setup() {
  // Configurando os pinos como saída
  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);

  // Configurando os pinos dos botões como entrada com pull-up interno
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  // Inicializando o conjunto 1 com verde e conjunto 2 com vermelho
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
}

void loop() {
  // Conjunto 1 verde, conjunto 2 vermelho
  delay(greenTime);

  // Apagando o verde do conjunto 1
  digitalWrite(green1, LOW);

  // Piscando vermelho no conjunto 1 antes de mudar para vermelho permanente
  for (int i = 0; i < (blinkTime / blinkInterval); i++) {
    digitalWrite(red1, LOW);
    delay(blinkInterval / 2);
    digitalWrite(red1, HIGH);
    delay(blinkInterval / 2);
  }

  // Mudando o estado: conjunto 1 vermelho, conjunto 2 verde
  digitalWrite(red1, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, LOW);

  delay(greenTime);

  // Apagando o verde do conjunto 2
  digitalWrite(green2, LOW);

  // Piscando vermelho no conjunto 2 antes de mudar para vermelho permanente
  for (int i = 0; i < (blinkTime / blinkInterval); i++) {
    digitalWrite(red2, LOW);
    delay(blinkInterval / 2);
    digitalWrite(red2, HIGH);
    delay(blinkInterval / 2);
  }

  // Mudando o estado: conjunto 2 vermelho, conjunto 1 verde
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(red2, HIGH);

  // Verifica se algum dos botões foi pressionado
  if (digitalRead(button1) == LOW || digitalRead(button2) == LOW) {
    // Todos os semáforos ficam verdes por 3 segundos
    digitalWrite(green1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(green2, HIGH);
    digitalWrite(red2, LOW);
    delay(allGreenTime);
  }
}