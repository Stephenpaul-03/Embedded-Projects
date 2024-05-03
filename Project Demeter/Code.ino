int soilMoisturePin = A7; // Analog pin for the soil moisture sensor
int relayPin = 2;        // Digital pin to control the relay
int moistureThreshold = 800; // Adjust this threshold according to your sensor
int hysteresis = 50;       // Hysteresis range to prevent rapid cycling

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(soilMoisturePin, INPUT);
}

void loop() {
  int soilMoisture = analogRead(soilMoisturePin);

  if (soilMoisture < moistureThreshold - hysteresis) {
    digitalWrite(relayPin, HIGH); // Soil is dry, turn on the pump
  } else if (soilMoisture >= moistureThreshold) {
    digitalWrite(relayPin, LOW);  // Soil is wet, turn off the pump
  }

  delay(1000); // Delay for 1 second before checking again (adjust as needed)
}
