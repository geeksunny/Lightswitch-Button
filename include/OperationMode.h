#ifndef WIFIBUDDON_INCLUDE_OPERATIONMODE_H_
#define WIFIBUDDON_INCLUDE_OPERATIONMODE_H_

namespace buddon {

class OperationMode {
 public:
  virtual void setup() = 0;
  virtual void loop() = 0;
};

}

#endif //WIFIBUDDON_INCLUDE_OPERATIONMODE_H_
