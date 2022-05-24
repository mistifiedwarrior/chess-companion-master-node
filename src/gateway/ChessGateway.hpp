#ifndef CHESS_GATEWAY_HPP
#define CHESS_GATEWAY_HPP

#include <ArduinoJson.h>
#include <list>
#include "gateway/utils/Webclient.hpp"
#include "service/Logger.hpp"
#include "domain/Error.hpp"

class ChessGateway
{
private:
  String baseUrl, authorization;
  Log logger;

public:
  ChessGateway() {}

  ChessGateway(String baseUrl, String authorization)
  {
    (*this).baseUrl = baseUrl;
    (*this).authorization = authorization;
  }
};

#endif