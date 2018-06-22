#include "NetworkManager.h"

NetworkManager::NetworkManager() {

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