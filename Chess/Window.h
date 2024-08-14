#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window {
public:
    Window(const std::string& title, int width, int height);
    void create();
    void close();
    void clear();
    void display();
    bool isOpen();
    void handleEvents();
    sf::RenderWindow& getRenderWindow();

private:
    sf::RenderWindow window;
    std::string title;
    int width;
    int height;
};

#endif // WINDOW_H