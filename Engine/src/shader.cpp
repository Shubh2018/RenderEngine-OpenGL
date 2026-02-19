#include <shader.h>

#include <iostream>

Shader::Shader()
{
    m_handle = 0;
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    std::string vertexShaderSource, fragmentShaderSource;

    std::fstream vertexFile(vertexShaderPath.c_str(), std::ios::in);
    std::fstream fragmentFile(fragmentShaderPath.c_str(), std::ios::in);

    std::string line;

    if(vertexFile.is_open())
    {
        while(getline(vertexFile, line))
        {
            vertexShaderSource.append(line);
            vertexShaderSource.append("\n");
        }

        vertexFile.close();
    }

    if(fragmentFile.is_open())
    {
        while(getline(fragmentFile, line))
        {
            fragmentShaderSource.append(line);
            fragmentShaderSource.append("\n");
        }

        fragmentFile.close();
    }

    const char* source = vertexShaderSource.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source, NULL);
    glCompileShader(vertexShader);

    CompileShader(vertexShader);

    source = fragmentShaderSource.c_str();

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source, NULL);
    glCompileShader(fragmentShader);

    CompileShader(fragmentShader);

    LinkProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

int Shader::CompileShader(unsigned int shader)
{
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR COMPILING SHADERS: " << infoLog << std::endl;
        return -1;
    }

    return 0;
}

int Shader::LinkProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    m_handle = glCreateProgram();
    glAttachShader(m_handle, vertexShader);
    glAttachShader(m_handle, fragmentShader);
    glLinkProgram(m_handle);

    glGetProgramiv(m_handle, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(m_handle, 512, NULL, infoLog);
        std::cout << "ERROR LINKING PROGRAM: " << infoLog << std::endl;
        return -1;
    }

    return 0;
}

void Shader::Use()
{
    glUseProgram(m_handle);
}

Shader::~Shader()
{
    glDeleteProgram(m_handle);
}