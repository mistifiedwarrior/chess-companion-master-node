#ifndef PIECES_SERVICE_HPP
#define PIECES_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/CommunicationService.hpp"
#include "service/Logger.hpp"

class PiecesService : public CommunicationService
{
private:
  Log logger = Log();
  int baudrate;
  SoftwareSerial *serial;

public:
  PiecesService() {}

  PiecesService(int baudrate, SoftwareSerial *serial) : CommunicationService(baudrate, serial) {}
};

#endif