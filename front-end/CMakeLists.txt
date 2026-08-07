cmake_minimum_required(VERSION 3.26.0)
project(chat-app-fe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
    dependencies/glad/src/glad.c)

add_executable(chat-app-fe ${SRC_FILES})
##===================================================
add_library(imgui
    dependencies/imgui/imgui.cpp
    dependencies/imgui/imgui_draw.cpp
    dependencies/imgui/imgui_tables.cpp
    dependencies/imgui/imgui_widgets.cpp
    #backends
    dependencies/imgui/backends/imgui_impl_glfw.cpp
    dependencies/imgui/backends/imgui_impl_opengl3.cpp)

target_include_directories(chat-app-fe PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/dependencies/glad/include)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/imgui
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/backends)
    
target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(chat-app-fe PRIVATE
    imgui)
