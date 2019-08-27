#ifndef LIGHTSWITCHBUTTON_INCLUDE_CONFIGURATION_H_
#define LIGHTSWITCHBUTTON_INCLUDE_CONFIGURATION_H_


// Uncomment to enable debug output via Serial console.
#define DEBUG_MODE


//// Debug Output ////
#define BAUD_RATE             115200


//// GPIO ////
#define MODE_SWITCH_PIN       4


//// Wifi Client ////
#define CLIENT_SSID           "NetworkName"
#define CLIENT_ENCRYPTED      true
#define CLIENT_PASS           "NetworkPassword"


//// Access Point ////
#define AP_NAME               "LightswitchBtn"
#define AP_MAC_IN_NAME        true
#define AP_ENCRYPTED          true
#define AP_PASSWORD           "PASSWORD"
#define HTTP_SERVER_PORT      80


#endif //LIGHTSWITCHBUTTON_INCLUDE_CONFIGURATION_H_
