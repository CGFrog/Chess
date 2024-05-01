#include "pawn.h"
#include "chess_board.h"

bool pawn::legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const{
	int delta_x = abs(this->get_pos_x() - x);
	int delta_y = abs(this->get_pos_y() - y);

	if (delta_x > 1) //Cannot move on x more than 1
		return false;
	if (delta_y > 2) //Cannot move on y more than 2
		return false;
	if (this->get_has_moved()) { //Cannot move on y more than 1 if piece has moved
		if (delta_y > 1)
			return false;
	}
	if (delta_x == 0) {
		if (map[y][x] != '_') {
			return false;
		}
	}
	if (delta_x != 0) { //Is the piece moving on the x to attack a piece?
		for (int i = 0; i < vector.size(); i++) {
			if (vector[i]->get_pos_x() == x && vector[i]->get_pos_y() == y)
				return true;
		}
		return false;
	}	
	return true;
}