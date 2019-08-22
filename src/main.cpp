#include <Arduino.h>
#include "Configuration.h"
#include "ConfigurationMode.h"
#include "ButtonMode.h"

buddon::OperationMode *mode;

bool modeSwitchActivated() {
  return digitalRead(MODE_SWITCH_PIN) == LOW;
}

void setup() {
#ifdef DEBUG_MODE
  Serial.begin(BAUD_RATE);
  delay(3000);  // Give serial console a chance to get ready
  Serial.println("Serial console ready.");
#endif

  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);

  if (modeSwitchActivated()) {
    mode = new buddon::ConfigurationMode;
  } else {
    mode = new buddon::ButtonMode;
  }

  mode->setup();
}

void loop() {
  mode->loop();
}