#ifndef ARM_SERVICE_HPP
#define ARM_SERVICE_HPP

#include <ESP8266WiFi.h>
#include "service/Logger.hpp"

class ArmService
{
private:
  Log logger = Log();
  int baudrate, rx, tx;

public:
  ArmService() {}

  ArmService(int baudrate, int tx, int rx)
  {
    (*this).baudrate = baudrate;
    (*this).tx = tx;
    (*this).rx = rx;
  }
};

#endif