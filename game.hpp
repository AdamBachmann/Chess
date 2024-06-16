#include <utility>
#include "chessboard.hpp"

class Game {
public:
	void move(Chessboard & chessboard, Piece piece, std::pair<char, int> destination);
};