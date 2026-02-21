#pragma once

#include <glad/gl.h>

#include <iostream>
#include <string>

class Texture
{
    private:
        unsigned int m_texture;

    public:
        Texture();
        Texture(std::string texturePath, GLenum format, GLenum texture);

        void ActiveTexture(GLenum texture);

        ~Texture();
};
