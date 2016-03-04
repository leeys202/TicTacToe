#include "Controller.h"
#include "Grid.h"
#include <iostream>
using namespace std;

int main() {
	Controller * controller = new Controller;
	bool stop = false;
	string response;
	cout << "Enter [play/score/exit/settings]: " ;
	while ( stop == false) {
		cin >> response;
		if ( response == "play") {
			controller->start();
		} else if (response == "exit") {
			stop = true;
		} else if (response == "score") {
			controller->score();
		} else {
			cout << "Enter [play/score/exit/settings]: " ;
		}
	}
	delete controller;
}