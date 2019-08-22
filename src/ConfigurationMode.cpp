#include "ConfigurationMode.h"
#include "Configuration.h"
#include "util.h"
#include <ESP8266WiFi.h>

#ifdef DEBUG_MODE
#include <iostream>
#endif

namespace buddon {

////////////////////////////////////////////////////////////////
// Class : ConfigurationMode ///////////////////////////////////
////////////////////////////////////////////////////////////////

char *apName() {
#if AP_MAC_IN_NAME
  char *result;
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.macAddress(mac);
  uint8_t strLen = sizeof(AP_NAME) + (WL_MAC_ADDR_LENGTH * 2);
  result = (char *) malloc(strLen);
  snprintf(result, strLen - 1, "%s_%d%d%d%d%d%d", AP_NAME, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  return result;
#else
  return util::allocLiteral(AP_NAME);
#endif
}

class ConfigRequestHandler : public ServerDocument {

  bool success = false;

 public:
  void handleRequest() override {
    String request = getRequestString();

    // TODO: Parse contents of request; update configuration / perform action
    //  * Update config values
    //  * "Blink LED" command for identifying connected button

    // TODO: set success=true if request is valid command & value was valid.
    //  Otherwise, success=false

#ifdef DEBUG_MODE
    std::cout << "Config set request from client: " << request << std::endl;
#endif

    ServerDocument::handleRequest();
  }

  String getContentType() override {
    return "type/text";
  }

  String getResponseBody() override {
    return success ? "SUCCESS" : "FAILED";
  }

};

ConfigurationMode::ConfigurationMode() {
  server_.on("/set", new ConfigRequestHandler);
}

void ConfigurationMode::setup() {
  // Start wifi access point
  char *name = apName();
  // TODO: Move to using Strings?

  WiFi.mode(WIFI_AP);
#if AP_ENCRYPTED
  bool started = WiFi.softAP(name, AP_PASSWORD);
#else
  bool started = WiFi.softAP(name);
#endif

#ifdef DEBUG_MODE
  if (started) {
    std::cout << "Started AP with name: " << name << " | Encrypted: " << (AP_ENCRYPTED ? "YES" : "NO") << std::endl;
    std::cout << "Server IP: " << WiFi.softAPIP().toString() << std::endl;
  } else {
    std::cout << "FAILED to start wifi AP!";
  }
#endif

  if (!started) {
    // TODO: halt the system
  }

  server_.setup();

  free(name);
}

void ConfigurationMode::loop() {
  server_.loop();
}

}
