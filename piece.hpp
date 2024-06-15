#pragma once
#include <utility>
#include <string>

typedef enum Piece_type_t {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

class Piece
{
private:
	char symbol;
	std::pair<char, int> position;
	std::string type;

public:
	Piece(char symbol = 'X', std::pair<char, int> position = { 'X', 0 }, std::string type = "X") : symbol{symbol}, position{position}, type{type} {};

	char get_symbol() { return symbol; };
	void set_symbol(char _symbol) { symbol = _symbol; };

	std::pair<char, int> get_position() { return position; };
	void set_position(std::pair<char, int> _position) { position = _position; };

	std::string get_type() { return type; };
	void set_type(std::string _type) { type = _type; };
};