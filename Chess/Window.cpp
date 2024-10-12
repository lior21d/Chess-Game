#include "Window.h"
#include <iostream>
#include "Pawn.h"
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
    static sf::Vector2f originalPos;
    static Piece* selectedPiece = nullptr;
    static Piece* capturedPiece = nullptr;
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
                    
                    if (piece->getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && board.getTurnColor() == piece->getColor()) {
                        selectedPiece = piece;
                        selectedPiece->getPossibleMoves(board, pieces, possibleMoves);
                        originalPos = selectedPiece->getPosition();
                        isDragging = true;
                        // Show the squares that are available
                        board.showAvailableSquares(possibleMoves);
                    }
                }
            }
            
        }
        // Stopped holding the piece
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            isDragging = false;
            // Reset squares after stopping to drag
            board.colorSquares();
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
                // Check if piece is able to move to new position
                
                if (board.isWithinBounds(newPiecePos) && board.isValidMove(possibleMoves, newPiecePos)) { // In bounds and possible
                    
                    
                    // Check for enPassant capture
                    capturedPiece = board.getPieceAtPosition(newPiecePos, pieces);
                    
                    selectedPiece->setPosition(newPiecePos);

                    // Check if en passant was made
                    if (selectedPiece->getPosition() == board.getEnPassantTarget() && dynamic_cast<Pawn*>(selectedPiece))
                    {
                        sf::Vector2f enPassantCapturePos = selectedPiece->getPosition();
                        // Get enPassantCapturePos relative to your selectedPiece
                        selectedPiece->getColor() == "white" ? enPassantCapturePos.y += board.getSquareSize() : enPassantCapturePos.y -= board.getSquareSize();

                        capturedPiece = board.getPieceAtPosition(enPassantCapturePos, pieces);
                        if (capturedPiece && board.isOpponentPiece(enPassantCapturePos, pieces, selectedPiece->getColor()))
                        {
                            // Made en passant
                            pieces.erase(std::remove(pieces.begin(), pieces.end(), capturedPiece), pieces.end());
                            capturedPiece = nullptr;
                        }
                    }

                    // Check for capture, if there is capturing, remove captured piece
                    
                    else if (capturedPiece && board.isOpponentPiece(newPiecePos, pieces, selectedPiece->getColor()))
                    {
                        // Capturing
                        pieces.erase(std::remove(pieces.begin(), pieces.end(), capturedPiece), pieces.end());
                        capturedPiece = nullptr;
                    }
                    
                    // Check for new possible En passant target
                    board.updateEnPassantTarget(selectedPiece, originalPos, newPiecePos);

                    // Update pawn's first move property
                    if (dynamic_cast<Pawn*>(selectedPiece))
                    {
                        dynamic_cast<Pawn*>(selectedPiece)->setFirstMove(false);
                    }
                    selectedPiece = nullptr;
                        
                    // Make others player turn
                    board.setTurn(!board.getTurn());
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


