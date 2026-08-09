#pragma once

#include "Message.hpp"

#include <string>
#include <vector>
#include <memory>

class ChatPanel {
private:
  std::string friendUsername;
  std::vector<std::unique_ptr<Message>> messages;
  char inputBuffer[512];

public:
  ChatPanel(const std::string &friendUsername);
  void render();
  void addMessage(const std::string &text, bool isMine);
};