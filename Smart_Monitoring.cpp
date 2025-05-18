#include <ESP8266WiFi.h>
#include <Wire.h>

String apiKey = "xxxxx";//Thingspeak API key
const char *ssid = "xxxx";//Wifi_ssid
const char *pass = "XXXXXXXXXX";//Wifi_password
const char* server = "api.thingspeak.com";

const int sensorPin = A0;
int currentValue = 0;
float voltageOffset = 2.5;
float sensitivity = 0.185;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");

  pinMode(sensorPin, INPUT);
}

void loop() {
  currentValue = analogRead(sensorPin);
  float voltage = (currentValue / 1024.0) * 5.0;
  float current = (voltage - voltageOffset) / sensitivity;
  float power = 230.0 * current;  

  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A, Power: ");
  Serial.print(power);
  Serial.println(" W");

  if (client.connect(server, 80)) {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(current);
    postStr += "&field2=";
    postStr += String(power);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.println("Data sent to ThingSpeak");
  }
  client.stop();
  delay(15000);
}
