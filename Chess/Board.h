#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class Board {
public:
    Board(int squareSize);
    void draw(sf::RenderWindow& window);

    // Method to get the help snapping
    sf::Vector2f getClosestSquare(const sf::Vector2f& position) const;

    // Methods to help game logic
    float getSquareSize();
    bool isOpponentPiece(const sf::Vector2f& position, const std::vector<Piece*>& pieces, const std::string& color);
    bool isEmptySquare(const std::vector<Piece*>& pieces, const sf::Vector2f& position);
    bool isWithinBounds(const sf::Vector2f& position) const;
    Piece* getPieceAtPosition(const sf::Vector2f& position, const std::vector<Piece*>& pieces);
    bool isValidMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& newPosition);
    void showAvailableSquares(const std::vector<sf::Vector2f>& possibleMoves);
    void colorSquares();
    std::string getTurnColor();
    void setTurn(bool turn);
    bool getTurn();
    bool checkInBounds(sf::Vector2f& newPiecePos);

    // Check and mate
    Piece* findKing(const std::string& kingColor, const std::vector<Piece*>& pieces);
    bool isKingInCheck(const std::string& kingColor, const std::vector<Piece*>& pieces);
    bool isCheckmate(const std::string& kingColor, const std::vector<Piece*>& pieces);
    bool simulateMove(const sf::Vector2f& move, const std::string& kingColor, std::vector<Piece*> pieces, Piece* piece);

    // En passant 
    void updateEnPassantTarget(Piece* pawn, const sf::Vector2f& start, const sf::Vector2f& finish);
    sf::Vector2f getEnPassantTarget() const;

private:
    static const int BOARD_SIZE = 8;
    int squareSize;
    sf::RectangleShape squares[BOARD_SIZE][BOARD_SIZE];
    bool turn; // boolean for who's turn it is // white true black false
    sf::Vector2f enPassantTarget; // Square where the en passant capture is possible
};

#endif // BOARD_H

