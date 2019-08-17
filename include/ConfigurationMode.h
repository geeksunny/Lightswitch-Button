#ifndef WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
#define WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_

#include "OperationMode.h"

namespace buddon {

class ConfigurationMode : public OperationMode {
 public:
  ConfigurationMode() = default;
  void setup() override;
  void loop() override;
};

}

#endif //WIFIBUDDON_INCLUDE_CONFIGURATIONMODE_H_
