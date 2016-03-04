#include <iostream>
#include "controller.h"
#include "grid.h"

using namespace std;

Controller::Controller() {
	game = new Grid;
}


// starts the game by calling grid
void Controller::start() {
	game->play();
}

void Controller::score() {

}

void Controller::settings() {

}
