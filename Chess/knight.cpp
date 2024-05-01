#include "knight.h"


bool knight::legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const{
	int delta_x = abs(this->get_pos_x() - x);
	int delta_y = abs(this->get_pos_y() - y);
	
	if (delta_x + delta_y == 3 && delta_x != 0 && delta_y != 0)
		return true;
	return false;
}