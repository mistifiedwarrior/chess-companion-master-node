#ifndef ARM_SERVICE_HPP
#define ARM_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/Logger.hpp"

class ArmService
{
private:
  Log logger = Log();
  int baudrate;
  SoftwareSerial *serial;

public:
  ArmService() {}

  ArmService(int baudrate, SoftwareSerial *serial)
  {
    (*this).baudrate = baudrate;
    (*this).serial = serial;
    (*serial).begin(baudrate);
  }

  int readMessage()
  {
    while (available() > 0)
    {
      return (*serial).read();
    }
    return 0;
  }

private:
  int available()
  {
    return (*serial).available();
  }
};

#endif