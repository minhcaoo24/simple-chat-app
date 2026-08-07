#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class UseImGui
{
public:
    void init(GLFWwindow* window, char* glsl_version);
    virtual void update();
    void newFrame();
    void render();
    void shutdown();
};