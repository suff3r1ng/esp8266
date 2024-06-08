#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
  HTTPClient https;
  WiFiClientSecure client;
const char* ssid = "Monarch of Shadows";         // Replace with your Wi-Fi SSID
const char* password = "Gerald1999!"; // Replace with your Wi-Fi password
const char* host = "raw.githubusercontent.com"; // Replace with your actual GitHub raw file host
const char* url = "/suff3r1ng/esp8266/main/index.html"; // Replace with your actual GitHub raw file URL
const int port = 443;
ESP8266WebServer server(80); // Web server on port 80 (HTTP)

void handleRoot() {
    Serial.begin(115200);
  
  client.setInsecure();
  https.begin(client, "https://raw.githubusercontent.com/suff3r1ng/esp8266/main/index.html");
  int httpCode = https.GET();
  Serial.print(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    String payload = https.getString();

    server.send(200, "html", payload);
  } else {
    server.send(500, "text/plain", "Error fetching index.html");
  }

  https.end();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi... count:");
    Serial.println(WiFi.status());
  }
  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}


