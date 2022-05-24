#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <ESP8266WiFi.h>
#include "service/Logger.hpp"

class WifiService
{
private:
  Log logger = Log();
  String ssid, password;

public:
  WifiService() {}

  WifiService(String ssid, String password)
  {
    (*this).ssid = ssid;
    (*this).password = password;
  }

  wl_status_t connect()
  {
    WiFi.begin(ssid, password);
    while (status() != WL_CONNECTED)
    {
      logger.info(".....");
      logger.info(status_as_string());
      delay(1000);
    }
    logger.info("Connected");
    return status();
  }

  wl_status_t status()
  {
    return WiFi.status();
  }

  wl_status_t connectIfDisconnected()
  {
    if (status() != WL_CONNECTED)
    {
      logger.warn("wifi is not connected, current status is: " + status_as_string());
      connect();
    }
    return status();
  }

  String status_as_string()
  {
    switch (status())
    {
    case WL_NO_SHIELD:
      return "WL_NO_SHIELD";
    case WL_IDLE_STATUS:
      return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL:
      return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED:
      return "WL_SCAN_COMPLETED";
    case WL_CONNECTED:
      return "WL_CONNECTED";
    case WL_CONNECT_FAILED:
      return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST:
      return "WL_CONNECTION_LOST";
    case WL_WRONG_PASSWORD:
      return "WL_WRONG_PASSWORD";
    case WL_DISCONNECTED:
      return "WL_DISCONNECTED";
    default:
      return "NOT_FOUND";
    }
  }
};

#endif