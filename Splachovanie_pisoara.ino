const int builtInLEDPin = LED_BUILTIN;
const int INPUT_PIN = 2;    //PIR sensor
const int LED = 3;          //indicative red LED diode
const int RELAY_1 = 4;
const int RELAY_2 = 5;
const int RELAY_3 = 6;
const int RELAY_4 = 7;
bool inputActive = false;
unsigned long startTime = 0;

void setup() {
  pinMode(INPUT_PIN, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
}

//All relays are active at signal LOW
void loop() {
  digitalWrite(RELAY_1, HIGH);
  digitalWrite(RELAY_2, HIGH);
  digitalWrite(RELAY_3, HIGH);
  digitalWrite(RELAY_4, HIGH);

//Reading signal from PIR sensor
  bool inputState = digitalRead(INPUT_PIN);   

//If motion was detected by PIR sensor
  if (inputState == HIGH) {
    digitalWrite(builtInLEDPin, HIGH);
    digitalWrite(LED, HIGH);

    if (!inputActive) {
      startTime = millis();
      inputActive = true;
    }
  } 
  //If motion was not detected
  else {
    digitalWrite(builtInLEDPin, LOW);
    digitalWrite(LED, LOW);

    if (inputActive && millis() - startTime >= 10000) {
      //Indicating the countdown to the next flush
      blinkLEDSequence(3, 500);
      blinkLEDSequence(4, 250);
      blinkLEDSequence(5, 125);

      //Activate the flushing system
      activateRelays(RELAY_1, RELAY_2);
      delay(300);
      deactivateRelays(RELAY_1, RELAY_2);

      //time of flushing the water
      delay(5000);

      //Deactivate the flushing system
      activateRelays(RELAY_3, RELAY_4);
      delay(300);
      deactivateRelays(RELAY_3, RELAY_4);

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
