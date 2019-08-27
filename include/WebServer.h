#ifndef LIGHTSWITCHBUTTON_INCLUDE_WEBSERVER_H_
#define LIGHTSWITCHBUTTON_INCLUDE_WEBSERVER_H_

#include <WString.h>
#include "OperationMode.h"

namespace buddon {

class RequestHandler {
 public:
  virtual void handleRequest() = 0;
 protected:
  String getRequestString();
};

class ServerDocument : public RequestHandler {
 public:
  void handleRequest() override;
  virtual String getContentType() = 0;
  virtual String getResponseBody() = 0;
};

class HtmlDocument : public ServerDocument {
 public:
  HtmlDocument();
  String getContentType() override;
  String getResponseBody() override;
 protected:
  virtual String getHeader() = 0;
  virtual String getTitle() = 0;
  virtual String getBody() = 0;
};

class WebServer : public OperationMode {
 public:
  WebServer();
  void setup() override;
  void loop() override;
  void on(const String &uri, RequestHandler *handler, bool replace_if_exists = false);
};

}

#endif //LIGHTSWITCHBUTTON_INCLUDE_WEBSERVER_H_
