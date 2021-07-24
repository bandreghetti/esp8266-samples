#include <MPU9250.h>

String MPU9250::DumpRegisters()
{
    String dump = "IMU| X0 X1 X2 X3 X4 X5 X6 X7 X8 X9 Xa Xb Xc Xd Xe Xf\n";
    dump += "---|------------------------------------------------\n";
    Wire.beginTransmission(this->address);
    Wire.write(0x00);
    auto err = Wire.endTransmission(this->address);
    if (err != 0)
    {
        return "failed to dump IMU registers";
    }
    Wire.requestFrom(this->address, 128);
    for (int i = 0; i < 128; i++)
    {
        if (i%16 == 0) dump += String(i/16, HEX) + "X |";
        int regVal = Wire.read();
        String regStr = String(regVal, HEX);
        if (regStr.length() == 1)
        {
            regStr = "0" + regStr;
        }
        dump += " " + regStr;
        if (i%16 == 15) dump += "\n";
    }
    dump += "----------------------------------------------------\n";

    dump += "MAG| X0 X1 X2 X3 X4 X5 X6 X7 X8 X9 Xa Xb Xc Xd Xe Xf\n";
    Wire.beginTransmission(this->magAddress);
    Wire.write(0x00);
    err = Wire.endTransmission(this->magAddress);
    if (err != 0)
    {
        return "failed to dump MAG registers";
    }
    Wire.requestFrom(this->magAddress, (uint8_t)(128));
    for (int i = 0; i < 128; i++)
    {
        if (i%16 == 0) dump += String(i/16, HEX) + "X |";
        int regVal = Wire.read();
        String regStr = String(regVal, HEX);
        if (regStr.length() == 1)
        {
            regStr = "0" + regStr;
        }
        dump += " " + regStr;
        if (i%16 == 15) dump += "\n";
    }
    dump += "----------------------------------------------------\n";

    return dump;
}

String MPU9250::Init() {
    Wire.beginTransmission(this->address);
    Wire.write(0x37);
    Wire.write(0x02);
    auto err = Wire.endTransmission(this->address);
    if (err != 0)
    {
        return "failed to init IMU";
    }
}