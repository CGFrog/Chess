#include "pawn.h"
#include <cmath>

bool pawn::is_valid_move(bool has_moved, bool can_attack, int posx, int posy, int next_posx, int next_posy) {
	int displacementy = next_posy - posy;
	int displacementx = next_posx - posx;

	if (posx != next_posx && !can_attack) {
		return false;
	}
	if (displacementy < 1 || displacementy > 2) {
		return false;
	}
	if (displacementy > 1 && has_moved) {
		return false;
	}
	if (abs(displacementx) == 1) {
		return true;
	}
	return true;
}