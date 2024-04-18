#include "chess_piece.h"

chess_piece::chess_piece(bool is_white, int posx, int posy, char symbol) {
	this->is_white = is_white;
	this->symbol = symbol;
	this->posx = posx;
	this->posy = posy;
}
//GETTERS
bool chess_piece::get_in_danger() const {
	return in_danger;
}
bool chess_piece::get_is_white() const {
	return is_white;

}
int chess_piece::get_posx() const {
	return posx;
}
int chess_piece::get_posy() const {
	return posy;
}
char chess_piece::get_symbol() const {
	return symbol;
}

//SETTERS
void chess_piece::set_in_danger(bool in_danger) {
	this -> in_danger = in_danger;
}
void chess_piece::set_posx(int& posx) {
	this->posx = posx;
}
void chess_piece::set_posyx(int& posy) {
	this->posy = posy;
}

