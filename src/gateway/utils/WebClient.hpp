#ifndef WEBCLIENT_HPP
#define WEBCLIENT_HPP

#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiClient.h>
#include "service/Logger.hpp"
#include "gateway/utils/WebResponse.hpp"

class Web_Client
{
private:
  HTTPClient https;
  Log logger;

public:
  Web_Client() {}

  WebResponse get(String base_url)
  {
    return get(base_url, "");
  }

  WebResponse get(String base_url, String path)
  {
    String url = base_url + path;
    logger.info("http get request " + url);

    if (base_url.startsWith("http://"))
    {
      WiFiClient client;
      https.begin(client, url);
    }
    else
    {
      std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
      client->setInsecure();
      https.begin(*client, url);
    }
    WebResponse response = get_response();
    https.end();
    return response;
  }

private:
  WebResponse get_response()
  {
    int httpCode = https.GET();
    if (httpCode == HTTP_CODE_OK)
    {
      String payload = https.getString();
      logger.info("status code: " + String(httpCode) + " length: " + payload.length() + " response: " + payload);
      return WebResponse(payload);
    }
    logger.info("status code: " + String(httpCode));
    return WebResponse(true, String(httpCode));
  }
};

#endif