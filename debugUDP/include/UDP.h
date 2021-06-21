#ifndef UDP_H
#define UDP_H

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

class UDPClient
{
    WiFiUDP client;
    bool debug;
    IPAddress remoteIP;
    uint16_t remotePort;
public:
    void Listen(uint16_t);
    void Loop();
    void Debug(String);
};

#endif
