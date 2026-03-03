#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <memory>

#include <window.h>
#include <shader.h>
#include <texture.h>
#include <mesh.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(0.f, 0.f, 3.f);
glm::vec3 cameraFront = glm::vec3(0.f, 0.f, -1.f);
glm::vec3 cameraUp = glm::vec3(0.f, 1.f, 0.f);

float deltaTime = 0.f;
float lastFrame = 0.f;

int main()
{
    std::unique_ptr<Window> window = std::make_unique<Window>("OpenGL", SCR_WIDTH, SCR_HEIGHT);

    // window->MakeCurrent();
    window->SetFrameBufferCallback(framebuffer_size_callback);

    std::unique_ptr<Mesh> quad = std::make_unique<Mesh>();
    quad->CreateCube();

    std::unique_ptr<Shader> shader = std::make_unique<Shader>(R"(./resources/shaders/vertex.glsl)", R"(./resources/shaders/fragment.glsl)");

    std::unique_ptr<Texture> texture1 = std::make_unique<Texture>(R"(./resources/textures/container.jpg)", GL_RGB, GL_TEXTURE0);
    std::unique_ptr<Texture> texture2 = std::make_unique<Texture>(R"(./resources/textures/awesomeface.png)", GL_RGBA, GL_TEXTURE1);

    shader->Use();

    glUniform1i(glGetUniformLocation(shader->Handle(), "tex1"), 0);
    glUniform1i(glGetUniformLocation(shader->Handle(), "tex2"), 1);

    glEnable(GL_DEPTH_TEST);

    // glm::vec3 cameraTarget = glm::vec3(0.f, 0.f, 0.f);
    // glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

    // glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
    // glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

    // glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

    while (!window->WindowShouldClose())
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window->GetWindow());

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model(1.f);
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(1.f, 0.f, 0.f));
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

        glm::mat4 view(1.f);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        glm::mat4 projection(1.f);
        projection = glm::perspective(glm::radians(45.0f), 800.f / 600.f, 0.1f, 100.0f);

        int modelLocation = glGetUniformLocation(shader->Handle(), "model");
        int viewLocation = glGetUniformLocation(shader->Handle(), "view");
        int projectionLocation = glGetUniformLocation(shader->Handle(), "projection");

        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

        shader->Use();

        texture1->ActiveTexture(GL_TEXTURE0);
        texture2->ActiveTexture(GL_TEXTURE1);

        quad->Draw();
 
        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    const float cameraSpeed = 2.5f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos += glm::cross(cameraUp, cameraFront) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos -= glm::cross(cameraUp, cameraFront) * cameraSpeed;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

