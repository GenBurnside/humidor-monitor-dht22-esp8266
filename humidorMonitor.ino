#include <ESP8266WiFi.h>

char ssid[] = "";
char password[] = "";

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectToWifi();
  }
    
  delay(1000);
}

void connectToWifi() {
  Serial.println();
  Serial.print("Connecting to network: ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}
