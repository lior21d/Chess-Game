#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Board.h"

class Window {
public:
    Window(const std::string& title, int width, int height);
    void create();
    void close();
    void clear();
    void display();
    bool isOpen();
    void handleEvents(std::vector<Piece*>& pieces, Board& board);
    sf::RenderWindow& getRenderWindow();
    std::vector<sf::Vector2f> possibleMoves;

    // Movement helper functions
    bool enPassantMove(Piece* selectedPiece, Board& board, Piece* capturedPiece, std::vector<Piece*>& pieces);
    bool castleMove(Piece* selectedPiece, Board& board, Piece* capturedPiece, std::vector<Piece*>& pieces);
    void capture(Piece* selectedPiece, Piece* capturedPiece, Board& board, sf::Vector2f& newPiecePos, std::vector<Piece*>& pieces);

private:
    sf::RenderWindow window;
    std::string title;
    int width;
    int height;
    
};

#endif // WINDOW_H