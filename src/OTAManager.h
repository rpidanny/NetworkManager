#ifndef OTAMANAGER_H
#define OTAMANAGER_H

#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class OTAManager {
  public:
    OTAManager();
    void begin();
    void handle();
  private:
    void DEBUG_OTA(String msg);

    bool _debug = true;
    const char* _host = String("ESP-" + ESP.getChipId()).c_str();
    const char* _password = "21232f297a57a5a743894a0e4a801fc3"; // MD5: admin
};

extern OTAManager Ota;

#endif