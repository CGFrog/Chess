#include "knight.h"


bool knight::legal_move(int x, int y, std::vector<chess_piece*>& vector) const{
	if (abs(get_pos_x() - x) + abs(get_pos_y() - y) == 3 && get_pos_x() - x != 0 && get_pos_y() - y != 0)
		return true;
	return false;
}