#ifndef OTA_H
#define OTA_H

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void SetupOTA();
void LoopOTA();
void WaitOTA(unsigned long);

#endif
