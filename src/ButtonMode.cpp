#include "ButtonMode.h"
#include <ESP8266WiFi.h>
#include "WifiTools.h"

#ifdef IS_DEBUG_MODE
#include <iostream>
#endif

// TODO: Manage action and value with digital inputs
#define CLIENT_ACTION     1
#define CLIENT_VALUE      0

namespace buddon {

void ButtonMode::setup() {
  // Start wifi in client mode
  if (!wifi_tools::startClient()) {
    while (true); // Halt
    // TODO: Properly handle halt with power down!
    //  - On failure to connect to AP, blink LED a few times before power down?
  }
  client_.setup();
  client_.sendPerformAction(CLIENT_ACTION, CLIENT_VALUE);
}

void ButtonMode::loop() {
#ifdef IS_DEBUG_MODE
  std::cout << "loop() : Executing client.loop()." << std::endl;
#endif
  client_.loop();
  std::cout << "loop() : Sleeping 0.5 seconds." << std::endl;
#ifdef IS_DEBUG_MODE
#endif
  delay(500);
}

}