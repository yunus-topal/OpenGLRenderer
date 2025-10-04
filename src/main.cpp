#include <iostream>

// Include GLEW before GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

int main() {

    std::cout << "Hello World!" << std::endl;
    // --- GLFW setup ---
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    // Request a modern context (3.3 core); adjust as needed
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // macOS requirement
    #endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL + GLFW + GLEW + GLM", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // vsync

    // --- GLEW setup (after a valid context exists) ---
    glewExperimental = GL_TRUE; // core profile needs this
    GLenum glewStatus = glewInit();
    // glewInit may generate a benign GL_INVALID_ENUM error; clear it
    glGetError();

    if (glewStatus != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: "
                  << reinterpret_cast<const char*>(glewGetErrorString(glewStatus)) << "\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // Print context info
    std::cout << "Renderer: "  << glGetString(GL_RENDERER)  << "\n";
    std::cout << "Version: "   << glGetString(GL_VERSION)   << "\n";
    std::cout << "GLSL: "      << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // Clear to a pleasant dark-ish gray
        glClearColor(0.12f, 0.14f, 0.18f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // TODO: draw your stuff here

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
