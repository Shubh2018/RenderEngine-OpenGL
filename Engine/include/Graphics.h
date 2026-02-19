#pragma once 

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Graphics
{
    private:

    unsigned int VAO, VBO, EBO;

    public:

    Graphics();

    void CreatePrimitive(float *vertices, unsigned int *indices, unsigned int vertexCound, unsigned int indexCound);
    void BindBuffer();
    void UnbindBuffer();

    void DrawBuffer();

    ~Graphics();
};