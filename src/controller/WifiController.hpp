#ifndef WIFI_CONTROLLER_HPP
#define WIFI_CONTROLLER_HPP

#include "service/WifiService.hpp"

class WifiController
{
private:
  WifiService wifiService;

public:
  WifiController() {}

  WifiController(String ssid, String password)
  {
    (*this).wifiService = WifiService(ssid, password);
  }

  void connect()
  {
    wifiService.connect();
  }

  void connectIfDisconnected()
  {
    wifiService.connectIfDisconnected();
  }
};

#endif