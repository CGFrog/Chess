#pragma once
#include <vector>
#include "chess_piece.h"


class chess_board {

	bool whites_turn;

public:
	


	void starting_positions();

	void set_pieces();

	chess_board(bool whites_turn);
	
	void display_board() const;

	void initBoard();

};