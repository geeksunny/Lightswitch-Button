#ifndef WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
#define WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_

#include "OperationMode.h"
#include "WebServer.h"

namespace buddon {

class ConfigurationMode : public OperationMode {
  WebServer server_;
 public:
  ConfigurationMode();
  void setup() override;
  void loop() override;
};

}

#endif //WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
