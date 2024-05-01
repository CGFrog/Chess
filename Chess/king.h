#pragma once
#include "chess_piece.h"

class king : public chess_piece {
	using chess_piece::chess_piece;

	bool legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const;

};