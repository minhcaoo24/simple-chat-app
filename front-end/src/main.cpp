#include "Constants.hpp"
#include "UseImGui.hpp"
// #include <glad/glad.h>

int main()
{
	// Setup window
	if (!glfwInit())
		return 1;

	// Decide GL+GLSL versions
	// GL 3.2 + GLSL 150
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wwritable-strings" 
	char *glsl_version = "#version 410 core";
	#pragma clang diagnostic pop
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac

	// Create window with graphics context
	GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dear ImGui - Conan", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	// 	throw("Unable to context to OpenGL");

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	UseImGui myimgui;
	myimgui.init(window, glsl_version);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		myimgui.newFrame();
		myimgui.update();
		myimgui.render();
		glfwSwapBuffers(window);
		if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
	myimgui.shutdown();

	return 0;
}