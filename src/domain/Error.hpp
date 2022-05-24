#ifndef ERROR_HPP
#define ERROR_HPP

#include <Arduino.h>

class Error
{
public:
  String code, message;

  Error(String code, String message)
  {
    (*this).code = code;
    (*this).message = message;
  }
};

class ErrorCode
{
public:
  const Error DD600 = Error("DD-600", "Failed to get pin mapping from server."),
              DD601 = Error("DD-601", "Max retry limit exhausted."),
              DD602 = Error("DD-602", "Failed to update the dustbin filled status on server."),
              DD603 = Error("DD-603", "Web socket client is not connected."),
              DD604 = Error("DD-604", "Empty pins list."),
              DD605 = Error("DD-605", "Failed to get gate lock postion from server.");
};

#endif