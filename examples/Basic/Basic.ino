#include <NetworkManager.h>

void setup() {
  Serial.begin(115200);
  Network.begin();
}

void loop() {
  Network.handle();
}