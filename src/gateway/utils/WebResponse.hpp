#ifndef WEB_RESPONSE_HPP
#define WEB_RESPONSE_HPP

#include <Arduino.h>

class WebResponse
{
public:
  bool error = false;
  String error_message;
  String payload;

  WebResponse() {}

  WebResponse(bool is_error, String err_message)
  {
    error = is_error;
    error_message = err_message;
  }

  WebResponse(String response)
  {
    payload = response;
  }
};

#endif