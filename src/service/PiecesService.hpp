#ifndef PIECES_SERVICE_HPP
#define PIECES_SERVICE_HPP

#include <ESP8266WiFi.h>
#include "service/Logger.hpp"

class PiecesService
{
private:
  Log logger = Log();
  int baudrate, rx, tx;

public:
  PiecesService() {}

  PiecesService(int baudrate, int tx, int rx)
  {
    (*this).baudrate = baudrate;
    (*this).tx = tx;
    (*this).rx = rx;
  }
};

#endif