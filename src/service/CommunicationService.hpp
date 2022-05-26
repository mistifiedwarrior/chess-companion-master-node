#ifndef COMMUNICATION_SERVICE_HPP
#define COMMUNICATION_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/Logger.hpp"

class CommunicationService
{
private:
  Log logger = Log();
  int baudrate;
  SoftwareSerial *serial;

public:
  CommunicationService() {}

  CommunicationService(int baudrate, SoftwareSerial *serial)
  {
    (*this).baudrate = baudrate;
    (*this).serial = serial;
    (*serial).begin(baudrate);
  }

  String readMessage()
  {
    String message = "";
    while (available() > 0)
    {
      char str = (*serial).read();
      message += str;
    }
    return message;
  }

  int available()
  {
    return (*serial).available();
  }
};

#endif