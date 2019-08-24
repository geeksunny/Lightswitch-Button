#include "ButtonMode.h"
#include "Configuration.h"
#include <ESP8266WiFi.h>
#include "WifiTools.h"

#ifdef DEBUG_MODE
#include <iostream>
#endif

namespace buddon {

void ButtonMode::setup() {
  // Start wifi in client mode
  if (!wifi_tools::startClient()) {
    while (true); // Halt
    // TODO: Properly handle halt with power down!
    //  - On failure to connect to AP, blink LED a few times before power down?
  }
}

void ButtonMode::loop() {
  // TODO:
  //  If a payload is defined, perform HTTP request to server address with payload
  //   THEN
  //  Power down
#ifdef DEBUG_MODE
  std::cout << "loop() : Sleeping 5 seconds." << std::endl;
#endif
  delay(5000);
}

}