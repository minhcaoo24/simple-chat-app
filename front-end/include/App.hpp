#include "FriendList.hpp"
#include "ChatPanel.hpp"

#include <imgui.h>
#include <GLFW/glfw3.h>

class App {
private:
    GLFWwindow* window;
    ImGuiWindowFlags window_flags;

    bool isEnable;
    char message[255] = "";

    FriendList friendList;
    ChatPanel chatPanel;
public:
    App();
    ~App();

    void init();
    void run();
    void draw();
    void dispose();
};