#include "HID-Project.h"

const int VOLUME_DOWN_PIN = 14;
const int VOLUME_UP_PIN = 5;
const int PREV_MEDIA_PIN= 10;
const int PLAY_PAUSE_PIN = 7;
const int NEXT_MEDIA_PIN = 9;
const int POTENTIOMETER_PIN = A1;

int POT_VAL = 0;
int OLD_POT_VAL = 0;
int VOL_DIV = 17;
int POT_MAX = 1024;
int POT_DIV_SIZE = POT_MAX / VOL_DIV;

void setup() {
  pinMode(VOLUME_DOWN_PIN, INPUT_PULLUP);
  pinMode(VOLUME_UP_PIN, INPUT_PULLUP);
  pinMode(PREV_MEDIA_PIN, INPUT_PULLUP);
  pinMode(PLAY_PAUSE_PIN, INPUT_PULLUP);
  pinMode(NEXT_MEDIA_PIN, INPUT_PULLUP);

  // read potentiometer value
  POT_VAL = analogRead(POTENTIOMETER_PIN);
  OLD_POT_VAL = POT_VAL;
  Consumer.begin();
}

void loop() {
  POT_VAL = analogRead(POTENTIOMETER_PIN);
  if (POT_VAL / POT_DIV_SIZE > OLD_POT_VAL / POT_DIV_SIZE) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    OLD_POT_VAL = POT_VAL;
    delay(5);
  }
  if (POT_VAL / POT_DIV_SIZE < OLD_POT_VAL / POT_DIV_SIZE) {
    Consumer.write(MEDIA_VOLUME_UP);
    OLD_POT_VAL = POT_VAL;
    delay(5);
  }
  if (!digitalRead(VOLUME_DOWN_PIN)) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    delay(100);
  }
  if (!digitalRead(VOLUME_UP_PIN)) {
    Consumer.write(MEDIA_VOLUME_UP);
    delay(100);
  }
  if (!digitalRead(PREV_MEDIA_PIN)) {
    Consumer.write(MEDIA_PREV);
    delay(100);
  }
  if (!digitalRead(PLAY_PAUSE_PIN)) {
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(100);
  }
  if (!digitalRead(NEXT_MEDIA_PIN)) {
    Consumer.write(MEDIA_NEXT);
    delay(100);
  }
}
