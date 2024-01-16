#include <Keyboard.h>

// sample arduino sketch for macro-pad

#include <Arduino.h>
// #include <Keyboard.h>
// #include <Keypad.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Helloiii World");
  delay(1000);
}
