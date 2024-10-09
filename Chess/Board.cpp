#include "Board.h"
#include "iostream"
#include "Pawn.h"

Board::Board(int squareSize)
    : squareSize(squareSize), turn(true), enPassantTarget(-1,-1) {

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            squares[row][col].setSize(sf::Vector2f(static_cast<float>(squareSize), static_cast<float>(squareSize))); // 100x100px
            squares[row][col].setPosition(static_cast<float>(col) * static_cast<float>(squareSize), static_cast<float>(row) * static_cast<float>(squareSize));

            // Color the board
            colorSquares();


        }
    }

}




void Board::draw(sf::RenderWindow& window) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            window.draw(squares[row][col]);
        }
    }
}



sf::Vector2f Board::getClosestSquare(const sf::Vector2f& position) const {

    int col = static_cast<int>(position.x / squareSize);
    int row = static_cast<int>(position.y / squareSize);

    // Calculate the top-left corner of the square
    float xCorner = static_cast<float>(col) * squareSize;
    float yCorner = static_cast<float>(row) * squareSize;

    return sf::Vector2f(xCorner, yCorner);
}

bool Board::isOpponentPiece(const sf::Vector2f& position, const std::vector<Piece*>& pieces, const std::string& color) {
    for (const auto& piece : pieces) {
        if (piece->getPosition() == position && piece->getColor() != color) {
            return true;
        }
    }
   return false;
}

bool Board::isEmptySquare(const std::vector<Piece*>& pieces, const sf::Vector2f& position)
{
    for (const auto& piece : pieces) {
        if (piece->getPosition() == position) {
            return false;
        }
    }
    return true;
}

bool Board::isWithinBounds(const sf::Vector2f& position) const {
    float x = position.x / squareSize;
    float y = position.y / squareSize;

    // Check if position of a piece is within the board bounds
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

Piece* Board::getPieceAtPosition(const sf::Vector2f& position, const std::vector<Piece*>& pieces)
{
    for (const auto& piece : pieces)
    {
        if (piece->getPosition() == position) {
            return piece;
        }
    }
    return nullptr;
}

bool Board::isValidMove(const std::vector<sf::Vector2f>& possibleMoves, const sf::Vector2f& newPosition)
{
    for (const auto& move : possibleMoves) {
        if (move == newPosition) {
            return true;  // The new position is a valid move
        }
    }
    return false;  // The new position is not in the list of possible moves
}

void Board::showAvailableSquares(const std::vector<sf::Vector2f>& possibleMoves)
{
    // Color all available squares
    const sf::Color availableColor = sf::Color(178, 199, 148, 255);
    for (const auto& pos : possibleMoves) {
        if (squares[static_cast<int>(pos.y) / squareSize][static_cast<int>(pos.x) / squareSize].getFillColor() == sf::Color(118, 150, 86, 255)) // Green
        {
            squares[static_cast<int>(pos.y) / squareSize][static_cast<int>(pos.x) / squareSize].setFillColor(sf::Color(118, 150, 86, 190));
        }
        else if (squares[static_cast<int>(pos.y) / squareSize][static_cast<int>(pos.x) / squareSize].getFillColor() == sf::Color(238, 238, 210, 255)) // White
        {
            squares[static_cast<int>(pos.y) / squareSize][static_cast<int>(pos.x) / squareSize].setFillColor(sf::Color(238, 238, 210, 190));
        }
    }

}

void Board::colorSquares()
{
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {

            // Color the board, mainly used to reset the colors
            const sf::Color green = sf::Color(118, 150, 86, 255);
            const sf::Color white = sf::Color(238, 238, 210, 255);
            if ((row + col) % 2 != 0) {
                squares[row][col].setFillColor(green); // Green
            }
            else {
                squares[row][col].setFillColor(white); // White
            }
        }
    }
}

std::string Board::getTurnColor()
{
    if (turn)
    {
        return "white";
    }
    else {
        return "black";
    }
}

void Board::setTurn(bool turn)
{
    this->turn = turn;
}

bool Board::getTurn()
{
    return turn;
}

void Board::updateEnPassantTarget(Piece* pawn, const sf::Vector2f& start, const sf::Vector2f& finish)
{
    // Check if a pawn moved two squares forward
    if (abs(finish.y - start.y) == 200 && dynamic_cast<Pawn*>(pawn))
    {
        // Set enPassantTarget to the square the pawn skipped over
        enPassantTarget = sf::Vector2f(start.x, (start.y + finish.y) / 2);

    }
    else {
        // Reset if no valid en passant move
        enPassantTarget = sf::Vector2f(-1, -1);
    }

}

sf::Vector2f Board::getEnPassantTarget() const
{
    return enPassantTarget;
}









