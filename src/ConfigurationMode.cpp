#include "ConfigurationMode.h"
#include <ESP8266WiFi.h>
#include "WifiTools.h"

#ifdef DEBUG_MODE
#include <iostream>
#endif

namespace buddon {

////////////////////////////////////////////////////////////////
// Class : ConfigurationMode ///////////////////////////////////
////////////////////////////////////////////////////////////////

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

  if (!wifi_tools::startAP()) {
    // TODO: halt the system
  }

  server_.setup();
}

void ConfigurationMode::loop() {
  server_.loop();
}

}
