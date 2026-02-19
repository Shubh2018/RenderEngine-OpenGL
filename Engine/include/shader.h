#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <string>
#include <iostream>

class Shader
{
    private:
        unsigned int m_handle;

        int success;
        char infoLog[512];

        int CompileShader(unsigned int shader);
        int LinkProgram(unsigned int vertexShader, unsigned int fragmentShader);

    public:
        Shader();
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

        void Use();
        unsigned int Handle() const { return m_handle; }

        ~Shader();
};