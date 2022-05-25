#ifndef DUSTBIN_MANAGER_HPP
#define DUSTBIN_MANAGER_HPP

#include "service/WebsocketClient.hpp"
#include "service/MasterService.hpp"

class MasterController
{
private:
  WebsocketClient wsClient;
  MasterService masterService;

public:
  MasterController(MasterService masterService, WebsocketClient wsClient)
  {
    (*this).masterService = masterService;
    (*this).wsClient = wsClient;
    (*this).wsClient.onMessage(onMessageCallback());
  }

  void loop()
  {
    wsClient.connectIfDisconnected();
    wsClient.poll();
    String message = masterService.readMessage();
    if (message != "")
    {
      // logic for message
    }
  }

private:
  PartialMessageCallback onMessageCallback()
  {
    return [&](WebsocketsMessage message)
    {
      // logic for input message
    };
  }
};

#endif