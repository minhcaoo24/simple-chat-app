#pragma once
#include "IRender.hpp"

#include <string>

class FriendInWS : IRender {
private:
  std::string username;

public:
  FriendInWS(const std::string &username);
  void render();
  const std::string &getUsername() const;
};