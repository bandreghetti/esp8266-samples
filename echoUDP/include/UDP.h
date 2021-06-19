#ifndef UDP_H
#define UDP_H

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

class UDPClient
{
    WiFiUDP client;
public:
    void Listen(uint16_t);
    void Loop();
};

#endif
