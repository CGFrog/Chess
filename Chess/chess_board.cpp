#include "chess_board.h"
#include <iostream>
#include "windows.h"
#include "pawn.h"
#include "queen.h"
#include "knight.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"

//Is there a cleaner way of creating/storing these
//without them being outside of a function or data structure?

//If I have a vector of pointers I still need the objects to exist somewhere to reference
//but then they are all just floating out here and I do not like this.

std::vector <char> white_score;
std::vector <char> black_score;

pawn w_pawnA1(true, 0, 6, 'P');
pawn w_pawnB1(true, 1, 6, 'P');
pawn w_pawnC1(true, 2, 6, 'P');
pawn w_pawnD1(true, 3, 6, 'P');
pawn w_pawnE1(true, 4, 6, 'P');
pawn w_pawnF1(true, 5, 6, 'P');
pawn w_pawnG1(true, 6, 6, 'P');
pawn w_pawnH1(true, 7, 6, 'P');
rook w_rookA0(true, 0, 7, 'R');
rook w_rookH0(true, 7, 7, 'R');
queen w_queen(true, 3, 7, 'Q');
king w_king(true, 4, 7, 'K');
knight w_knightB0(true, 6, 7, 'N');
knight w_knightG0(true, 1, 7, 'N');
bishop w_bishopF0(true, 2, 7, 'B');
bishop w_bishopC0(true, 5, 7, 'B');
pawn b_pawnA7(false, 0, 1, 'p');
pawn b_pawnB7(false, 1, 1, 'p');
pawn b_pawnC7(false, 2, 1, 'p');
pawn b_pawnD7(false, 3, 1, 'p');
pawn b_pawnE7(false, 4, 1, 'p');
pawn b_pawnF7(false, 5, 1, 'p');
pawn b_pawnG7(false, 6, 1, 'p');
pawn b_pawnH7(false, 7, 1, 'p');
rook b_rookA8(false, 0, 0, 'r');
rook b_rookH8(false, 7, 0, 'r');
queen b_queen(false, 3, 0, 'q');
king b_king(false, 4, 0, 'k');
knight b_knightB8(false, 6, 0, 'n');
knight b_knightG8(false, 1, 0, 'n');
bishop b_bishopF8(false, 2, 0, 'b');
bishop b_bishopC8(false, 5, 0, 'b');

std::vector <chess_piece*> piece_vec;
std::vector<std::vector<char>> chess_board_vector = {
{'_', '_', '_', '_', '_', '_', '_', '_', },
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
	piece_vec.push_back(&b_pawnA7);
	piece_vec.push_back(&b_pawnB7);
	piece_vec.push_back(&b_pawnC7);
	piece_vec.push_back(&b_pawnD7);
	piece_vec.push_back(&b_pawnE7);
	piece_vec.push_back(&b_pawnF7);
	piece_vec.push_back(&b_pawnG7);
	piece_vec.push_back(&b_pawnH7);
	piece_vec.push_back(&b_rookA8);
	piece_vec.push_back(&b_rookH8);
	piece_vec.push_back(&b_queen);
	piece_vec.push_back(&b_king);
	piece_vec.push_back(&b_knightB8);
	piece_vec.push_back(&b_knightG8);
	piece_vec.push_back(&b_bishopF8);
	piece_vec.push_back(&b_bishopC8);
	piece_vec.push_back(&w_pawnA1);
	piece_vec.push_back(&w_pawnB1);
	piece_vec.push_back(&w_pawnC1);
	piece_vec.push_back(&w_pawnD1);
	piece_vec.push_back(&w_pawnE1);
	piece_vec.push_back(&w_pawnF1);
	piece_vec.push_back(&w_pawnG1);
	piece_vec.push_back(&w_pawnH1);
	piece_vec.push_back(&w_rookA0);
	piece_vec.push_back(&w_rookH0);
	piece_vec.push_back(&w_queen);
	piece_vec.push_back(&w_king);
	piece_vec.push_back(&w_knightB0);
	piece_vec.push_back(&w_knightG0);
	piece_vec.push_back(&w_bishopF0);
	piece_vec.push_back(&w_bishopC0);
}
void chess_board::set_pieces() {	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chess_board_vector[i][j] = '_';
		}
	}

	for (int i = 0; i < piece_vec.size(); i++) {
		int x = (*piece_vec[i]).get_pos_x();
		int y = (*piece_vec[i]).get_pos_y();
		char sym = (*piece_vec[i]).get_symbol();
		chess_board_vector[y][x] = sym;
	}
}
void chess_board::next_turn(bool& quit) {
	whites_turn = !whites_turn;
	set_pieces();
	if (whites_turn)
		display_board_white();
	else
		display_board_black();
	move_piece(quit);
}

