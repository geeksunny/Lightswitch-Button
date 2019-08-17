#ifndef WIFIBUDDON_INCLUDE_CONFIGURATION_H_
#define WIFIBUDDON_INCLUDE_CONFIGURATION_H_


// Uncomment to enable debug output via Serial console.
#define DEBUG_MODE


//// Debug Output ////
#define BAUD_RATE             115200


//// GPIO ////
#define MODE_SWITCH_PIN       4


//// Access Point ////
#define AP_NAME               "Buddon"
#define AP_MAC_IN_NAME        true
#define AP_ENCRYPTED          true
#define AP_PASSWORD           "PASSWORD"
#define HTTP_SERVER_PORT      80


#endif //WIFIBUDDON_INCLUDE_CONFIGURATION_H_