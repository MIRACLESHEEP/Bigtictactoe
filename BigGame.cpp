#include "BigGame.h"

#include "Point.h"

#include "MiniGame.h"

#include <curses.h>

BigGame::BigGame(WINDOW* mywindow,Point aStartingPoint, int maxY, int maxX): _bigwin(mywindow), _point(aStartingPoint), _maxY(maxY), _maxX(_maxY)
{
	
	int GridSize = 3;

	// Think of how much space each game needs, exit if there isn't enough space to display the game

	// Each player character + 2 spaces + separators
	int miniGameNeededSize = GridSize + GridSize * 2 + ( GridSize - 1 );

	// Each minigame + 2 spaces + sparators
	int bigGameNeededSize = ( miniGameNeededSize*GridSize ) + (GridSize * 2)+ (GridSize - 1);

	
	WINDOW * mywin1 = newwin(miniGameNeededSize,miniGameNeededSize,1,1);
 	
	_myMiniGame1 = MiniGame(mywin1,Point(0,0), 'x','o' );
	_myMiniGame2 = MiniGame(mywin1,Point(12,30), 'x','o' );
	_myMiniGame3 = MiniGame(mywin1,Point(20,90), 'x','o' );
	

}

void BigGame::play(int key_press) {
	 //mvprintw(_point.getY(), _point.getX(), "   Max X is %i  |  Max Y is %i  ", _maxX, _maxY); 	
	
	 // Have mini game draw itself and play..
	 _myMiniGame1.play('x',key_press);

	 _myMiniGame2.play('o',key_press);

	 _myMiniGame3.play('x',key_press);

}
