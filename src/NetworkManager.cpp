#include "NetworkManager.h"

NetworkManager::NetworkManager() {
  _hostname = "ESP_" + ESP.getChipId();
}

void NetworkManager::DEBUG_NM(String msg) {
  if (_debug) {
    Serial.print("*NM: ");
    Serial.println(msg);
  }
}

void NetworkManager::begin() {
  // Local initialization
  WiFiManager wifiManager;
  if (!wifiManager.autoConnect()) {
    DEBUG_NM("Failed to connect..");
    ESP.reset();
    delay(WIFI_RECONNECT_TIME);
  }
  DEBUG_NM("Connected to " + WiFi.SSID());

  // setup mDNS
  WiFi.hostname(_hostname.c_str());
  if (!MDNS.begin(_hostname.c_str())) {
    DEBUG_NM("Error setting up mDNS responder.");
  }

  // Initialize OTA Service
  if (_ota)
    Ota.begin();
}

void NetworkManager::handle() {
  if (_ota)
    Ota.handle();
}

void NetworkManager::ota(bool flag) {
  _ota = flag;
}

NetworkManager Network;