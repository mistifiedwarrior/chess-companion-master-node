#ifndef INDICATOR_SERVICE_HPP
#define INDICATOR_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/CommunicationService.hpp"
#include "service/Logger.hpp"

class IndicatorService : public CommunicationService
{
private:
  Log logger = Log();

public:
  IndicatorService() {}

  IndicatorService(int baudrate, SoftwareSerial *serial) : CommunicationService(baudrate, serial) {}
};

#endif