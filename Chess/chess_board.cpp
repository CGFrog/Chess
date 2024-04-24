#include "chess_board.h"
#include <iostream>


std::vector <chess_piece> piece_vec;

std::vector<std::vector<char>> chess_board_vector = {
{ '_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', },
{'_', '_', '_', '_', '_', '_', '_', '_', }
};

chess_board::chess_board(bool whites_turn) {
	this->whites_turn = whites_turn;
}

void chess_board::starting_positions() {
	chess_piece w_pawnA2(true, 1, 1, 'P');
	chess_piece w_pawnB2(true, 1, 1, 'P');
	chess_piece w_pawnC2(true, 2, 1, 'P');
	chess_piece w_pawnD2(true, 3, 1, 'P');
	chess_piece w_pawnE2(true, 4, 1, 'P');
	chess_piece w_pawnF2(true, 5, 1, 'P');
	chess_piece w_pawnG2(true, 6, 1, 'P');
	chess_piece w_pawnH2(true, 7, 1, 'P');
	chess_piece w_rookA1(true, 0, 0, 'R');
	chess_piece w_rookH1(true, 7, 0, 'R');
	chess_piece w_queen(true, 3, 0, 'Q');
	chess_piece w_king(true, 4, 0, 'K');
	chess_piece w_knightB1(true, 6, 0, 'N');
	chess_piece w_knightG1(true, 1, 0, 'N');
	chess_piece w_bishopF1(true, 2, 0, 'B');
	chess_piece w_bishopC1(true, 5, 1, 'B');

	piece_vec.push_back(w_pawnA2);
	piece_vec.push_back(w_pawnB2);
	piece_vec.push_back(w_pawnC2);
	piece_vec.push_back(w_pawnD2);
	piece_vec.push_back(w_pawnE2);
	piece_vec.push_back(w_pawnF2);
	piece_vec.push_back(w_pawnG2);
	piece_vec.push_back(w_pawnH2);
	piece_vec.push_back(w_rookA1);
	piece_vec.push_back(w_rookH1);
	piece_vec.push_back(w_queen);
	piece_vec.push_back(w_king);
	piece_vec.push_back(w_knightB1);
	piece_vec.push_back(w_knightG1);
	piece_vec.push_back(w_bishopF1);
	piece_vec.push_back(w_bishopC1);
}


void chess_board::set_pieces() {
	for (int i = 0; i < piece_vec.size(); i++) {
		int x = piece_vec[i].get_pos_x();
		int y = piece_vec[i].get_pos_y();
		char sym = piece_vec[i].get_symbol();
		chess_board_vector[y][x] = sym;
	}
}

void chess_board::display_board() const{
	for (int x = 0; x < 8; x++)
	{
		std::cout << 8 - x;
		for (int y = 0; y < 8; y++)
		{
			std::cout << chess_board_vector[x][y] << " ";
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
	starting_positions();
	set_pieces();
	display_board();

}

