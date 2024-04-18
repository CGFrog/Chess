#pragma once

class chess_piece {

public:

	bool in_danger = false;
	bool white;
	int pos[2] = {};
	char symbol;

	chess_piece(bool white, int posx, int posy, char symbol);

};

