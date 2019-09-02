#ifndef LIGHTSWITCHBUTTON_INCLUDE_BUTTONMODE_H_
#define LIGHTSWITCHBUTTON_INCLUDE_BUTTONMODE_H_

#include "OperationMode.h"
#include <LightswitchClient.h>

namespace buddon {

class ButtonMode : public OperationMode {
  lightswitch::LightswitchClient client_;
 public:
  ButtonMode() = default;
  void setup() override;
  void loop() override;
};

}

#endif //LIGHTSWITCHBUTTON_INCLUDE_BUTTONMODE_H_
