#include "chess_board.h"
#include <iostream>
#include "windows.h"

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
	chess_piece b_pawnA7(false, 0, 1, 'p');
	chess_piece b_pawnB7(false, 1, 1, 'p');
	chess_piece b_pawnC7(false, 2, 1, 'p');
	chess_piece b_pawnD7(false, 3, 1, 'p');
	chess_piece b_pawnE7(false, 4, 1, 'p');
	chess_piece b_pawnF7(false, 5, 1, 'p');
	chess_piece b_pawnG7(false, 6, 1, 'p');
	chess_piece b_pawnH7(false, 7, 1, 'p');
	chess_piece b_rookA8(false, 0, 0, 'r');
	chess_piece b_rookH8(false, 7, 0, 'r');
	chess_piece b_queen(false, 3, 0, 'q');
	chess_piece b_king(false, 4, 0, 'k');
	chess_piece b_knightB8(false, 6, 0, 'n');
	chess_piece b_knightG8(false, 1, 0, 'n');
	chess_piece b_bishopF8(false, 2, 0, 'b');
	chess_piece b_bishopC8(false, 5, 0, 'b');

	piece_vec.push_back(b_pawnA7);
	piece_vec.push_back(b_pawnB7);
	piece_vec.push_back(b_pawnC7);
	piece_vec.push_back(b_pawnD7);
	piece_vec.push_back(b_pawnE7);
	piece_vec.push_back(b_pawnF7);
	piece_vec.push_back(b_pawnG7);
	piece_vec.push_back(b_pawnH7);
	piece_vec.push_back(b_rookA8);
	piece_vec.push_back(b_rookH8);
	piece_vec.push_back(b_queen);
	piece_vec.push_back(b_king);
	piece_vec.push_back(b_knightB8);
	piece_vec.push_back(b_knightG8);
	piece_vec.push_back(b_bishopF8);
	piece_vec.push_back(b_bishopC8);

	chess_piece w_pawnA1(true, 0, 6, 'P');
	chess_piece w_pawnB1(true, 1, 6, 'P');
	chess_piece w_pawnC1(true, 2, 6, 'P');
	chess_piece w_pawnD1(true, 3, 6, 'P');
	chess_piece w_pawnE1(true, 4, 6, 'P');
	chess_piece w_pawnF1(true, 5, 6, 'P');
	chess_piece w_pawnG1(true, 6, 6, 'P');
	chess_piece w_pawnH1(true, 7, 6, 'P');
	chess_piece w_rookA0(true, 0, 7, 'R');
	chess_piece w_rookH0(true, 7, 7, 'R');
	chess_piece w_queen(true, 3, 7, 'Q');
	chess_piece w_king(true, 4, 7, 'K');
	chess_piece w_knightB0(true, 6, 7, 'N');
	chess_piece w_knightG0(true, 1, 7, 'N');
	chess_piece w_bishopF0(true, 2, 7, 'B');
	chess_piece w_bishopC0(true, 5, 7, 'B');

	piece_vec.push_back(w_pawnA1);
	piece_vec.push_back(w_pawnB1);
	piece_vec.push_back(w_pawnC1);
	piece_vec.push_back(w_pawnD1);
	piece_vec.push_back(w_pawnE1);
	piece_vec.push_back(w_pawnF1);
	piece_vec.push_back(w_pawnG1);
	piece_vec.push_back(w_pawnH1);
	piece_vec.push_back(w_rookA0);
	piece_vec.push_back(w_rookH0);
	piece_vec.push_back(w_queen);
	piece_vec.push_back(w_king);
	piece_vec.push_back(w_knightB0);
	piece_vec.push_back(w_knightG0);
	piece_vec.push_back(w_bishopF0);
	piece_vec.push_back(w_bishopC0);
}


void chess_board::set_pieces() {
	for (int i = 0; i < piece_vec.size(); i++) {
		int x = piece_vec[i].get_pos_x();
		int y = piece_vec[i].get_pos_y();
		char sym = piece_vec[i].get_symbol();
		chess_board_vector[y][x] = sym;
	}
}

void reset_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
}

void chess_board::display_board() const{
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < 8; y++)
	{
		SetConsoleTextAttribute(h, 3);
		std::cout << 8 - y << ' ';
		reset_color();
		for (int x = 0; x < 8; x++)
		{
			if (chess_board_vector[y][x] > 96 && chess_board_vector[y][x] < 123)
				SetConsoleTextAttribute(h, 14);
			else if (chess_board_vector[y][x] > 64 && chess_board_vector[y][x] < 91)
				SetConsoleTextAttribute(h, 12);
			std::cout << chess_board_vector[y][x] << " ";

		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (int x = 0; x < 8; x++) {
		SetConsoleTextAttribute(h, 11);
		char x_axis = 'A' + x;
		std::cout << x_axis << ' ';
	}
	reset_color();
}

void chess_board::initBoard() {
	starting_positions();
	set_pieces();
	display_board();

}

