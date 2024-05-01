#include "bishop.h"

bool bishop::legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const {
	int delta_x = abs(this->get_pos_x() - x);
	int delta_y = abs(this->get_pos_y() - y);
	if (delta_x == delta_y) {
		return true;
	}
	return false;
}