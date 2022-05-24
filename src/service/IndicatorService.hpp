#ifndef INDICATOR_SERVICE_HPP
#define INDICATOR_SERVICE_HPP

#include <ESP8266WiFi.h>
#include "service/Logger.hpp"

class IndicatorService
{
private:
  Log logger = Log();
  int baudrate, rx, tx;

public:
  IndicatorService() {}

  IndicatorService(int baudrate, int tx, int rx)
  {
    (*this).baudrate = baudrate;
    (*this).tx = tx;
    (*this).rx = rx;
  }
};

#endif