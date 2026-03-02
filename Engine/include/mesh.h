#pragma once 

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>

struct Vertex
{
    glm::vec3 vertices;
    glm::vec2 uv;
};

class Mesh
{
    private:

        unsigned int VAO, VBO, EBO;

        std::vector<unsigned int> indices;
        std::vector<Vertex> vertices;

    public:

        Mesh();

        void CreateCube();
        void BindBuffer();
        void UnbindBuffer();

        void Draw();

        ~Mesh();
};