// SerialHello
// 
// This program:
// * takes input from potentiometer -> sends values to serial
// * takes serial input -> sets onboard LED to (L)ow and (H)igh 

int incomingByte;
int lastValPot = -1;
int sensitivityFactor = 10; // lower is more sensitive )potentiometer)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read in serial and toggle onboard LED
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    // capital H (ASCII 72) turns on the LED
    if (incomingByte == 'H') { // 
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Setting light high");
    }

    // capital L (ASCII 76) turns off the LED
    if (incomingByte == 'L') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("Setting light low");
    }
  }

  // send an update when the value has changed significantly
  int valPot = analogRead(A0);
  if (abs(valPot - lastValPot) > sensitivityFactor) {
    Serial.println("New value pot: " + String(valPot));
    lastValPot = valPot;
  }
}
