#pragma once
#include <vector>
#include "chess_piece.h"


class chess_board {

	bool whites_turn;

public:
	
	char chess_board_array[8][8] = {
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	'_','_','_','_','_','_','_','_',
	};



	void starting_positions();

	void set_piece(int x, int y, char symb, char(&arr)[8][8]);

	chess_board(bool whites_turn);
	
	void display_board() const;

	void initBoard();

};