#include "player.h"
#include <iostream>
#include <string>
player::player(bool is_white) {
	this->is_white = is_white;
}

std::string select_location() {
	std::string selected_piece;
	std::getline(std::cin, selected_piece);
	return selected_piece;
}

int player::convert_x(std::string x) {
	int converted_x = x[0];	
	return converted_x;
}
int player::convert_y(std::string y) {
	int converted_y = y[1];
	return converted_y;
}