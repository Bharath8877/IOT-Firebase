#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "host"
#define FIREBASE_AUTH "auth key"
#define WIFI_SSID "your ssid"
#define WIFI_PASSWORD "password"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
void loop() {
  int a = analogRead(A0);
  float mv= a*2.932;
  float cel = mv/10;
  Serial.print("Tempearature:");
  Serial.println(cel);
  Firebase.setFloat("Temperature",cel);
  delay(1000);
}
