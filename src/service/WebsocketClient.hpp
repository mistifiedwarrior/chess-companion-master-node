#ifndef WEBSOCKET_CLIENT_HPP
#define WEBSOCKET_CLIENT_HPP

#include <ArduinoWebsockets.h>
#include <ArduinoJson.h>
#include "service/Logger.hpp"

using namespace std;
ErrorCode ERROR;
using namespace websockets;

class WebsocketClient
{
private:
  Log logger;
  String url;
  WebsocketsClient wsClient = WebsocketsClient();

public:
  WebsocketClient()
  {
    connect();
  }

  WebsocketClient(String url)
  {
    (*this).url = url;
    connect();
  }

  void onMessage(PartialMessageCallback callback)
  {
    wsClient.onMessage(callback);
  }

  void connectIfDisconnected()
  {
    while (!available())
    {
      logger.error(ERROR.DD603);
      connect();
      delay(1000);
    }
  }

  void poll()
  {
    wsClient.poll();
  }

private:
  bool available()
  {
    return wsClient.available();
  }

  bool connect()
  {
    logger.info("websocket url for connection " + url);
    return wsClient.connect(url);
  }
};
#endif