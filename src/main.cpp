#include "controller/WifiController.hpp"
#include "controller/MasterController.hpp"
#include "service/ArmService.hpp"
#include "service/IndicatorService.hpp"
#include "service/PiecesService.hpp"
#include "service/MasterService.hpp"
#include "service/WebsocketClient.hpp"
#include "gateway/ChessGateway.hpp"

const String ssid = "Shiviraj";
const String password = "Aadii2112@#";
const String baseUrl = "198.168.1.100";
const String authorization = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJnYW1lSWQiOiJjb21wYW5pb24iLCJwbGF5ZXJJZCI6InBoeXNpY2FsIiwiaWF0IjoxNjUzMzAwMzk4fQ.EeAuXYmayVd64tYH5gNH-6Qno5PH2caGqcC97EGeGR8";
const String wsUrl = baseUrl + "/websockets?token=" + authorization;
const int baudrate = 115200;
const int piecesRx = 12, piecesTx = 13;
const int armRx = 10, armTx = 11;
const int indicatorRx = 8, indicatorTx = 9;

void setup()
{
  WifiController wifiController = WifiController(ssid, password);
  wifiController.connect();

  PiecesService piecesService = PiecesService(baudrate, piecesTx, piecesRx);
  ArmService armService = ArmService(baudrate, armTx, armRx);
  IndicatorService indicatorService = IndicatorService(baudrate, indicatorTx, indicatorRx);
  ChessGateway chessGateway = ChessGateway(baseUrl, authorization);

  MasterService masterService = MasterService(piecesService, indicatorService, armService, chessGateway);
  WebsocketClient wsClient = WebsocketClient(wsUrl);

  MasterController masterController = MasterController(masterService, wsClient);

  while (true)
  {
    wifiController.connectIfDisconnected();
    masterController.loop();
    delay(1000);
  }
}

void loop() {}