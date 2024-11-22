int soilMoisturePin = A7;  
int relayPin = 2;         
int ledDry = 3;           
int ledWet = 4;           

int moistureThreshold = 800; 
int hysteresis = 50;         
unsigned long maxPumpTime = 60000; 
unsigned long pumpStartTime = 0;

bool isPumpOn = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(soilMoisturePin, INPUT);
  pinMode(ledDry, OUTPUT);
  pinMode(ledWet, OUTPUT);

  digitalWrite(relayPin, LOW); 
  Serial.begin(9600); 
}

void loop() {
  int soilMoisture = analogRead(soilMoisturePin);

  Serial.print("Soil Moisture Level: ");
  Serial.println(soilMoisture);
  Serial.print("Pump Status: ");
  Serial.println(isPumpOn ? "ON" : "OFF");

  if (soilMoisture < moistureThreshold - hysteresis) {
    if (!isPumpOn) {
      digitalWrite(relayPin, HIGH); 
      isPumpOn = true;
      pumpStartTime = millis(); 
      digitalWrite(ledDry, HIGH);
      digitalWrite(ledWet, LOW);
      Serial.println("Pump turned ON.");
    }
  } else if (soilMoisture >= moistureThreshold) {
    if (isPumpOn) {
      digitalWrite(relayPin, LOW); 
      isPumpOn = false;
      digitalWrite(ledDry, LOW);
      digitalWrite(ledWet, HIGH);
      Serial.println("Pump turned OFF.");
    }
  }

  if (isPumpOn && millis() - pumpStartTime > maxPumpTime) {
    digitalWrite(relayPin, LOW); 
    isPumpOn = false;
    digitalWrite(ledDry, LOW);
    digitalWrite(ledWet, HIGH);
    Serial.println("Pump stopped due to maximum runtime.");
  }

  delay(1000); 
}