void reset_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
}
void black_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
}
void white_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
}
void y_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 3);
}
void x_color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 11);
}
void what_color_piece(int x, int y){
	if (chess_board_vector[y][x] > 96 && chess_board_vector[y][x] < 123)
		black_color();
	else if (chess_board_vector[y][x] > 64 && chess_board_vector[y][x] < 91)
		white_color();
	else if (chess_board_vector[y][x] == '_')
		reset_color();
}

void chess_board::display_board_white() const{
	system("CLS");
	
	for (int y = 0; y < 8; y++)
	{
		y_color();
		std::cout << 8 - y << ' ';
		reset_color();
		for (int x = 0; x < 8; x++)
		{
			what_color_piece(x,y);
			std::cout << chess_board_vector[y][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (int x = 0; x < 8; x++) {
		x_color();
		char x_axis = 'A' + x;
		std::cout << x_axis << ' ';
	}
	std::cout << std::endl << std::endl;
	reset_color();
	std::cout << "It is whites turn" << std::endl;
	std::cout << "Select piece to move & location \"E2 E4\" or type \"resign\"" << std::endl;
	score_board();
}
void chess_board::display_board_black() const {
	system("CLS");

	for (int y = 7; y > -1; y--)
	{
		y_color();
		std::cout << 8 - y << ' ';
		reset_color();
		for (int x = 7; x > -1; x--)
		{
			what_color_piece(x, y);
			std::cout << chess_board_vector[y][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (int x = 0; x < 8; x++) {
		x_color();
		char x_axis = 'H' - x;
		std::cout << x_axis << ' ';
	}
	std::cout << std::endl << std::endl;
	reset_color();

	std::cout << "It is blacks turn" << std::endl;
	std::cout << "Select piece to move & location \"E2 E4\" or type \"resign\"" << std::endl;
	score_board();
}
void chess_board::initBoard() {
	starting_positions();
	set_pieces();
}
bool chess_board::valid_coordinate(std::string coord) {
	bool is_valid = true;
	if (!(coord[0] > 64 && coord[0] < 73) && !(coord[0] > 96 && coord[0] < 105)) {
		is_valid = false; //Letters
	}
	else if (!(coord[1] < 57 && coord[1] > 48)) {
		is_valid = false;//Digits
	}
	else if (!(coord[3] > 64 && coord[3] < 73) && !(coord[3] > 96 && coord[3] < 105)) {
		is_valid = false; //Letters
	}
	else if (!(coord[4] < 57 && coord[4] > 48)) {
		is_valid = false; //Digits
	}
	if (!is_valid)
		std::cout << "Invalid Coordinates" << std::endl;
	return is_valid;
}
void chess_board::resign() {
	if (whites_turn) {
		std::cout << "White has resigned, Black wins." << std::endl;
		return;
	}
	std::cout << "Black has resigned, White wins." << std::endl;
}

std::string chess_board::get_coordinate() {
	std::string coordinate;
	std::getline(std::cin, coordinate);
	return coordinate;
}
int chess_board::convert_coord_x(char coord) {
	if (coord > 96) {
		return abs(coord - 104); //Lowercase
	}
	else if(coord < 73) {
		return abs(coord - 65); //Uppercase letters
	}
	return 0;
}
int chess_board::convert_coord_y(char coord) {
	return abs(coord - 56);
}

void chess_board::move_piece(bool& quit) { // If time, trim down this function.
	std::string coordinates = get_coordinate();
	if (coordinates == "resign") {
		quit = true;
		resign();
		return;
	}
	while (!valid_coordinate(coordinates)) {
		coordinates = get_coordinate();
		if (coordinates == "resign") {
			quit = true;
			resign();
			return;
		}
	}

	int select_x = convert_coord_x(coordinates[0]);
	int select_y = convert_coord_y(coordinates[1]);
	int next_x = convert_coord_x(coordinates[3]);
	int next_y = convert_coord_y(coordinates[4]);

	for (int i = 0; i < piece_vec.size(); i++) {
		if ((*piece_vec[i]).get_pos_x() == select_x && (*piece_vec[i]).get_pos_y() == select_y) {
			if((*piece_vec[i]).get_is_white() != whites_turn){
				std::cout << "That piece belongs to the other team" << std::endl;
				move_piece(quit);
				return;
			}
			if (!(piece_vec[i])->legal_move(next_x, next_y, piece_vec, chess_board_vector)) {
				std::cout << "Illegal Move" << std::endl;
				move_piece(quit);
				return;
			}

			else if ((*piece_vec[i]).get_is_white() == whites_turn) {
				if (!attack_square(next_x, next_y)) {
					move_piece(quit);
					return;
				}
				//Too much nesting make this a function and use it for the top for-loop as well.
				//Try to do this without this for-loop, keep size of vector some way
				//Push element to end of vector then set a variable to subtract from the indexed range of vector
				//It will maintain size but exclude captured pieces
				for (int j = 0; j < piece_vec.size(); j++) {
					if ((*piece_vec[j]).get_pos_x() == select_x && (*piece_vec[j]).get_pos_y() == select_y) {
						(*piece_vec[j]).set_pos_x(next_x);
						(*piece_vec[j]).set_pos_y(next_y);
						(*piece_vec[j]).set_has_moved(true);
						return;
					}
				}
			}
			//If time, change vector of classes to a matrix with NULL pointers for O(1) time.
		}
	}
	std::cout << "There is no piece at that location." << std::endl;
	move_piece(quit);
	return;
}
bool chess_board::attack_square(int next_x, int next_y) {
	for (int j = 0; j < piece_vec.size(); j++) {
		if ((piece_vec[j]->get_pos_x() == next_x && piece_vec[j]->get_pos_y() == next_y) && (piece_vec[j]->get_is_white() != whites_turn)) {
			if (piece_vec[j]->get_is_white())
				black_score.push_back(piece_vec[j]->get_symbol());
			else if (!piece_vec[j]->get_is_white())
				white_score.push_back(piece_vec[j]->get_symbol());
			piece_vec.erase(piece_vec.begin() + j);
			return true;
		}
		if ((piece_vec[j]->get_pos_x() == next_x && piece_vec[j]->get_pos_y() == next_y) && (piece_vec[j]->get_is_white() == whites_turn)) {
			std::cout << "That square is already occupied by one of your pieces." << std::endl;
			return false;
		}
	}
	return true;
}
void chess_board::score_board() const{
	white_color();
	std::cout << "White's Score: ";
	if (white_score.size() > 0) {
		for (int i = 0; i < white_score.size(); i++) {
			std::cout << white_score[i] << ",";
		}
	}
	std::cout << std::endl;
	black_color();
	std::cout << "Black's Score: ";
	if (black_score.size() > 0) {
		for (int i = 0; i < black_score.size(); i++) {
			std::cout << black_score[i] << ",";
		}
	}
	std::cout << std::endl;
	reset_color();
}