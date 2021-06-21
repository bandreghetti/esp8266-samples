#include <UDP.h>

void UDPClient::Listen(uint16_t port)
{
    this->client.begin(port);
}

void UDPClient::Loop()
{
    int packetSize = this->client.parsePacket();
    if (packetSize)
    {
        char packet[255];
        int len = this->client.read(packet, 255);
        packet[len] = '\0';
        if (len >= 2 && packet[0] == 'o' && packet[1] == 'n')
        {
            this->debug = true;
            this->remoteIP = this->client.remoteIP();
            this->remotePort = this->client.remotePort();
        }
        else if (len >= 3 && packet[0] == 'o' && packet[1] == 'f' && packet[2] == 'f')
        {
            this->debug = false;
        }
    }
}

void UDPClient::Debug(String msg)
{
    if (this->debug)
    {
        if (!msg.endsWith("\n")) {
            msg = msg + "\n";
        }
        this->client.beginPacket(this->remoteIP, this->remotePort);
        this->client.write(msg.c_str());
        this->client.endPacket();
    }
}