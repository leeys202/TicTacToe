// to do:
// change colour of O and X font 

#include "grid.h"
#include <iostream>

using namespace std;

Grid::Grid(): MAX(9) {
	for (int i = 0; i < MAX; i++) {
		board[i] = 49+i;
	}
	player1 = "Player 1";
	player2 = "Player 2";
	turn = 0;
	current = 'X';
	win1 = 0;
	win2 = 0;
	draw = 0;
	total = 0;
}

void Grid::printBoard() {
	cout << " - - - - - -" << endl;
	for (int i = 0; i < MAX ; i++) {
		cout << "| " << board[i] << " ";
		if (i % 3 == 2) { 
			cout << "|" << endl; 
			cout << " - - - - - -" << endl;
		} 
	}
}

void Grid::resetBoard() {
	for (int i = 0; i < MAX; i++) {
		board[i]=' ';
	}
}

char Grid::checkWin() {
	for (int i = 0; i < MAX ; i++) {
		char first = board[i];
		if ( i == 0 || i == 3 || i == 6) {
			if ( first == board[i+1] && first == board[i+2] ) return first;
		}
		if ( i == 0 || i == 1 || i == 2) {
			if ( first == board[i+3] && first == board[i+6]) return first;
		}
		if (i == 0) {
			if ( first == board[4] && first == board[8]) return first;
		}
		if (i == 2) {
			if ( first == board[4] && first == board[6]) return first;
		}
	}
	return 'c';
}

void Grid::play() {
	cout << "Game is starting..." << endl;
	cout << player1 << " is X" << endl;
	cout << player2 << " is O" << endl;

	cout << "Make your move by typing in [1 - 9]" << endl;
	cout << "The numbers correspond to the following locations: " << endl;

	printBoard();
	cout << endl;

	int input;
	while (turn < MAX) {
		if (turn % 2 == 0) {
			current = 'X';
			cout << player1 << ": Please place your " << current << endl;
		} else {
			current = 'O';
			cout << current << ": Please place your " << current << endl;
		}
		printBoard();
		while (cin >> input) {
			if (input > 0 && input <= MAX) {
				if (board[input-1] != 'X' || board[input-1] != 'O') {
					board[input-1] = current;
					break;
				} else {
					cout << "Cannot place in this position." << endl;
				}
			} else {
				cout << "Not a valid position." << endl;
			}
			cout << "Please re-enter your move: " << endl;
			printBoard();
		}
		char result = checkWin();
		if ( result == 'X' ) {
			printBoard();
			cout << player1 << " has won!" << endl;
			win1++;
			total++;
			break;
		} else if (result == 'O') {
			printBoard();
			cout << player2 << " has won!" << endl;
			win2++;
			total++;
			break;
		}
		turn++;

	}
	input = win1;
	win1 = win2;
	win2 = win1;
	resetBoard();
	cout << "Enter [play/score/exit/settings]: " ;
}

void Grid::changeName(string name) {

}