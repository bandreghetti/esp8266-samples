#include <ESP8266WiFi.h>
#include <OTA.h>
#include <UDP.h>
#include <reboot.h>

#ifndef STASSID
#define STASSID "bad-net-2.4GHz"
#define STAPSK "QeasdWF?Ejenam"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

// Set your Static IP address
IPAddress local_IP(192, 168, 0, 80);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

#define UDP_PORT 4133
UDPClient UDP; 

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_AUX, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN_AUX, LOW);

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

  UDP.Listen(UDP_PORT);

  digitalWrite(LED_BUILTIN_AUX, HIGH);
}

unsigned long lastDebug;

void loop(void) {
  auto now = millis();
  if (now - lastDebug >= 500) {
    digitalWrite(LED_BUILTIN, LOW);
    lastDebug = now;
    UDP.Debug(String(now));
    digitalWrite(LED_BUILTIN, HIGH);
  }
  UDP.Loop();
  LoopOTA();
}