#include "Window.h"
#include <iostream>
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


void Window::handleEvents(std::vector<Piece*>& pieces, Board& board)
{
    sf::Event event;
    static bool isDragging = false;
    static Piece* selectedPiece = nullptr;
    static sf::Vector2f originalPos;

    while (window.pollEvent(event))
    {
        // Closing the window
        if (event.type == sf::Event::Closed)
        {
            close();
        }


        // Handling piece movement
        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            {
                for (auto& piece : pieces)
                {
                    if (piece->getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        selectedPiece = piece;
                        originalPos = selectedPiece->getPosition();
                        isDragging = true;
                        // Print out possible move, just for debugging sake
                        std::cout << "Current Position: X:" << selectedPiece->getPosition().x << " Y: " << selectedPiece->getPosition().y << std::endl;

                        std::vector<sf::Vector2f> test = selectedPiece->getPossibleMoves(board, pieces);
                        for (auto& vec : test) {
                            std::cout << "X:" << vec.x << " Y:" << vec.y << std::endl;
                            std::cout << "" << std::endl;
                        }
                    }
                }
            }
        }
        // Stopped holding the piece
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
            
        }

        // Dragging
        if (isDragging && selectedPiece) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f newPiecePos = static_cast<sf::Vector2f>(mousePos) - sf::Vector2f(50, 50); // Offset piece because we grab its edge
            selectedPiece->setPosition(newPiecePos);
            
        }

        //Snapping, here we actually move the piece to the square
            if (!isDragging && selectedPiece) {
               
                sf::Vector2f newPiecePos = board.getClosestSquare(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
                
                if (newPiecePos.x >= 0 && newPiecePos.x <= 800 && newPiecePos.y >= 0 && newPiecePos.y <= 800) { // In bounds
                    
                    selectedPiece->setPosition(newPiecePos);
                    selectedPiece = nullptr;
  
                    
                }
                else {
                    selectedPiece->setPosition(originalPos);
                    selectedPiece = nullptr;
                }
        }
    }
}

sf::RenderWindow& Window::getRenderWindow() {
    return window;
}

