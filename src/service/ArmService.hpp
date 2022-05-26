#ifndef ARM_SERVICE_HPP
#define ARM_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/CommunicationService.hpp"
#include "service/Logger.hpp"

class ArmService : public CommunicationService
{
private:
  Log logger = Log();

public:
  ArmService() {}

  ArmService(int baudrate, SoftwareSerial *serial) : CommunicationService(baudrate, serial) {}
};

#endif