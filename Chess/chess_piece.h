#pragma once
#include <string>
#include <vector>
class chess_piece {

	bool in_danger = false; // Only relevant for kings OR if checkmate is implemented
	bool has_moved = false; // Only relevant for pawns, kings, and rooks
	bool is_white;
	int pos_x;
	int pos_y;
	char symbol;


	//P = Pawn, Q = Queen, K = King, N = Knight, R = Rook, B = Bishop

public:
	bool get_has_moved() const;
	bool get_in_danger() const;
	bool get_is_white() const;
	int get_pos_x() const;
	int get_pos_y() const;
	char get_symbol() const;
	void set_in_danger(bool in_danger);
	void set_pos_x(int& pos_x);
	void set_pos_y(int& pos_y);
	void set_has_moved(bool has_moved);
	virtual	bool legal_move(int x, int y, std::vector<chess_piece*>& vector, std::vector<std::vector<char>>& map) const;
	chess_piece(bool white, int pos_x, int pos_y, char symbol);

	void move_piece(int pos_x, int pos_y, std::string next_pos);


};
