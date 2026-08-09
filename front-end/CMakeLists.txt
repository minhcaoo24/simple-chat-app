cmake_minimum_required(VERSION 3.26.0)
project(chat-app-fe LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp)

add_executable(chat-app-fe ${SRC_FILES})
##===================================================
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

find_library(COCOA_LIBRARY Cocoa)
find_library(OpenGL_LIBRARY OpenGL)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)
SET(EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})

#glad
add_library(glad
    dependencies/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/glad/include)
#======================================================

add_library(imgui
    dependencies/imgui/imgui.cpp
    dependencies/imgui/imgui_draw.cpp
    dependencies/imgui/imgui_tables.cpp
    dependencies/imgui/imgui_widgets.cpp
    #backends
    dependencies/imgui/backends/imgui_impl_glfw.cpp
    dependencies/imgui/backends/imgui_impl_opengl3.cpp)

target_include_directories(chat-app-fe PRIVATE 
    ${CMAKE_SOURCE_DIR}/include)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/dependencies/imgui
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/backends)

target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL)

target_link_libraries(chat-app-fe PRIVATE
    imgui
    glad
    ${EXTRA_LIBS})
