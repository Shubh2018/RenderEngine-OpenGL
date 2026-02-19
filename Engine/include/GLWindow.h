#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include<string>

class GLWindow
{
    private:
    GLFWwindow* window;

    public:
        GLWindow();
        GLWindow(std::string windowName, int width, int height);

        void Terminate();

        GLFWwindow* Window();

        bool WindowShouldClose();
        ~GLWindow();
};