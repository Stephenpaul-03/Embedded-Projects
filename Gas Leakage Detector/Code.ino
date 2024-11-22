const int gasSensorPin = A0; 
const int buttonPin = 2;     
const int redLedPin = 9;     
const int greenLedPin = 10;  

const int gasThreshold = 300;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    int gasValue = analogRead(gasSensorPin);
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);

    if (gasValue > gasThreshold) {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
    } else {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
    }
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }

  delay(50);
}
