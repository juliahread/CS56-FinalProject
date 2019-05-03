#include "Camera.hpp"
#include <iostream>

Camera *Camera::m_camera = nullptr;

Camera::Camera(SDL_Point location, int screen_width, int screen_height) {
    m_location = location;
    m_screen_width = screen_width;
    m_screen_height = screen_height;
}

Camera::~Camera() { delete m_camera; }

Camera *Camera::get_instance() {
    if (m_camera == nullptr) {
        std::cout << "Error: Camera has not been initialized";
    }
    return m_camera;
}

Camera *Camera::get_instance(SDL_Point location, int screen_width, int screen_height) {
    if (m_camera == nullptr) {
        m_camera = new Camera(location, screen_width, screen_height);
    }
    return m_camera;
}

void Camera::update_location(SDL_Point location) {
    m_location = location;
}

SDL_Point Camera::get_location() {
    return m_location;
}

int Camera::get_width() {
    return m_screen_width;
}

int Camera::get_height() {
    return m_screen_height;
}

// int main(int argc, char** argv) {
//     SDL_Point point = {0, 0};
//     Camera *cam = Camera::get_instance(point);
//     std::cout << cam->get_location().x;
//     std::cout << cam->get_location().y;
//     SDL_Point new_pt = {1, 1};
//     cam->update_location(new_pt);
//     std::cout << cam->get_location().x;
//     std::cout << cam->get_location().y;
// }
