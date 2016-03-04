#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Grid;

class Controller {
	Grid * game;

public:
	Controller ();
	void start();
	void score();
	void settings();

};
#endif