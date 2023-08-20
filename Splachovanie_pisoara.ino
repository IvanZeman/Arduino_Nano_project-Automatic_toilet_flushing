const int builtInLEDPin = LED_BUILTIN;
const int INPUT_PIN = 2;
const int LED = 3;
const int RELE_1 = 4;
const int RELE_2 = 5;
const int RELE_3 = 6;
const int RELE_4 = 7;
bool inputActive = false;
unsigned long startTime = 0;

void setup() {
  pinMode(INPUT_PIN, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(RELE_1, OUTPUT);
  pinMode(RELE_2, OUTPUT);
  pinMode(RELE_3, OUTPUT);
  pinMode(RELE_4, OUTPUT);
}

void loop() {
  digitalWrite(RELE_1, HIGH);
  digitalWrite(RELE_2, HIGH);
  digitalWrite(RELE_3, HIGH);
  digitalWrite(RELE_4, HIGH);

  bool inputState = digitalRead(INPUT_PIN);

  if (inputState == HIGH) {
    digitalWrite(builtInLEDPin, HIGH);
    digitalWrite(LED, HIGH);

    if (!inputActive) {
      startTime = millis();
      inputActive = true;
    }
  } else {
    digitalWrite(builtInLEDPin, LOW);
    digitalWrite(LED, LOW);

    if (inputActive && millis() - startTime >= 10000) {
      blinkLEDSequence(3, 500);
      blinkLEDSequence(4, 250);
      blinkLEDSequence(5, 125);

      activateRelays(RELE_1, RELE_2);
      delay(300);
      deactivateRelays(RELE_1, RELE_2);

      delay(5000);

      activateRelays(RELE_3, RELE_4);
      delay(300);
      deactivateRelays(RELE_3, RELE_4);


      inputActive = false;
    }
  }
}

void blinkLEDSequence(int count, int delayTime) {
  for (int i = 0; i < count; i++) {
    digitalWrite(LED, HIGH);
    delay(delayTime);
    digitalWrite(LED, LOW);
    delay(delayTime);
  }
}

void activateRelays(int relay1, int relay2) {
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void deactivateRelays(int relay1, int relay2) {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}