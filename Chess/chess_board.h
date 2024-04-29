#pragma once
#include "chess_piece.h"


class chess_board {

	bool whites_turn;

public:
	
	void starting_positions();
	void set_pieces();
	chess_board(bool whites_turn);
	void initBoard();
	void move_piece(bool& quit);
	std::string get_coordinate();
	bool valid_coordinate(std::string coord);
	int convert_coord_x(char coord);
	int convert_coord_y(char coord);
	void next_turn(bool& quit);
	bool attack_square(int i, int next_x, int next_y) const;
	void resign();
	void display_board_white() const;
	void display_board_black() const;
	void score_board() const;
};