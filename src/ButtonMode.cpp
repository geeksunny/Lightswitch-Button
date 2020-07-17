#include "ButtonMode.h"
#include <util.hpp>
#include <DebugLog.hpp>
#include <ESP8266WiFi.h>
#include <WifiTools.h>

#ifdef IS_DEBUG_MODE
#include <iostream>
#endif

#define CLIENT_MODE_WIFI    0
#define CLIENT_MODE_ESPNOW  1
// Default CLIENT_MODE to WIFI
#ifndef CLIENT_MODE
#define CLIENT_MODE CLIENT_MODE_WIFI
#endif

// TODO: Manage action and value with digital inputs
#define CLIENT_ACTION     1
#define CLIENT_VALUE      0

namespace buddon {

ButtonMode::ButtonMode() {
#if CLIENT_MODE == CLIENT_MODE_WIFI
  client_ = util::make_unique<lightswitch::LightswitchWifiClient>();
  DEBUG("Button mode starting as CLIENT_MODE_WIFI.")
  #pragma message ("Button mode built as CLIENT_MODE_WIFI.")
#else //#elif CLIENT_MODE == CLIENT_MODE_ESPNOW
  client_ = util::make_unique<lightswitch::LightswitchEspNowClient>();
  DEBUG("Button mode starting as CLIENT_MODE_ESPNOW.")
  #pragma message ("Button mode built as CLIENT_MODE_ESPNOW.")
#endif
}

void ButtonMode::setup() {
#if CLIENT_MODE == CLIENT_MODE_WIFI
  // TODO: Can (or should?) this be moved into LightswitchWifiClient ?
  // Start wifi in client mode
  if (!wifi_tools::startClient()) {
    DEBUG("Failed to start Wifi client! Halting...")
    while (true); // Halt
    // TODO: Properly handle halt with power down!
    //  - On failure to connect to AP, blink LED a few times before power down?
  }
#else //#elif CLIENT_MODE == CLIENT_MODE_ESPNOW
  // No special setup needed for ESP-NOW. Its all handled in the LightswitchEspNowClient class.
#endif

  client_->setup();
  uint16_t clicks;
  bool result = client_->getStorage().getClicks(clicks);
  DEBUG("Click count: ", clicks, " | Result: ", (result ? "SUCCESS" : "FAILURE"))
  // DEBUG: Randomized action value...
  auto action = static_cast<lightswitch::LightswitchAction>(clicks % lightswitch::LightswitchAction::CYCLE);
//  auto action = lightswitch::LightswitchAction::CYCLE;
  client_->sendPerformAction(action, clicks % 101);
}

void ButtonMode::loop() {
//  DEBUG("loop() : Executing client.loop().")
  client_->loop();
//  DEBUG("loop() : Sleeping 1 second.")
  delay(1000);
}

}