#include <DHT.h>
#include <ESP8266WiFi.h>

DHT dht(2, DHT22);

char ssid[] = "";
char password[] = "";

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectToWifi();
  }

  float hum = dht.readHumidity();
  float temp = dht.readTemperature(true);

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
  }

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" *F\t");
  Serial.println();
    
  delay(5000);
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
