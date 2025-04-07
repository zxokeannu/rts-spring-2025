const int ledPin1 =  3;
const int ledPin2 =  5;
const int ledPin3 =  6;
const int ledPin4 =  9;
const int ledPin5 =  10;

int ledState1 = LOW;             
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;
int ledState5 = LOW;

unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 

unsigned long previousMicros3 = 0;
unsigned long previousMicros4 = 0;
unsigned long previousMicros5 = 0;

const long interval1 = 10;
const long interval2 = 1;
const long interval3 = 500;
const long interval4 = 100;
const long interval5 = 50;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;

    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
  }
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
  }
  if (currentMicros - previousMicros3 >= interval3) {
    previousMicros3 = currentMicros;

    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }
  }
  if (currentMicros - previousMicros4 >= interval4) {
    previousMicros4 = currentMicros;

    if (ledState4 == LOW) {
      ledState4 = HIGH;
    } else {
      ledState4 = LOW;
    }
  }
  if (currentMicros - previousMicros5 >= interval5) {
    previousMicros5 = currentMicros;

    if (ledState5 == LOW) {
      ledState5 = HIGH;
    } else {
      ledState5 = LOW;
    }
  }
    digitalWrite(ledPin1, ledState1);
    digitalWrite(ledPin2, ledState2);
    digitalWrite(ledPin3, ledState3);
    digitalWrite(ledPin4, ledState4);
    digitalWrite(ledPin5, ledState5);
}
