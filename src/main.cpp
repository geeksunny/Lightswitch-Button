#include <Arduino.h>
#include "ConfigurationMode.h"
#include "ButtonMode.h"
#include <DebugLog.hpp>

buddon::OperationMode *mode;

bool modeSwitchActivated() {
  return digitalRead(MODE_SWITCH_PIN) == LOW;
}

void setup() {
  SETUP_SERIAL(BAUD_RATE, 3000, "Serial console ready.")

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