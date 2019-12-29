#include "BigGame.h"

#include "Point.h"

#include "MiniGame.h"

#include "game.h"

#include <curses.h>

BigGame::BigGame(Point aStartingPoint, int maxY, int maxX): _myStartingPoint(aStartingPoint), _maxY(maxY), _maxX(_maxY)
{

 	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
 	
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


	// Draw the big game
	draw();
	
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

}

void BigGame::draw() {
		
	int GridSize = 3;

	// Each player character + 2 spaces + separators
	int miniGameNeededSize = GridSize + GridSize * 2 + ( GridSize - 1 );

	// Each minigame + 2 spaces + sparators
	int bigGameNeededSize = ( miniGameNeededSize*GridSize ) + (GridSize * 2)+ (GridSize - 1);

	
	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	
	// Draw the BIG Grid
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "---------------------------------------");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "---------------------------------------");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");
	mvprintw(myY++, myX, "            |             |            ");

		
	
	// Draws the "Status Bar"...

	
} 
