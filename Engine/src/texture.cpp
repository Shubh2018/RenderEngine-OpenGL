#include <texture.h>

#include <stb_image.h>

Texture::Texture()
{
    m_texture = 0;
}

Texture::Texture(std::string texturePath, GLenum format, GLenum texture)
{
    std::cout << "Using Texture Class!!!!" << std::endl;
    glGenTextures(1, &m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);

    stbi_set_flip_vertically_on_load(true);

    if(!data)
    {
        std::cout << "Texture Loading Failed " << stbi_failure_reason() << std::endl;
        return;
    }

    ActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void Texture::ActiveTexture(GLenum texture)
{
    glActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}