#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include<string>

class Window
{
    private:
        GLFWwindow* window;

    public:
        Window();
        Window(std::string windowName, int width, int height);

        void Terminate();
        
        inline void MakeCurrent() { glfwMakeContextCurrent(window); }
        inline void SetFrameBufferCallback(GLFWframebuffersizefun fun) { glfwSetFramebufferSizeCallback(window, fun); }

        inline GLFWwindow* GetWindow() const { return window; }

        bool WindowShouldClose();
        ~Window();
};