#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

class Camera
{
    private :
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;

        float yaw, pitch;
        float lastx, lasty;

        bool firstMouse;

        float xoffset;
        float yoffset;

        float sensitivity;

    public:
        Camera();
        Camera(float screenWidth, float screenHeight);

        void CameraControl(double xpos, double ypos);

        inline glm::vec3 GetPosition() const { return cameraPos; }
        inline glm::vec3 GetFront() const { return cameraFront; }
        inline glm::vec3 GetUp() const { return cameraUp; }

        inline glm::vec3 GetFrontDirection() const { return cameraPos + cameraFront; }

        inline void SetPosition(glm::vec3 newPos) { cameraPos = newPos; }

        ~Camera();
};