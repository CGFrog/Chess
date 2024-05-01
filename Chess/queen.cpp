#include "queen.h"

bool queen::legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const {
	int delta_x = abs(this->get_pos_x() - x);
	int delta_y = abs(this->get_pos_y() - y);
	int num = delta_x + delta_y;
	if (delta_x == num || delta_y == num) {
		return true;
	}
	if (delta_x == delta_y) {
		return true;
	}
	return false;
}