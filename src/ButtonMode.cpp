#include "ButtonMode.h"

namespace buddon {

void ButtonMode::setup() {
  // TODO: Check for cached wifi credentials; setup wifi if none set
  //  On failure to connect to AP, blink LED a few times before power down?
}

void ButtonMode::loop() {
  // TODO:
  //  1) perform DHCP request (or some other easily-identifiable broadcast message)
  //   OR
  //  2) perform HTTP request to server address?
  //   THEN
  //  Power down
}

}