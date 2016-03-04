#ifndef __GRID_H__
#define __GRID_H__
#include <string>

class Grid {
	const int MAX;
	char board[9];
	std::string player1;
	std::string player2;

	int turn;
	char current;

	// statistics
	int win1; // player1 win stat
	int win2; // player2 win stat
	int draw;
	int total;

///// methods ////////
	void printBoard();
	void resetBoard();
	char checkWin();

public:
	Grid();
	void play();
	
	// extra
	void changeName(std::string name);
};

#endif