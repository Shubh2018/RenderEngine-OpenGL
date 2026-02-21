#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

#include <window.h>
#include <shader.h>
#include <texture.h>
#include <graphics.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    std::unique_ptr<Window> window = std::make_unique<Window>("OpenGL", SCR_WIDTH, SCR_HEIGHT);

    // window->MakeCurrent();
    window->SetFrameBufferCallback(framebuffer_size_callback);

    std::unique_ptr<Graphics> quad = std::make_unique<Graphics>();
    quad->CreateQuad();

    std::unique_ptr<Shader> shader = std::make_unique<Shader>(R"(./resources/shaders/vertex.glsl)", R"(./resources/shaders/fragment.glsl)");

    std::unique_ptr<Texture> texture1 = std::make_unique<Texture>(R"(./resources/textures/container.jpg)", GL_RGB, GL_TEXTURE0);
    std::unique_ptr<Texture> texture2 = std::make_unique<Texture>(R"(./resources/textures/awesomeface.png)", GL_RGBA, GL_TEXTURE1);

    shader->Use();

    glUniform1i(glGetUniformLocation(shader->Handle(), "tex1"), 0);
    glUniform1i(glGetUniformLocation(shader->Handle(), "tex2"), 1);

    while (!window->WindowShouldClose())
    {
        processInput(window->GetWindow());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture1->ActiveTexture(GL_TEXTURE0);
        texture2->ActiveTexture(GL_TEXTURE1);

        //shader->Use();

        quad->Draw();
 
        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

