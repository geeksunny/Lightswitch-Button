#ifndef WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
#define WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_

#include "OperationMode.h"
#include "Configuration.h"
#include <ESP8266WebServer.h>

namespace buddon {

static ESP8266WebServer web_server(HTTP_SERVER_PORT);

class ConfigurationMode : public OperationMode {
 public:
  ConfigurationMode();
  void setup() override;
  void loop() override;
};

}

#endif //WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
