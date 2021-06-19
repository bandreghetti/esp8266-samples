#include <ESP8266WiFi.h>
#include <OTA.h>
#include <reboot.h>

#ifndef STASSID
#define STASSID "my-ssid"
#define STAPSK "my-password"
#endif

#define BLINK_DELAY 100

const char *ssid = STASSID;
const char *password = STAPSK;

// Set your Static IP address
IPAddress local_IP(192, 168, 0, 80);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_AUX, OUTPUT);
  digitalWrite(LED_BUILTIN_AUX, HIGH);

  Serial.println("Booting");
  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, 0, 0))
  {
    reboot(LED_BUILTIN_AUX);
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    reboot(LED_BUILTIN_AUX);
  }

  SetupOTA();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

unsigned long currentTime;
uint8_t ledState;

void loop(void) {
  if (millis() - currentTime > BLINK_DELAY) {
    currentTime = millis();
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
  LoopOTA();
}