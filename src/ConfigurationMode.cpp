#include "ConfigurationMode.h"
#include "Configuration.h"
#include <ESP8266WiFi.h>

#ifdef DEBUG_MODE
#include <PrintStream.h>
#endif

namespace buddon {

const char *apName() {
#if AP_MAC_IN_NAME
  char *result;
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.macAddress(mac);
  uint8_t strLen = sizeof(AP_NAME) + (WL_MAC_ADDR_LENGTH * 2);
  result = (char *) malloc(strLen);
  snprintf(result, strLen - 1, "%s_%d%d%d%d%d%d", AP_NAME, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#else
  const char *result = AP_NAME;
#endif
  return result;
}

void handleRoot() {
  // TODO: Read in index.html, send to client.
  web_server.send(200, "text/plain", "Hello, world.");
}

void handleSet() {
  String request = web_server.client().readString();

  // TODO: Parse contents of request; update configuration / perform action
  //  * Update config values
  //  * "Blink LED" command for identifying connected button

#ifdef DEBUG_MODE
  Serial << "From client: " << request << endl;
#endif

  web_server.send(200, "text/plain", "SET");
}

void handleNotFound() {
  web_server.send(404, "text/plain", "HTTP404 - Not found!");
}

ConfigurationMode::ConfigurationMode() {
  web_server.on("/", handleRoot);
  web_server.on("/set", handleSet);
  web_server.onNotFound(handleNotFound);
}

void ConfigurationMode::setup() {
  // Start wifi access point
  const char *name = apName();

  WiFi.mode(WIFI_AP);
#if AP_ENCRYPTED
  bool started = WiFi.softAP(name, AP_PASSWORD);
#else
  bool started = WiFi.softAP(name);
#endif

#ifdef DEBUG_MODE
  if (started) {
    Serial << "Started AP with name: " << name << " | Encrypted: " << (AP_ENCRYPTED ? "YES" : "NO") << endl;
    Serial << "Server IP: " << WiFi.softAPIP() << endl;
  } else {
    Serial << "FAILED to start wifi AP!";
  }
#endif

  if (!started) {
    // TODO: halt the system
  }

  web_server.begin();

  // TODO: Will call to free() fail when AP_MAC_IN_NAME==false? TEST THIS!
  free((char *) name);
}

void ConfigurationMode::loop() {
  web_server.handleClient();
}

}
