#include "Window.h"

Window::Window(const std::string& title, int width, int height)
    : title(title), width(width), height(height) {}

void Window::create() {
    window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
}

void Window::close() {
    window.close();
}

void Window::clear() {
    window.clear();
}

void Window::display() {
    window.display();
}

bool Window::isOpen() {
    return window.isOpen();
}

void Window::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            close();
        }
    }
}

sf::RenderWindow& Window::getRenderWindow() {
    return window;
}