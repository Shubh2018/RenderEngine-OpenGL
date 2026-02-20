#include <iostream>
#include <string>

#include <window.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

Window::Window()
{

}

Window::Window(std::string windowName, int width, int height)
{
    if(glfwInit() == 0)
    {
        std::cout << "GLFW Initalization Failed!" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

    if(window == NULL)
    {
        std::cout << "Window Creation Failed!" << std::endl;
        Terminate();
        return;
    }

    std::cout << "GLWindow Class"<< std::endl;
}

void Window::Terminate()
{
    glfwTerminate();
}

bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

Window::~Window()
{
    Terminate();
}