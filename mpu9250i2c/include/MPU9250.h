#ifndef MPU9250_H
#define MPU9250_H

#include <Wire.h>

class MPU9250
{
    uint8_t address = 0x68;
    uint8_t magAddress = 0x0c;
public:
    String Init();
    String DumpRegisters();
};

#endif
