#include "chess_board.h"
#include <iostream>


chess_board::chess_board() {

}

void chess_board::starting_positions() {
	
}

void chess_board::display_board() {
	for (int y = 0; y < 8; y++)
	{
		std::cout << 8 - y;
		for (int x = 0; x < 8; x++)
		{
			std::cout << chess_board_array[y][x] << " ";
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
