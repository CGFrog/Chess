#include "chess_board.h"
#include <iostream>


chess_board::chess_board() {


}

void chess_board::display_board() {
	for (int i = 0; i < 8; i++)
	{
		std::cout << 8 - i;
		for (int j = 0; j < 8; j++)
		{
			std::cout << chess_board_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << ' ';
	for (int i = 0; i < 8; i++) {
		char x_axis = 'A' + i;
		std::cout << x_axis << ' ';
	}
}

void chess_board::initBoard() {
	display_board();



}
