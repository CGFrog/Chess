#include "pawn.h"
#include "chess_board.h"


bool pawn::legal_move(int x, int y, std::vector<chess_piece*>& vector) const{
	if (x != 0 && y < 2 && y > 0) {
		if (abs(x) > 1)
			return false;
		for (int i = 0; i < vector.size(); i++) {
			if (((*vector[i]).get_pos_x() == x && (*vector[i]).get_pos_y() == y) && ((*vector[i]).get_is_white() != get_is_white())) {
				return true;
			}
		}
		return false;
	}
	if (!(this->get_has_moved())) {
		if (abs(y - get_pos_y()) > 2)
			return false;
	}
	else if (this->get_has_moved()) {
		if (abs(y - get_pos_y()) > 1)
			return false;
	}
	return true;
}