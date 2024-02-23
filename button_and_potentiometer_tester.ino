void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // Button 1
  pinMode(3, INPUT_PULLUP); // Button 2
  pinMode(4, INPUT_PULLUP); // Button 3
  pinMode(A0, INPUT); // Potentiometer 1
  pinMode(A1, INPUT); // Potentiometer 2
  Serial.begin(31250);
}

int buttonStatus[3] = {0}; // Array to store the status of three buttons
int potValues[2] = {0}; // Array to store the values of two potentiometers

void loop() {
  // put your main code here, to run repeatedly:
  int pinValues[3]; // Array to store the readings of three buttons
  pinValues[0] = digitalRead(2); // Button 1
  pinValues[1] = digitalRead(3); // Button 2
  pinValues[2] = digitalRead(4); // Button 3
  potValues[0] = analogRead(A0); // Potentiometer 1
  potValues[1] = analogRead(A1); // Potentiometer 2
  delay(10);
  
  // Check each button
  for (int i = 0; i < 3; i++) {
    if (buttonStatus[i] != pinValues[i]) {
      buttonStatus[i] = pinValues[i];
      Serial.print("Button ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(buttonStatus[i]);
    }
  }
  
  // Print potentiometer values
  Serial.print("Potentiometer 1: ");
  Serial.println(potValues[0]);
  Serial.print("Potentiometer 2: ");
  Serial.println(potValues[1]);
}
