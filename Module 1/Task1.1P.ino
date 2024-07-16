// Define the TMP36 pin
const int tmp36Pin = A0;

// Define the LED pin
const int ledPin = 13;

// Define the temperature threshold to turn the fan on
const float temperatureThreshold = 25.50;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start the Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the TMP36
  int sensorValue = analogRead(tmp36Pin);

  // Convert the analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert the voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" *C");

  // Act based on the temperature
  if (temperatureC > temperatureThreshold) {
    Serial.println("Temperature is above threshold. Turning fan on.");
    // Turn the LED (fan) on
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("Temperature is below threshold. Turning fan off.");
    // Turn the LED (fan) off
    digitalWrite(ledPin, LOW);
  }

  // Wait a few seconds between measurements
  delay(2000);
}
