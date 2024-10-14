#include "Board.h"
#include "iostream"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"

Board::Board(int squareSize)
    : squareSize(squareSize), turn(true), enPassantTarget(-1, -1) {

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

bool Board::checkInBounds(sf::Vector2f& newPiecePos)
{
    return (newPiecePos.x >= 0 && newPiecePos.x <= 800 && newPiecePos.y >= 0 && newPiecePos.y <= 800);
}

float Board::getSquareSize()
{
    return static_cast<float>(squareSize);
}


void Board::updateEnPassantTarget(Piece* pawn, const sf::Vector2f& start, const sf::Vector2f& finish)
{
    // Check if a pawn moved two squares forward
    if (abs(finish.y - start.y) == 2 * squareSize && dynamic_cast<Pawn*>(pawn))
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


Piece* Board::findKing(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    for (Piece* piece : pieces)
    {
        if (dynamic_cast<King*>(piece) && piece->getColor() == kingColor)
        {
            return piece;
        }
    }
    return nullptr;
}

bool Board::isKingInCheck(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    Piece* king = findKing(kingColor, pieces);
    if (king != nullptr) {
        sf::Vector2f kingPosition = king->getPosition();

        // Check each pieces position and check if king is in check
        for (const auto& piece : pieces)
        {
            if (piece->getColor() != kingColor) // Opponent pieces
            {
                std::vector<sf::Vector2f> possibleMoves;
                piece->getPossibleMoves(*this, pieces, possibleMoves);
                if (std::find(possibleMoves.begin(), possibleMoves.end(), kingPosition) != possibleMoves.end())
                {
                    return true; // King is in check
                }
            }
        }
    }

    return false;
}

bool Board::isCheckmate(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    // Need to check if any possible move that a player can do will uncheck the king, if not then its checkmate and game over

    // First check for a check, if there is no check no point in checking for a checkmate
    if (!isKingInCheck(kingColor, pieces))
    {
        return false;
    }

    // King is indeed in check so we will simulate each move, and if it unchecks the king its not checkmate
    // Iterate through each piece
    for (const auto& piece : pieces)
    {
        if (piece->getColor() == kingColor)
        {
            // Iterate through each pieces move
            std::vector<sf::Vector2f> possibleMoves;
            piece->getPossibleMoves(*this, pieces, possibleMoves);
            for (const auto& move : possibleMoves)
            {
                // Simualte each move and check if it removes the check
                if (!simulateMove(move, kingColor, pieces, piece))
                {
                    return false; // There is a move that removes the check
                }
            }
        }
    }

    if (!simulateCastleMove(kingColor, pieces))
    {
        return false; // Castling removes the check
    }

    return true; // No possible move to remove the check hence its mate and the game is over
}

bool Board::simulateMove(const sf::Vector2f& move, const std::string& kingColor, std::vector<Piece*> pieces, Piece* piece)
{
    // Store the original position to revert back to it after simulation is done
    sf::Vector2f originalPosition = piece->getPosition();

    // Temporary variable for captured piece (to restore it later)
    Piece* capturedPiece = nullptr;

    // Check for enemy piece in the move we are about to perform
    if (isOpponentPiece(move, pieces, kingColor))
    {
        // Will capture
        Piece* capturedPiece = getPieceAtPosition(move, pieces);

        // Remove it and set the piece to its new position and check if it removes check
        if (capturedPiece)
        {
            // Remove the captured piece from the simulated 'pieces' vector
            pieces.erase(std::remove(pieces.begin(), pieces.end(), capturedPiece), pieces.end());

        }

    }

    // Piece is free to move there without capture
    piece->setPosition(move);


    bool isKingStillInCheck = isKingInCheck(kingColor, pieces);

    // Restore to original position
    piece->setPosition(originalPosition);
    if (capturedPiece)
    {
        pieces.push_back(capturedPiece);
    }

    // Return whether the king is still in check after the move
    return isKingStillInCheck;
}

bool Board::simulateCastleMove(const std::string& kingColor, std::vector<Piece*> pieces)
{
    bool checkKingSide = true;
    bool checkQueenSide = true;
    // Check for king side
    if (canCastleKingSide(kingColor, pieces))
    {
        sf::Vector2f originalKingPosition = findKing(kingColor, pieces)->getPosition();
        sf::Vector2f originalRookPosition = sf::Vector2f(7 * squareSize, originalKingPosition.y);

        // Move the pieces
        Piece* rook = getPieceAtPosition(originalRookPosition, pieces);
        rook->setPosition(sf::Vector2f(5 * squareSize, originalRookPosition.y));
        Piece* king = findKing(kingColor, pieces);
        king->setPosition(sf::Vector2f(6 * squareSize, originalKingPosition.y));
        checkKingSide = isKingInCheck(kingColor, pieces);
    }
    // Check for queen side
    if (canCastleQueenSide(kingColor, pieces))
    {
        sf::Vector2f originalKingPosition = findKing(kingColor, pieces)->getPosition();
        sf::Vector2f originalRookPosition = sf::Vector2f(0, originalKingPosition.y);

        // Move the pieces
        Piece* rook = getPieceAtPosition(originalRookPosition, pieces);
        rook->setPosition(sf::Vector2f(3 * squareSize, originalRookPosition.y));
        Piece* king = findKing(kingColor, pieces);
        king->setPosition(sf::Vector2f(2 * squareSize, originalKingPosition.y));
        checkQueenSide = isKingInCheck(kingColor, pieces);

    }
    return (checkKingSide && checkQueenSide);
}

bool Board::isKingSide(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    if (kingColor == "white")
    {
        // Check for white kingside
        Piece* rook = getPieceAtPosition(sf::Vector2f(7 * squareSize, 7 * squareSize), pieces);
        if (rook && dynamic_cast<Rook*>(rook) && dynamic_cast<Rook*>(rook)->hasMoved == false)
        {
            // Rook kingside
            return true;
        }
    }
    else if (kingColor == "black")
    {
        // Check for black kingside
        Piece* rook = getPieceAtPosition(sf::Vector2f(7 * squareSize, 0), pieces);
        if (rook && dynamic_cast<Rook*>(rook) && dynamic_cast<Rook*>(rook)->hasMoved == false)
        {
            // Rook kingside
            return true;
        }
    }
    return false;
}

bool Board::isQueenSide(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    if (kingColor == "white")
    {
        // Check for white queen side
        Piece* rook = getPieceAtPosition(sf::Vector2f(0, 7 * squareSize), pieces);
        if (rook && dynamic_cast<Rook*>(rook) && dynamic_cast<Rook*>(rook)->hasMoved == false)
        {
            // Rook queen side
            return true;
        }
    }
    else if (kingColor == "black")
    {
        // Check for black queen side
        Piece* rook = getPieceAtPosition(sf::Vector2f(0, 0), pieces);
        if (rook && dynamic_cast<Rook*>(rook) && dynamic_cast<Rook*>(rook)->hasMoved == false)
        {
            // Rook queen side
            return true;
        }
    }
    return false;
}

bool Board::canCastleKingSide(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    // Find the king
    Piece* king = findKing(kingColor, pieces);

    // Check if the king hasn't moved
    if (king && dynamic_cast<King*>(king)->hasMoved == true)
    {
        return false;
    }

    // Check for king side white side
    if (isKingSide(kingColor, pieces) && kingColor == "white")
    {
        // Check empty squares between
        std::vector<sf::Vector2f> squaresBetween;
        squaresBetween.push_back(sf::Vector2f(5 * squareSize, 7 * squareSize));
        squaresBetween.push_back(sf::Vector2f(6 * squareSize, 7 * squareSize));
        for (const auto& square : squaresBetween)
        {
            if (!isEmptySquare(pieces, square))
            {
                return false; // Cant castle because piece inbetween rook and king
            }
        }

        // Check if the king/squares he has to move through are under attack
        squaresBetween.push_back(findKing("white",pieces)->getPosition());
        std::vector<sf::Vector2f> possibleMoves;
        for (const auto& piece : pieces)
        {
            if (piece->getColor() != kingColor)
            {
                piece->getPossibleMoves(*this, pieces, possibleMoves);
                for (const auto& move : possibleMoves)
                {
                    for (const auto& square : squaresBetween)
                    {
                        if (square == move)
                        {
                            // Square/king are attacked
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Check for king side black side

    if (isKingSide(kingColor, pieces) && kingColor == "black")
    {
        // Check empty squares between
        std::vector<sf::Vector2f> squaresBetween;
        squaresBetween.push_back(sf::Vector2f(5 * squareSize, 0));
        squaresBetween.push_back(sf::Vector2f(6 * squareSize, 0));
        for (const auto& square : squaresBetween)
        {
            if (!isEmptySquare(pieces, square))
            {
                return false; // Cant castle because piece inbetween rook and king
            }
        }

        // Check if the king/squares he has to move through are under attack
        squaresBetween.push_back(findKing("black", pieces)->getPosition());
        std::vector<sf::Vector2f> possibleMoves;
        for (const auto& piece : pieces)
        {
            if (piece->getColor() != kingColor)
            {
                piece->getPossibleMoves(*this, pieces, possibleMoves);
                for (const auto& move : possibleMoves)
                {
                    for (const auto& square : squaresBetween)
                    {
                        if (square == move)
                        {
                            // Square/king are attacked
                            return false;
                        }
                    }
                }
            }
        }
    }
    // If none of the squares are attacked, king isnt attacked (checked), the squares between the king and the rook are empty,
    // and they both didn't move we can conclude that we can do a kingside castle
    return true;

}

bool Board::canCastleQueenSide(const std::string& kingColor, const std::vector<Piece*>& pieces)
{
    // Find the king
    Piece* king = findKing(kingColor, pieces);

    // Check if the king hasn't moved
    if (king && dynamic_cast<King*>(king)->hasMoved == true)
    {
        return false;
    }

    // Check for queen side white side
    if (isQueenSide(kingColor, pieces) && kingColor == "white")
    {
        // Check empty squares between
        std::vector<sf::Vector2f> squaresBetween;
        squaresBetween.push_back(sf::Vector2f(1 * squareSize, 7 * squareSize));
        squaresBetween.push_back(sf::Vector2f(2 * squareSize, 7 * squareSize));
        squaresBetween.push_back(sf::Vector2f(3 * squareSize, 7 * squareSize));
        for (const auto& square : squaresBetween)
        {
            if (!isEmptySquare(pieces, square))
            {
                return false; // Cant castle because piece inbetween rook and king
            }
        }

        // Check if the king/squares he has to move through are under attack
        squaresBetween.push_back(findKing("white", pieces)->getPosition());
        std::vector<sf::Vector2f> possibleMoves;
        for (const auto& piece : pieces)
        {
            if (piece->getColor() != kingColor)
            {
                piece->getPossibleMoves(*this, pieces, possibleMoves);
                for (const auto& move : possibleMoves)
                {
                    for (const auto& square : squaresBetween)
                    {
                        if (square == move)
                        {
                            // Square/king are attacked
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Check for queen side black side
    if (isQueenSide(kingColor, pieces) && kingColor == "black")
    {
        // Check empty squares between
        std::vector<sf::Vector2f> squaresBetween;
        squaresBetween.push_back(sf::Vector2f(1 * squareSize, 0));
        squaresBetween.push_back(sf::Vector2f(2 * squareSize, 0));
        squaresBetween.push_back(sf::Vector2f(3 * squareSize, 0));
        for (const auto& square : squaresBetween)
        {
            if (!isEmptySquare(pieces, square))
            {
                return false; // Cant castle because piece inbetween rook and king
            }
        }

        // Check if the king/squares he has to move through are under attack
        squaresBetween.push_back(findKing("black", pieces)->getPosition());
        std::vector<sf::Vector2f> possibleMoves;
        for (const auto& piece : pieces)
        {
            if (piece->getColor() != kingColor)
            {
                piece->getPossibleMoves(*this, pieces, possibleMoves);
                for (const auto& move : possibleMoves)
                {
                    for (const auto& square : squaresBetween)
                    {
                        if (square == move)
                        {
                            // Square/king are attacked
                            return false;
                        }
                    }
                }
            }
        }
    }
    // If none of the squares are attacked, king isnt attacked (checked), the squares between the king and the rook are empty,
    // and they both didn't move we can conclude that we can do a kingside castle
    return true;
}




