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

	chess_board();
	
	void display_board();

	void initBoard();

	chess_piece& find_chess_piece(int posx, int posy) const;
	
	//https://cplusplus.com/forum/general/2710/
	std::vector<chess_piece*>active_pieces;


};