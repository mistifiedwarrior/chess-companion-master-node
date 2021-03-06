#ifndef MASTER_SERVICE_HPP
#define MASTER_SERVICE_HPP

#include <ArduinoJson.h>
#include <list>
#include "service/Logger.hpp"
#include "service/PiecesService.hpp"
#include "service/ArmService.hpp"
#include "service/IndicatorService.hpp"
#include "domain/Error.hpp"
#include "service/WebsocketClient.hpp"
#include "gateway/ChessGateway.hpp"

class MasterService
{
private:
  Log logger;
  PiecesService piecesService;
  IndicatorService indicatorService;
  ArmService armService;
  ChessGateway chessGateway;

public:
  MasterService() {}

  MasterService(PiecesService piecesService, IndicatorService indicatorService, ArmService armService, ChessGateway chessGateway)
  {
    (*this).piecesService = piecesService;
    (*this).indicatorService = indicatorService;
    (*this).armService = armService;
    (*this).chessGateway = chessGateway;
  }

  String readMessage()
  {
    if (piecesService.available() > 0)
    {
      return piecesService.readMessage();
    }
    if (indicatorService.available() > 0)
    {
      return indicatorService.readMessage();
    }
    return armService.readMessage();
  }
};

#endif