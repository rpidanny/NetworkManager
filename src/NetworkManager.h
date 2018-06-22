#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#ifdef DEBUG_ESP_PORT
  #define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
  #define DEBUG_MSG(...)
#endif

#ifndef WIFI_RECONNECT_TIME
  #define WIFI_RECONNECT_TIME 3000
#endif

#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)
#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include "OTAManager.h"

class NetworkManager {
  public:
    NetworkManager();
    void begin();
    void handle();
    void ota(bool flag = true);
  private:
    void DEBUG_NM(String msg);

    bool _debug = true;
    bool _ota;
};

extern NetworkManager Network;

#endif