#pragma once 

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Graphics
{
private:

    unsigned int VAO, VBO, EBO;

public:

    Graphics();

    void CreateQuad();
    void BindBuffer();
    void UnbindBuffer();

    void Draw();

    ~Graphics();
};