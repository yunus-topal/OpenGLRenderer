# engine/CMakeLists.txt
add_library(engine STATIC)

# Public headers exposed to apps:
target_sources(engine
        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        include/engine/engine.h
#        include/engine/scene/Camera.hpp
#        include/engine/scene/Primitives.hpp
        PRIVATE
#        src/scene/Camera.cpp
#        src/scene/Primitives.cpp
#        src/gfx/GlContext.cpp
)

target_include_directories(engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Find packages from vcpkg
find_package(OpenGL REQUIRED)
find_package(GLEW CONFIG REQUIRED)       # Provides target: GLEW::GLEW
find_package(glfw3 CONFIG REQUIRED)      # Provides target: glfw
find_package(glm CONFIG REQUIRED)        # Provides target: glm::glm

# Link everything
target_link_libraries(engine
        PRIVATE
        OpenGL::GL
        GLEW::GLEW
        glfw
        PUBLIC
        glm::glm        # glm types are commonly used in public headers
)

target_compile_features(engine PUBLIC cxx_std_20)