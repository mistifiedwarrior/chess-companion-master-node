#ifndef PIECES_SERVICE_HPP
#define PIECES_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/Logger.hpp"

class PiecesService
{
private:
  Log logger = Log();
  int baudrate;
  SoftwareSerial *serial;

public:
  PiecesService() {}

  PiecesService(int baudrate, SoftwareSerial *serial)
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