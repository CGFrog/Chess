#pragma once
#include "chess_piece.h"

class pawn : public chess_piece {

private:
	bool can_attack;
	bool has_moved;

public:
	pawn();
	bool is_valid_move(bool has_moved, bool can_attack, int posx, int posy, int next_posx, int next_posy);
	


};