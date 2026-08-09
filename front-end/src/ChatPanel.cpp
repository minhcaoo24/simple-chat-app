#include "ChatPanel.hpp"

#include <cstring>
#include <imgui.h>

ChatPanel::ChatPanel(const std::string &friendUsername)
    : friendUsername(friendUsername) {
  std::memset(inputBuffer, 0, sizeof(inputBuffer));
}

void ChatPanel::addMessage(const std::string &text, bool isMine) {
  messages.push_back(std::make_unique<Message>(text, isMine));
}

void ChatPanel::render() {

  // =========================
  // Messages
  // =========================

  ImGui::BeginChild("Messages", ImVec2(0, -65), true);

  for (auto &message : messages) {
    message->render();
  }

  // Tự động scroll xuống cuối
  if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
    ImGui::SetScrollHereY(1.0f);
  }

  ImGui::EndChild();

  // =========================
  // Input
  // =========================

  ImGui::BeginChild("InputArea", ImVec2(0, 60), false);

  ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - 70);

  ImGui::SetCursorPos(ImVec2(25, 0));

  ImGui::InputText("##message", inputBuffer, sizeof(inputBuffer));

  ImGui::SameLine();

  if (ImGui::Button("Send")) {
    if (std::strlen(inputBuffer) > 0) {
      addMessage(inputBuffer, true);

      std::memset(inputBuffer, 0, sizeof(inputBuffer));
    }
  }

  ImGui::EndChild();
}