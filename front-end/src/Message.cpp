#include <imgui.h>

#include "Message.hpp"

Message::Message(const std::string &content, bool isMine)
    : content(content), isMine(isMine) {}

void Message::render() {
  const float windowWidth = ImGui::GetContentRegionAvail().x;

  if (isMine) {
    // Đẩy message sang bên phải
    float textWidth = ImGui::CalcTextSize(content.c_str()).x;

    float x = ImGui::GetCursorPosX() + windowWidth - textWidth - 20.0f;

    ImGui::SetCursorPosX(x);

    ImGui::Button(content.c_str(), ImVec2(textWidth + 20.0f, 45.0f));
  } else {
    // Message của friend bên trái
    ImGui::Button(content.c_str(), ImVec2(200.0f, 45.0f));
  }

  ImGui::Spacing();
}