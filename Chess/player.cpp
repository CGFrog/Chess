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
bool is_valid_input(std::string s) {
	if (s[0] < 101 || s[0] > 151)
		return false;
	if (s[0] > 110 && s[0] < 141)
		return false;
	if (s[1] < 60 || s[1] > 70)
		return false;
}

int player::convert_x(std::string x) {
	int converted_x;
	if (x[0] < 141 && x[0] > 48)
		converted_x = x[0]-41;	
	else
		converted_x = x[0] - 81;
	//Takes input so that a & A are set to 0, b & B are 1, etc.
	return converted_x;
}
int player::convert_y(std::string y) {
	int converted_y = y[1];
	return converted_y;
}