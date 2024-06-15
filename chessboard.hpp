#pragma once
#include <array>
#include "piece.hpp"

class Chessboard
{
private:
	std::array<Piece, 32> pieces;
public:
	Chessboard();

	std::array<Piece, 32> get_pieces() { return pieces; };

	void print();
};