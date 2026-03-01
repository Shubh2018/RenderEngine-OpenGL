#include <mesh.h>

#include <iostream>

Mesh::Mesh()
{
    VBO = VAO = EBO = 0;

    std::cout << "Mesh Class!!" << std::endl;
}

void Mesh::CreateQuad()
{
    std::cout << "CreateQuad()" << std::endl;

    //vertices.push_back({{}, {}})

    float vertices[] = {
         1.f,  1.f, 1.f, 1.f, 1.f,
         1.f, -1.f, 1.f, 1.f, 0.f,
        -1.f, -1.f, 1.f, 0.f, 0.f,
        -1.f,  1.f, 1.f, 0.f, 1.f,

         1.f,  1.f, -1.f, 1.f, 1.f,
         1.f, -1.f, -1.f, 1.f, 0.f,
        -1.f, -1.f, -1.f, 0.f, 0.f,
        -1.f,  1.f, -1.f, 0.f, 1.f,
    };

    unsigned int indices[] = {  
        0, 1, 3,  
        1, 2, 3,
        
        4, 5, 7,
        5, 6, 7,

        0, 3, 4,
        3, 7, 4,

        1, 2, 5,
        2, 6, 5,

        7, 3, 6,
        3, 2, 6,

        0, 5, 1,
        0, 4, 5
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

void Mesh::BindBuffer()
{
    glBindVertexArray(VAO);
}

void Mesh::Draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Mesh::UnbindBuffer()
{
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    if(VAO != 0)
    {
        glDeleteVertexArrays(1, &VAO);
    }

    if(VBO != 0)
    {
        glDeleteBuffers(1, &VBO);
    }

    if(EBO != 0)
    {
        glDeleteBuffers(1, &EBO);
    }
}