#include "BigGame.h"

#include "Point.h"

#include "MiniGame.h"

#include "game.h"

#include <curses.h>

#include <iostream>
using namespace std;


BigGame::BigGame(Point aStartingPoint, int maxY, int maxX): _myStartingPoint(aStartingPoint), _maxY(maxY), _maxX(_maxY)
{


	// Each player character + 2 spaces + separators
	miniGameNeededSize = GRID_SIZE + GRID_SIZE * 2 + ( GRID_SIZE - 1 );

	// With added spaces
	miniGameCellSize = miniGameNeededSize + 2;

	// Each minigame + 2 spaces + sparators
	bigGameNeededSize = ( miniGameNeededSize*GRID_SIZE ) + (GRID_SIZE * 2)+ (GRID_SIZE - 1);

	_gridPositionY = 1;
    _gridPositionX = 1;
 
 	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	//status = newwin(20,40,myY + 42, myX + 42);
 	status = newwin(BIG_GAME_STATUS_BAR_LINES,bigGameNeededSize,myY + bigGameNeededSize, myX);
 	refresh();
 	
 	
	_myMiniGame1 = MiniGame(Point(myY + 1 ,myX));
	_myMiniGame2 = MiniGame(Point(myY + 1,myX + 14));
	_myMiniGame3 = MiniGame(Point(myY + 1,myX + 28));
	_myMiniGame4 = MiniGame(Point(myY + 13,myX));
	_myMiniGame5 = MiniGame(Point(myY + 13,myX + 14));
	_myMiniGame6 = MiniGame(Point(myY + 13,myX + 28));
	_myMiniGame7 = MiniGame(Point(myY + 26,myX));
	_myMiniGame8 = MiniGame(Point(myY + 26,myX + 14));
	_myMiniGame9 = MiniGame(Point(myY + 26,myX + 28));
	



}

void BigGame::play(int key_press) {


	
	// Find Current Active Game
	
	// If there is not current active game
	// Player must pick a cell on the BIG Grid to play in.
	// Handle Arrows Up/Down Right/Left to pick a CELL.
	
	// Play current Game
	// Have mini game draw itself and play..


	/*
	_myMiniGame1.play(PLAYER1,key_press);

	_myMiniGame2.play(PLAYER2,key_press);

	_myMiniGame3.play(PLAYER1,key_press);
	
	_myMiniGame4.play(PLAYER2,key_press);
	
	_myMiniGame5.play(PLAYER1,key_press);
	
	_myMiniGame6.play(PLAYER2,key_press);
	
	_myMiniGame7.play(PLAYER1,key_press);
	
	_myMiniGame8.play(PLAYER2,key_press);
	
	_myMiniGame9.play(PLAYER1,key_press); */
	switch(key_press) {	
			case KEY_LEFT:
			if(_gridPositionX > 0) _gridPositionX--;
			break;
		case KEY_RIGHT:
			if(_gridPositionX < (GRID_SIZE-1)) _gridPositionX++;
			break;
		case KEY_UP:
			if(_gridPositionY > 0) _gridPositionY--;
			break;
		case KEY_DOWN:
			if(_gridPositionY < (GRID_SIZE-1)) _gridPositionY++;
			break;
		/*	
		case R_ENTER:
			// If the current space is the 'NONE' player
			if(_grid[_gridPositionY][_gridPositionX] == NONE) {
				_grid[_gridPositionY][_gridPositionX] = currentPlayer;

				// Do other STUFF ?!
			} else {
				// Occupied position ... somehow show that...
				// mvprintw(_mY / 2 - 10, _mX / 2 - 6, "OCCUPIED");
			}
			break;*/
			
	}


	// Draw the big game
	draw();
	//_myMiniGame1.play(PLAYER1,key_press);
}

void BigGame::draw() {
		


	
	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	
	// Draw the BIG Grid
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "-----------------------------------------");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "-----------------------------------------");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             ");
	mvprintw(myY++, myX, "             |             |             "); 



		
	// Starting position + the location of the cell + separators + number to be in the center of the cell
	int _cursorY = _myStartingPoint.getY() + _gridPositionY*miniGameCellSize + _gridPositionY + (miniGameCellSize/2);
	
	int _cursorX = _myStartingPoint.getX() + _gridPositionX*miniGameCellSize + _gridPositionX + (miniGameCellSize/2);
		// Display Cursor in grid
	move(_cursorY, _cursorX);
	
	cout << "miniGameNeededSize " << miniGameNeededSize <<  "bigGameNeededSize "  << bigGameNeededSize << "_cursorY " << _cursorY << " _cursorX" << _cursorX << "\n";
	
	// Draws the "Status Bar"...

	box(status,121,121);
	mvwprintw(status,5,5, "This is john's box");
	wrefresh(status);
	
} 
