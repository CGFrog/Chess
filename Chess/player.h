#pragma once
#include <string>
class player {

	bool is_white;
	std::string selected_piece;
	std::string selected_location;


public:

	player(bool is_white);

	std::string select_location();
	bool is_valid_input(std::string input);
	int convert_x(std::string x);
	int convert_y(std::string y);
};