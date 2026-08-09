#include <imgui.h>

#include "FriendInWS.hpp"

FriendInWS::FriendInWS(const std::string &username) : username(username) {}

void FriendInWS::render() {
  // Tạo ID riêng cho từng friend
  ImGui::PushID(username.c_str());

  ImGui::Button(username.c_str(), ImVec2(-1.0f, 50.0f));

  ImGui::PopID();
}

const std::string &FriendInWS::getUsername() const { return username; }