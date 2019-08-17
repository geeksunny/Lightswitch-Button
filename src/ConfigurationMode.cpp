#include "ConfigurationMode.h"
#include "Configuration.h"
#include <ESP8266WiFi.h>

#ifdef DEBUG_MODE
#include <PrintStream.h>
#endif

namespace buddon {

char *apName() {
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.macAddress(mac);
  uint8_t strLen = sizeof(AP_PREFIX) + (WL_MAC_ADDR_LENGTH * 2);
  char *result = (char *) malloc(strLen);
  snprintf(result, strLen - 1, "%s%d%d%d%d%d%d", AP_PREFIX, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  return result;
}

void ConfigurationMode::setup() {
  // Start wifi access point
  char *name = apName();
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

  free(name);
}

void ConfigurationMode::loop() {
  // TODO: Monitor incoming requests
  //  * Config values
  //  * "Blink LED" command for identifying connected button
}

}
