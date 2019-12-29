#include "BigGame.h"

#include "Point.h"

#include "MiniGame.h"

#include "game.h"

#include <curses.h>

BigGame::BigGame(Point aStartingPoint, int maxY, int maxX): _point(aStartingPoint), _maxY(maxY), _maxX(_maxY)
{

 	
	_myMiniGame1 = MiniGame(Point(0,0));
	_myMiniGame2 = MiniGame(Point(12,30));
	_myMiniGame3 = MiniGame(Point(20,90));
	



}

void BigGame::play(int key_press) {
	 //mvprintw(_point.getY(), _point.getX(), "   Max X is %i  |  Max Y is %i  ", _maxX, _maxY); 	
	
	 // Have mini game draw itself and play..
	 _myMiniGame1.play(PLAYER1,key_press);

	 _myMiniGame2.play(PLAYER2,key_press);

	 _myMiniGame3.play(PLAYER1,key_press);

}

void BigGame::draw() {
		
	int GridSize = 3;

	// Think of how much space each game needs, exit if there isn't enough space to display the game

	// Each player character + 2 spaces + separators
	int miniGameNeededSize = GridSize + GridSize * 2 + ( GridSize - 1 );

	// Each minigame + 2 spaces + sparators
	int bigGameNeededSize = ( miniGameNeededSize*GridSize ) + (GridSize * 2)+ (GridSize - 1);
	
	
} 
