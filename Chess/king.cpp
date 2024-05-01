#include "king.h"

bool king::legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const {
	if ((abs(this->get_pos_x() - x) > 1) || (abs(this->get_pos_y() - y) > 1))
		return false;

	return true;
}