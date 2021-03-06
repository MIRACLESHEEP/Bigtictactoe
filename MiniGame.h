#ifndef MINIGAME_H
#define MINIGAME_H
#include "Infobar.h"

#include "Infobar.h"

#include "Point.h"
#include<curses.h>
#include "game.h"

class MiniGame
{
	Point _myStartingPoint;
	

	
	static const int GRID_SIZE = 3;
	
	// A grid of Y/X for the game, having EMPTY, _player1 or _player2;
	char _grid[GRID_SIZE][GRID_SIZE];

	char _winner;

	// This is the position of the cursor on the Grid
	int _gridPositionY;
	int _gridPositionX;
	
	bool _isValidPlay;
	
	public:
		// A game need to have a starting co-ordinates
		MiniGame() {
		}

		MiniGame(Point aStartingPoint);
		
		// Plays a turn for play, it returns the last point (x,y)
		Point play(char player,int key_press);
		
		//Things I want the big gane to know 
		//these will go into public because I want them to be seen by bic tic tac class
		bool isWon();
		bool isGameFinished();
		bool isValidPlay();
		char winner();

		bool isFinished();
		
		// Resets the game
		void reset();
		
		//draws the board
		void draw(bool showCursor);

		
	protected:
	
			
};

#endif
