const int soundSensorPin = A0; // Connect the sound sensor to analog pin A0
const int redPin = 9; // Connect the red pin of the RGB LED to digital pin 9
const int greenPin = 10; // Connect the green pin of the RGB LED to digital pin 10
const int bluePin = 11; // Connect the blue pin of the RGB LED to digital pin 11

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundValue = analogRead(soundSensorPin); // Read the analog value from the sound sensor
  Serial.println(soundValue); // Print the sound value to the serial monitor

  if (soundValue > 800) { // Adjust this threshold based on your sensor and environment
    blinkLED(255, 0, 0); // Blink red when the sound is high
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}

void blinkLED(int red, int green, int blue) {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  delay(100); // Adjust the delay time to control the blinking speed
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(100); // Adjust the delay time to control the blinking speed
}
