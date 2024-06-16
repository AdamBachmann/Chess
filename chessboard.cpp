#include <iostream>
#include "chessboard.hpp"

Chessboard::Chessboard()
{
	pieces = {
		Piece{ 'P', {'A',2}, "Pawn"		}, 
		Piece{ 'P', {'B',2}, "Pawn"		},
		Piece{ 'P', {'C',2}, "Pawn"		},
		Piece{ 'P', {'D',2}, "Pawn"		},
		Piece{ 'P', {'E',2}, "Pawn"		},
		Piece{ 'P', {'F',2}, "Pawn"		},
		Piece{ 'P', {'G',2}, "Pawn"		},
		Piece{ 'P', {'H',2}, "Pawn"		},

		Piece{ 'R', {'A',1}, "Rook"		},
		Piece{ 'N', {'B',1}, "Knight"	},
		Piece{ 'B', {'C',1}, "Bishop"	},
		Piece{ 'Q', {'D',1}, "Queen"	},
		Piece{ 'K', {'E',1}, "King"		},
		Piece{ 'B', {'F',1}, "Bishop"	},
		Piece{ 'N', {'G',1}, "Knight"	},
		Piece{ 'R', {'H',1}, "Rook"		},

		Piece{ 'P', {'A',7}, "Pawn"		},
		Piece{ 'P', {'B',7}, "Pawn"		},
		Piece{ 'P', {'C',7}, "Pawn"		},
		Piece{ 'P', {'D',7}, "Pawn"		},
		Piece{ 'P', {'E',7}, "Pawn"		},
		Piece{ 'P', {'F',7}, "Pawn"		},
		Piece{ 'P', {'G',7}, "Pawn"		},
		Piece{ 'P', {'H',7}, "Pawn"		},

		Piece{ 'R', {'A',8}, "Rook"		},
		Piece{ 'N', {'B',8}, "Knight"	},
		Piece{ 'B', {'C',8}, "Bishop"	},
		Piece{ 'Q', {'D',8}, "Queen"	},
		Piece{ 'K', {'E',8}, "King"		},
		Piece{ 'B', {'F',8}, "Bishop"	},
		Piece{ 'N', {'G',8}, "Knight"	},
		Piece{ 'R', {'H',8}, "Rook"		},
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
							std::cout << piece.get_symbol();
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