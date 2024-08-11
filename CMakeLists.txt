cmake_minimum_required(VERSION 3.10)
project(MinecraftClone)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add GLFW
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

# Add GLAD
add_library(glad libs/glad/src/glad.c)
include_directories(libs/glad/include)

# Add GLM
include_directories(libs/glm)

# Add ImGui
add_library(imgui
    libs/imgui/imgui.cpp
    libs/imgui/imgui_demo.cpp
    libs/imgui/imgui_draw.cpp
    libs/imgui/imgui_tables.cpp
    libs/imgui/imgui_widgets.cpp
    libs/imgui/backends/imgui_impl_glfw.cpp
    libs/imgui/backends/imgui_impl_opengl3.cpp
)
include_directories(libs/imgui libs/imgui/backends libs/)

# Find all source files in the src directory
file(GLOB SOURCES
     "src/*.h"
     "src/*.cpp"
)

# Define the executable
add_executable(MinecraftClone ${SOURCES})

# Link the libraries
target_link_libraries(${PROJECT_NAME} glfw glad imgui)

# OS-specific settings
if (WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32)
elseif (UNIX)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} dl)
endif()

