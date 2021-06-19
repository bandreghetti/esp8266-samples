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
        if (len > 0)
        {
            packet[len] = '\0';
        }

        // Send return packet
        this->client.beginPacket(this->client.remoteIP(), this->client.remotePort());
        this->client.write(packet);
        this->client.endPacket();
    }
}
