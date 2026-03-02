#include <mesh.h>

#include <iostream>

Mesh::Mesh()
{
    VBO = VAO = EBO = 0; 
}

void Mesh::CreateCube()
{
    vertices.insert(
        vertices.end(), {
        //Front    
         1.f,  1.f, 1.f, 1.f, 1.f,
         1.f, -1.f, 1.f, 1.f, 0.f,
        -1.f, -1.f, 1.f, 0.f, 0.f,
        -1.f,  1.f, 1.f, 0.f, 1.f,

        //Back
         1.f,  1.f, -1.f, 1.f, 1.f,
         1.f, -1.f, -1.f, 1.f, 0.f,
        -1.f, -1.f, -1.f, 0.f, 0.f,
        -1.f,  1.f, -1.f, 0.f, 1.f,

        //Left
        -1.f, -1.f,  1.f, 1.f, 1.f,
        -1.f,  1.f,  1.f, 1.f, 0.f,
        -1.f,  1.f, -1.f, 0.f, 0.f,
        -1.f, -1.f, -1.f, 0.f, 1.f,

        //Right
         1.f, -1.f,  1.f, 1.f, 1.f,
         1.f,  1.f,  1.f, 1.f, 0.f,
         1.f,  1.f, -1.f, 0.f, 0.f,
         1.f, -1.f, -1.f, 0.f, 1.f,

        //Top
         1.f,  1.f, -1.f, 1.f, 1.f,
         1.f,  1.f,  1.f, 1.f, 0.f,
        -1.f,  1.f,  1.f, 0.f, 0.f,
        -1.f,  1.f, -1.f, 0.f, 1.f,

        //Bottom
         1.f, -1.f,  1.f, 1.f, 1.f,
         1.f, -1.f, -1.f, 1.f, 0.f,
        -1.f, -1.f, -1.f, 0.f, 0.f,
        -1.f, -1.f,  1.f, 0.f, 1.f,
    });

    indices.insert(
        indices.end(), { 
        0, 1, 3,  
        1, 2, 3,
        
        4, 5, 7,
        5, 6, 7,

        8, 9, 11,
        9, 10, 11,

        12, 13, 15,
        13, 14, 15,

        16, 17, 19,
        17, 18, 19,

        20, 21, 23,
        21, 22, 23
    });  

    std::cout << vertices.size() * sizeof(vertices.front()) << " " << sizeof(float) << std::endl;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices.front()), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices.front()), indices.data(), GL_STATIC_DRAW);

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