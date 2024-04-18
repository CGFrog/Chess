#pragma once
#include <string>

class chess_piece {

	bool in_danger = false;
	bool is_white;
	int posx;
	int posy;
	char symbol;


public:

	bool get_in_danger() const;
	bool get_is_white() const;
	int get_posx() const;
	int get_posy() const;
	char get_symbol() const;

	void set_in_danger(bool in_danger);
	void set_posx(int posx);
	void set_posyx(int posy);



	chess_piece(bool white, int posx, int posy, char symbol);

	void move_piece(int posx, int posy, std::string next_pos);

};

