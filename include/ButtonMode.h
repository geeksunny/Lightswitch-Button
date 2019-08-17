#ifndef WIFIBUDDON_INCLUDE_BUTTONMODE_H_
#define WIFIBUDDON_INCLUDE_BUTTONMODE_H_

#include "OperationMode.h"

namespace buddon {

class ButtonMode : public OperationMode {
 public:
  ButtonMode() = default;
  void setup() override;
  void loop() override;
};

}

#endif //WIFIBUDDON_INCLUDE_BUTTONMODE_H_
