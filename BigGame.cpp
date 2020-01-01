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

	pointsplayer1 = 0;
	pointsplayer2 = 0;

	selectedGame = false;

 
 	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	
	

	status = newwin(BIG_GAME_STATUS_BAR_LINES,bigGameNeededSize,myY + bigGameNeededSize, myX);
 	refresh();


	// initialized the MiniGames
 	_miniGames[0][0] = MiniGame(Point(myY + 1, myX + 1));
 	_miniGames[1][0] = MiniGame(Point(myY + 1, myX + 15));
 	_miniGames[2][0] = MiniGame(Point(myY + 1, myX + 29));

	_miniGames[0][1] = MiniGame(Point(myY + 15,myX + 1) );
	_miniGames[1][1] = MiniGame(Point(myY + 15,myX + 15));
	_miniGames[2][1] = MiniGame(Point(myY + 15,myX + 29));

	_miniGames[0][2] = MiniGame(Point(myY + 29,myX + 1));
	_miniGames[1][2] = MiniGame(Point(myY + 29,myX + 15));
	_miniGames[2][2] = MiniGame(Point(myY + 29,myX + 29));

}

void BigGame::play(int key_press) {


	
	// If there is no current selected game
	// Player must pick a cell on the BIG Grid to play in.
	// Handle Arrows Up/Down Right/Left to pick a CELL.
	if( selectedGame == false ) {
		// Navigate the big game grid until user selects ( ENTER ) a game
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
			case R_ENTER:
				if( _miniGames[_gridPositionX][_gridPositionY].isWon() == false) {
					selectedGame = true;
				}
				break;
		}

		// Draw the big game
		draw();

	} else {
		// If we have a selected game we play it..
		// Draw the big game
		draw();
		Point nextPosition = _miniGames[_gridPositionX][_gridPositionY].play(currentPlayer,key_press);
		// A play was done in minigame... we need to go to the next minigame
		// If the mini game did a valid play
		if (_miniGames[_gridPositionX][_gridPositionY].isWon()){
			//who has won?
			//was it tied?
		}
		if( _miniGames[_gridPositionX][_gridPositionY].isValidPlay() &&  key_press == R_ENTER ) {
		// Rules for switching games/winning games that are DONE.
		
		if (_miniGames[nextPosition.getX()][nextPosition.getY()].isWon() == false) {
		
		  _gridPositionY = nextPosition.getY();
		  _gridPositionX = nextPosition.getX();
			
			
		} else {
			selectedGame = false;
		}  
		
		  // Switch players
		  if(currentPlayer == PLAYER1 )
		  	 currentPlayer = PLAYER2;
		  else
		  	 currentPlayer = PLAYER1;

		  // Draw again
		  draw();
		}


	}

	cout << " key_press " << key_press << "selectedGame " << selectedGame << "KEY_ENTER" << KEY_ENTER << "\n";
	
}

void BigGame::draw() {
		


	
	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	int ybeg,xbeg;
	int maxX,maxY;

	
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


	// Draw all mini games
	for( int COL=0; COL < GRID_SIZE; COL++ ) {
		for( int ROW=0; ROW < GRID_SIZE; ROW++ ) {
			_miniGames[COL][ROW].draw(false);
		}
	}
	
	if( selectedGame == false ) {
		// Starting position + the location of the cell + separators + number to be in the center of the cell
		int _cursorY = _myStartingPoint.getY() + _gridPositionY*miniGameCellSize + _gridPositionY + (miniGameCellSize/2);
		
		int _cursorX = _myStartingPoint.getX() + _gridPositionX*miniGameCellSize + _gridPositionX + (miniGameCellSize/2);
			// Display Cursor in grid
		move(_cursorY, _cursorX);
	} else {
		// Redraw selected game
		_miniGames[_gridPositionX][_gridPositionY].draw(true);
	}
	
	// cout << "miniGameNeededSize " << miniGameNeededSize <<  "bigGameNeededSize "  << bigGameNeededSize << "_cursorY " << _cursorY << " _cursorX" << _cursorX << "\n";
	
	// Draws the "Status Bar"...
	box(status,0,0);
	refresh();
	mvwprintw(status,1,bigGameNeededSize / 2 - 3, "STATS");
	mvwprintw(status,2,1, "Player 1");
	mvwprintw(status,4,4, "%d",pointsplayer1);
	mvwprintw(status,2,bigGameNeededSize - 10, "Player 2");
	mvwprintw(status,4,bigGameNeededSize - 4, "%d",pointsplayer2);
	mvwprintw(status,5,1, "Current Game %d %d - Selected ? %d",_gridPositionY,_gridPositionX,selectedGame);
	mvwprintw(status,6,1, "Current Player %c",currentPlayer);
	if( selectedGame == true )
		mvwprintw(status,7,1, "Current Game Won? %d",_miniGames[_gridPositionX][_gridPositionY].isWon());
	
	wrefresh(status);
}















