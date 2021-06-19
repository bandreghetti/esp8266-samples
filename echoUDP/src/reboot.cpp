#include <reboot.h>

void reboot(uint8_t ledPin) {
    digitalWrite(ledPin, LOW);
    delay(60);
    digitalWrite(ledPin, HIGH);
    delay(60);
    digitalWrite(ledPin, LOW);
    delay(60);
    digitalWrite(ledPin, HIGH);
    delay(60);
    digitalWrite(ledPin, LOW);
    delay(60);
    digitalWrite(ledPin, HIGH);
    delay(60);
    digitalWrite(ledPin, LOW);
    delay(60);
    digitalWrite(ledPin, HIGH);
    delay(60);
    digitalWrite(ledPin, LOW);
    ESP.restart();
}