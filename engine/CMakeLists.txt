# engine/CMakeLists.txt
add_library(engine STATIC)

# Public headers exposed to apps:
target_sources(engine
        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/engine/engine.h
        PRIVATE
#           src/scene/Camera.cpp

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
find_package(spdlog CONFIG REQUIRED)      # spdlog::spdlog or ::spdlog_header_only

# Link everything
target_link_libraries(engine
        PRIVATE
            OpenGL::GL
            GLEW::GLEW
            glfw
            spdlog::spdlog_header_only  # or spdlog::spdlog if you prefer compiled
        PUBLIC
            glm::glm        # glm types are commonly used in public headers
)

target_compile_features(engine PUBLIC cxx_std_20)

# Compile-time log level control (optional, but handy)
# DEBUG: verbose logs; RELEASE: warnings+errors only
target_compile_definitions(engine
        PUBLIC
        $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE>
        $<$<CONFIG:RelWithDebInfo>:SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO>
        $<$<CONFIG:Release>:SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_WARN>
)