#include "App.hpp"
#include "Constants.hpp"

#include <cstring>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

App::App() : isEnable(true), chatPanel("username") { init(); }

App::~App() { dispose(); }

//========================================================================================================
void App::run() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Bắt đầu Frame ImGui mới
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    draw();

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }
}

//========================================================================================================
void App::init() {
  if (!glfwInit()) {
    std::cerr << "Cannot initialize glfw" << std::endl;
    return;
  }

  // Cấu hình phiên bản OpenGL (3.3 Core Profile)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chat App", nullptr,
                            nullptr);
  if (!window) {
    std::cerr << "cannot create window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window);

#pragma region ImGui Initialization
  {
    // ImGui initialize
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NavEnableKeyboard;
    window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoTitleBar;

    // ImGui style
    ImGuiStyle &style = ImGui::GetStyle();
    style.FrameRounding = 6.0f;
    ImGui::StyleColorsDark();

    // ImGui backend
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
  }
#pragma endregion

  //   chatPanel.addMessage("friend message", false);

  //   chatPanel.addMessage("my message", true);
  friendList.addFriend("friend who joins ws");
}

//========================================================================================================
void App::draw() {
  if (isEnable) {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::Begin("Messenger", &isEnable, window_flags);

    // left-side
    {
      ImGui::BeginChild("left-side",
                        ImVec2(ImGui::GetContentRegionAvail().x / 2.5f, 0));
      friendList.render();
      ImGui::EndChild();
    }

    ImGui::SameLine();

    // right-side
    {
      //   ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(1, 1, 1, 0.2f));

      ImGui::BeginChild("right-side", ImVec2(0, 0));
      chatPanel.render();

      // #pragma region chat message
      //       {
      //         ImGui::SetCursorPos(ImVec2(0, ImGui::GetContentRegionAvail().y
      //         - 30)); ImGui::BeginChild("chat-message",
      //                           ImVec2(ImGui::GetContentRegionAvail().x,
      //                           30));

      //         ImGui::SetCursorPos(ImVec2(120, 5));
      //         bool send = ImGui::InputText("##message", message,
      //         sizeof(message)); ImGui::SameLine(); if (ImGui::Button("Send")
      //         || glfwGetKey(window, GLFW_KEY_ENTER)) {
      //           if (strlen(message) > 0) {
      //             std::cout << message << "\n";
      //             message[0] = '\0';
      //           }
      //         }

      //         ImGui::EndChild();
      //       }
      // #pragma endregion chat message

      ImGui::EndChild();

      //   ImGui::PopStyleColor();
    }

    ImGui::End();
  }
}

//========================================================================================================
void App::dispose() {
  isEnable = false;
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();
}