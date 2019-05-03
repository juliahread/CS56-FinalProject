#include "Camera.hpp"

Camera::Camera(SDL_Point location) {
    m_location = location;
}

Camera::~Camera() {}

void Camera::update_location(SDL_Point location) {
    m_location = location;
}
