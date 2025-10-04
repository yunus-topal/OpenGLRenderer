cmake_minimum_required(VERSION 3.21)
project(OpenGLRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages from vcpkg
find_package(OpenGL REQUIRED)
find_package(GLEW CONFIG REQUIRED)       # Provides target: GLEW::GLEW
find_package(glfw3 CONFIG REQUIRED)      # Provides target: glfw
find_package(glm CONFIG REQUIRED)        # Provides target: glm::glm

add_executable(opengl_renderer src/main.cpp)

# Link everything
target_link_libraries(opengl_renderer
        PRIVATE
        OpenGL::GL
        GLEW::GLEW
        glfw
        glm::glm
)

# Helpful warnings
if (MSVC)
    target_compile_options(opengl_renderer PRIVATE /W4 /permissive-)
else()
    target_compile_options(opengl_renderer PRIVATE -Wall -Wextra -Wpedantic)
endif()

# On macOS, request a modern GL at compile-time (runtime hints are in main.cpp)
if(APPLE)
    target_compile_definitions(opengl_renderer PRIVATE MACOS)
endif()