#pragma once
#include "IRender.hpp"

#include <string>

class Message : IRender{
private:
  std::string content;
  bool isMine;

public:
  Message(const std::string &content, bool isMine);
  void render() override;
};