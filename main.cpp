#include <iostream>
#include <tuple>

#include "chessboard.hpp"
#include "game.hpp"

int main()
{
	Chessboard test;
	test.print();

	std::pair<char, int> move;
	std::cin >> move.first >> move.second;

	Piece piece;
	piece.set_position(move);

	std::cin >> move.first >> move.second;

	test.move_piece(piece, move);
	test.print();

	return 0;
}