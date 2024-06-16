#include <iostream>
#include "chessboard.hpp"

Chessboard::Chessboard()
{
	pieces = {
		Piece{ PAWN,	{'A',2}}, 
		Piece{ PAWN,	{'B',2}},
		Piece{ PAWN,	{'C',2}},
		Piece{ PAWN,	{'D',2}},
		Piece{ PAWN,	{'E',2}},
		Piece{ PAWN,	{'F',2}},
		Piece{ PAWN,	{'G',2}},
		Piece{ PAWN,	{'H',2}},
		Piece{ ROOK,	{'A',1}},
		Piece{ KNIGHT,	{'B',1}},
		Piece{ BISHOP,	{'C',1}},
		Piece{ QUEEN,	{'D',1}},
		Piece{ KING,	{'E',1}},
		Piece{ BISHOP,	{'F',1}},
		Piece{ KNIGHT,	{'G',1}},
		Piece{ ROOK,	{'H',1}},
		Piece{ PAWN,	{'A',7}},
		Piece{ PAWN,	{'B',7}},
		Piece{ PAWN,	{'C',7}},
		Piece{ PAWN,	{'D',7}},
		Piece{ PAWN,	{'E',7}},
		Piece{ PAWN,	{'F',7}},
		Piece{ PAWN,	{'G',7}},
		Piece{ PAWN,	{'H',7}},
		Piece{ ROOK,	{'A',8}},
		Piece{ KNIGHT,	{'B',8}},
		Piece{ BISHOP,	{'C',8}},
		Piece{ QUEEN,	{'D',8}},
		Piece{ KING,	{'E',8}},
		Piece{ BISHOP,	{'F',8}},
		Piece{ KNIGHT,	{'G',8}},
		Piece{ ROOK,	{'H',8}},
	};
}

void Chessboard::print()
{
	const unsigned char right_upper_corner = 191;
	const unsigned char left_upper_corner = 218;
	const unsigned char right_bottom_corner = 217;
	const unsigned char left_bottom_corner = 192;

	const unsigned char upper_middle = 194;
	const unsigned char bottom_middle = 193;
	const unsigned char right_middle = 180;
	const unsigned char left_middle = 195;

	const unsigned char horizontal = 196;
	const unsigned char vertical = 179;

	const unsigned char center = 197;

	for (int row = 0; row < 17; row++) {
		for (int column = 0; column < 17; column++) {
			if (row % 2 == 0) {
				if (row == 0) {
					if (column % 2 == 0) {
						if (column == 0) {
							std::cout << char(left_upper_corner);
						}
						else if (column == 16) {
							std::cout << char(right_upper_corner);
						}
						else {
							std::cout << char(upper_middle);
						}
					}
					else {
						std::cout << char(horizontal);
					}
				}
				else if (row == 16) {
					if (column % 2 == 0) {
						if (column == 0) {
							std::cout << char(left_bottom_corner);
						}
						else if (column == 16) {
							std::cout << char(right_bottom_corner);
						}
						else {
							std::cout << char(bottom_middle);
						}
					}
					else {
						std::cout << char(horizontal);
					}
				}
				else {
					if (column % 2 == 0) {
						if (column == 0) {
							std::cout << char(left_middle);
						}
						else if (column == 16) {
							std::cout << char(right_middle);
						}
						else {
							std::cout << char(center);
						}
					}
					else {
						std::cout << char(horizontal);
					}
				}
			}
			else {
				if (column % 2 == 0) {
					std::cout << char(vertical);
				}
				else {
					//fill pieces
					int is_empty = 1;
					for (auto piece : pieces) {
						if (row == piece.get_position().second * 2 - 1 && column == (((piece.get_position().first - 'A') + 1) * 2 - 1)) {
							std::cout << char(piece.get_type());
							is_empty = 0;
						}
					}
					if (is_empty == 1) {
						std::cout << " ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}

int Chessboard::move_piece(Piece whence, std::pair<char, int> destination) {
	auto element = std::find_if(pieces.begin(), pieces.end(), [whence](Piece i) mutable {
		return whence.get_position().first == i.get_position().first && whence.get_position().second == i.get_position().second;
		});

	if (element == pieces.end()){
		return -1;
	}

	element->set_position(destination);
	return 0;
}