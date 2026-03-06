#include <camera.h>

#include <iostream>

Camera::Camera()
{

}

Camera::Camera(float screenWidth, float screenHeight)
{
    cameraPos = glm::vec3(0.f, 0.f, 3.f);
    cameraFront = glm::vec3(0.f, 0.f, -1.f);
    cameraUp = glm::vec3(0.f, 1.f, 0.f);

    lastx = screenWidth / 2;
    lasty = screenHeight / 2;

    firstMouse = true;

    sensitivity = 0.1f;
}

void Camera::CameraControl(double xpos, double ypos)
{
    if(firstMouse)
    {
        xpos = lastx;
        ypos = lasty;
        firstMouse = false;
    }

    float xoffset = xpos - lastx;
    float yoffset = lasty - ypos;

    lastx = xpos;
    lasty = ypos;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
}

Camera::~Camera()
{

}