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

void Window::handleEvents(std::vector<Piece*>& pieces, Board& board) {
    sf::Event event;
    static bool isDragging = false;
    static Piece* selectedPiece = nullptr;
    static sf::Vector2f mouseOffset;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (auto& piece : pieces)
            {
                if (piece->getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    selectedPiece = piece;
                    isDragging = true;
                    mouseOffset = selectedPiece->getPosition() - static_cast<sf::Vector2f>(mousePos);
                    break;
                }
            }
        }

        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            isDragging = false;
            if (selectedPiece)
            {
                // Snap
                sf::Vector2f newPosition = board.getClosestSquareCenter(selectedPiece->getPosition());
                selectedPiece->setPosition(newPosition);
                selectedPiece = nullptr;
            }
        }
        if (isDragging && selectedPiece) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            selectedPiece->setPosition(static_cast<sf::Vector2f>(mousePos) + mouseOffset);
        }

    }

}

sf::RenderWindow& Window::getRenderWindow() {
    return window;
}

