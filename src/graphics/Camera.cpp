#include "graphics/Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <iostream>

Camera::Camera()
    : m_position(0.0f, 2.0f, 6.0f),
      m_front(0.0f, 0.0f, -1.0f),
      m_up(0.0f, 1.0f, 0.0f),
      m_worldUp(0.0f, 1.0f, 0.0f),
      m_yaw(-90.0f),
      m_pitch(-15.0f),
      m_speed(5.0f),
      m_sensitivity(0.1f),
      m_aspectRatio(1280.0f / 720.0f)
{
    //m_pitch = -15.0f;
    updateVectors();

    m_projection = glm::perspective(
        glm::radians(45.0f),
        m_aspectRatio,
        0.1f,
        100.0f
    );
}

void Camera::update(float dt)
{   std::cout
        << m_position.x << " "
        << m_position.y << " "
        << m_position.z << std::endl;
    m_view = glm::lookAt(
        m_position,
        m_position + m_front,
        m_up
    );
}

void Camera::setAspectRatio(float aspect)
{
    m_aspectRatio = aspect;

    m_projection = glm::perspective(
        glm::radians(45.0f),
        m_aspectRatio,
        0.1f,
        100.0f
    );
}

const glm::vec3& Camera::getPosition() const
{
    return m_position;
}

const glm::mat4& Camera::getViewMatrix() const
{
    return m_view;
}

const glm::mat4& Camera::getProjectionMatrix() const
{
    return m_projection;
}

glm::vec3 Camera::getForward() const
{
    return m_front;
}

glm::vec3 Camera::getRight() const
{
    return m_right;
}

glm::vec3 Camera::getUp() const
{
    return m_up;
}

void Camera::processMouse(float xoffset, float yoffset)
{
    xoffset *= m_sensitivity;
    yoffset *= m_sensitivity;

    m_yaw   += xoffset;
    m_pitch += yoffset;

    if (m_pitch > 89.0f) m_pitch = 89.0f;
    if (m_pitch < -89.0f) m_pitch = -89.0f;

    updateVectors();
}

void Camera::processKeyboard(const glm::vec3& dir, float dt)
{
    float velocity = m_speed * dt;

    // Only move in the XZ plane
    glm::vec3 forward =
    {
        m_front.x,
        0.0f,
        m_front.z
    };

    forward = glm::normalize(forward);
    // Only move in the XZ plane
    //m_front = forward;
    m_position += forward * dir.z * velocity;//m_position += m_front * dir.z * velocity;
    m_position += m_right * dir.x * velocity;
    //m_position += m_up * dir.y * velocity;
}

void Camera::updateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up    = glm::normalize(glm::cross(m_right, m_front));
}