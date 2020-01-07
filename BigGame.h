#ifndef BIGGAME_H
#define BIGGAME_H
#include "Infobar.h"
#include "MiniGame.h"
#include <curses.h>

class BigGame
{
	static const int GRID_SIZE = 3;
	
	MiniGame _miniGames[GRID_SIZE][GRID_SIZE];
	
	int _maxY;
	int _maxX;
	Point _myStartingPoint;
	WINDOW * status;
	
	// This is the position of the cursor on the Grid
	int _gridPositionY;
	int _gridPositionX;

	int miniGameNeededSize;
	int miniGameCellSize;
	int bigGameNeededSize;
	
	bool selectedGame;
	
	//Point counter variables for player one and two
	int pointsplayer1;
	int pointsplayer2;
	
	char currentPlayer = PLAYER1;

	//detects of the big game is won
	bool isBigGameWon();
	bool isBigGameFinished();
	bool isBigGameTied();
	char BigGamewinner();
	

	public:
		BigGame(Point aStartingPoint, int maxY, int maxX);

		void play(int key_press);
		void draw();
		void reset();

	protected:
		

};

#endif
