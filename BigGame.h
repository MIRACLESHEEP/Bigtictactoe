#ifndef BIGGAME_H
#define BIGGAME_H

#include "MiniGame.h"
#include <curses.h>

class BigGame
{
	
	MiniGame _miniGames[3][3];
	
	int _maxY;
	int _maxX;
	Point _point;
	
	// Just for fun a few games ideally they should live in _miniGames
	MiniGame _myMiniGame1;
	MiniGame _myMiniGame2;
	MiniGame _myMiniGame3;


	WINDOW* _bigwin;

	public:
		BigGame(Point aStartingPoint, int maxY, int maxX);

		void play(int key_press);

	protected:
		void draw();

};

#endif
