#pragma once
#include <utility>
#include <string>

typedef enum Piece_type_t {
	DEFAULT = 'X',
	PAWN = 'P',
	KNIGHT = 'N',
	BISHOP = 'B',
	ROOK = 'R',
	QUEEN = 'Q',
	KING= 'K'
};

class Piece
{
private:
	Piece_type_t type;
	std::pair<char, int> position;

public:
	Piece(Piece_type_t type = DEFAULT, std::pair<char, int> position = { 'X', 0 }) : type{type}, position{position} {};

	std::pair<char, int> get_position() { return position; };
	void set_position(std::pair<char, int> _position) { position = _position; };

	Piece_type_t get_type() { return type; };
	void set_type(Piece_type_t _type) { type = _type; };
};