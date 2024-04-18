#pragma once
#include <string>
class player {

	bool is_white;
	std::string selected_piece;
	std::string selected_location;


public:

	player(bool is_white);

	std::string select_piece();
	std::string select_move();

	int convert_x(std::string x[0]);
	int convert_y(std::string y[1]);
};