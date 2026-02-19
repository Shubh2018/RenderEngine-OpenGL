#include <Graphics.h>

#include <iostream>

Graphics::Graphics()
{
    VAO = VBO = EBO = 0;

    std::cout << "Graphics Class" << std::endl;
}

void Graphics::CreatePrimitive(float *vertices, unsigned int *indices, unsigned int vertexCount, unsigned int indexCount)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * vertexCount, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * indexCount, indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Graphics::BindBuffer()
{
    glBindVertexArray(VAO);
}

void Graphics::DrawBuffer()
{
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Graphics::UnbindBuffer()
{
    glBindVertexArray(0);
}

Graphics::~Graphics()
{
    UnbindBuffer();

    VAO = VBO = EBO = 0;
}