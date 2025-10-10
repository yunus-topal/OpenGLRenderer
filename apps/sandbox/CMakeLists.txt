# in sandbox/CMakeLists.txt or top-level where sandbox is defined
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(sandbox
        main.cpp
)

target_link_libraries(sandbox PRIVATE
        engine
        imgui::imgui      # backends included because of vcpkg features
        glfw
        OpenGL::GL
)
