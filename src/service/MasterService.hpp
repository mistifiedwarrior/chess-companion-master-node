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

  int readMessage()
  {
    return piecesService.readMessage() || indicatorService.readMessage() || armService.readMessage();
  }
};

#endif