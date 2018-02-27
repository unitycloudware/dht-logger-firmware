#include <UCW_System.h>

/************************ UCW Platform Config *******************************/

// Configuration of the connection string to the UCW Platform.
static UCWConfig cfg = {
  .host = your_ucw_host,
  .port = 9601,
  .isSecuredConnection = false,
  .useMqtt = false,
  .token = "your_token"
};

/******************************* WiFi **************************************/

/*
  The UCW_WiFi client will work with the following boards:
    - Feather M0 WiFi -> https://www.adafruit.com/products/3010
    - Feather HUZZAH ESP8266 -> https://www.adafruit.com/products/2821
    - HUZZAH ESP8266 Breakout -> https://www.adafruit.com/products/2471
    - Feather WICED -> https://www.adafruit.com/products/3056
*/

#define WIFI_SSID       "your_ssid"
#define WIFI_PASS       "your_pass"

// comment out the following two lines if you are using WiFi
#include "UCW_WiFi.h"
UCW_WiFi ucw(&cfg, WIFI_SSID, WIFI_PASS);

/**************************** Ethernet ************************************/

/*
  The UCW_Ethernet client will work with the following boards:
    - Ethernet FeatherWing -> https://www.adafruit.com/products/3201
 */

// uncomment the following two lines for ethernet,
//#include "UCW_Ethernet.h"
//UCW_Ethernet ucw(cfg);

