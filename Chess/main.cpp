#include "chess_board.h"

int main() {
	bool quit = false;
	
	chess_board board(false);
	board.initBoard();
	while (!quit) {
		board.next_turn(quit);
	}
	return 0;
}