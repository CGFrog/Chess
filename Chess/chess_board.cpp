#include "chess_board.h"
#include <iostream>


std::vector <chess_piece*> piece_vec = {1, 2, 3};



chess_board::chess_board(bool whites_turn) {
	this->whites_turn = whites_turn;
}

void chess_board::starting_positions() {
	chess_piece w_pawnA2(true, 0, 1, 'P');
	chess_piece w_pawnB2(true, 1, 1, 'P');
	chess_piece w_pawnC2(true, 2, 1, 'P');
	chess_piece w_pawnD2(true, 3, 1, 'P');
	chess_piece w_pawnE2(true, 4, 1, 'P');
	chess_piece w_pawnF2(true, 5, 1, 'P');
	chess_piece w_pawnG2(true, 6, 1, 'P');
	chess_piece w_pawnH2(true, 7, 1, 'P');
	
	piece_vec.push_back(&w_pawnA2);
	piece_vec.push_back(&w_pawnB2);
	piece_vec.push_back(&w_pawnC2);
	piece_vec.push_back(&w_pawnD2);
	piece_vec.push_back(&w_pawnE2);
	piece_vec.push_back(&w_pawnF2);
	piece_vec.push_back(&w_pawnG2);
	piece_vec.push_back(&w_pawnH2);
}

void chess_board::set_piece(int x, int y, char symb, char(&arr)[8][8]) {
	arr[x - 1][y - 1] = symb;
}

void chess_board::display_board() const{
	for (int x = 0; x < 8; x++)
	{
		std::cout << 8 - x;
		for (int y = 0; y < 8; y++)
		{
			std::cout << chess_board_array[x][y] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << ' ';
	for (int x = 0; x < 8; x++) {
		char x_axis = 'A' + x;
		std::cout << x_axis << ' ';
	}
}

void chess_board::initBoard() {
	display_board();

}
