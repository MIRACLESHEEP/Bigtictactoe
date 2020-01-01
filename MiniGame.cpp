#include "MiniGame.h"

#include <iostream>
using namespace std;
#include "Point.h"

MiniGame::MiniGame(Point aStartingPoint): _myStartingPoint(aStartingPoint)
{
 reset();
}



void MiniGame::reset() {
	
  _gridPositionY = 1;
  _gridPositionX = 1;
  _isValidPlay = false;

   // Start with all spaces/NONE
   for(int i = 0; i < GRID_SIZE; i++) {
		for(int j = 0; j < GRID_SIZE; j++) {
			_grid[i][j] = NONE;
    	}
    }
}

void MiniGame::draw(bool showCursor) {
  
	
	int myY = _myStartingPoint.getY();
	int myX = _myStartingPoint.getX();
	
	
	mvprintw(myY++, myX, "   |   |   ");
	mvprintw(myY++, myX, " %c | %c | %c ", _grid[0][0], _grid[0][1], _grid[0][2]);
	mvprintw(myY++, myX, "   |   |   ");
	mvprintw(myY++, myX,  "---+---+---");
	mvprintw(myY++, myX, "   |   |   ");
	mvprintw(myY++, myX, " %c | %c | %c ", _grid[1][0], _grid[1][1], _grid[1][2]);
	mvprintw(myY++, myX, "   |   |   ");
	mvprintw(myY++, myX, "---+---+---");
	mvprintw(myY++, myX, "   |   |   ");
	mvprintw(myY++, myX, " %c | %c | %c ", _grid[2][0], _grid[2][1], _grid[2][2]);
	mvprintw(myY++, myX, "   |   |   ");

	if( showCursor == true ) {
		// Put Cursor in current position
		int _cursorY = _myStartingPoint.getY() + _gridPositionY*3 + _gridPositionY + 1;
		int _cursorX = _myStartingPoint.getX() + _gridPositionX*3 + _gridPositionX + 1;
		
		// Display Cursor in grid
		move(_cursorY, _cursorX);
	}
	

}

bool MiniGame::isValidPlay() {
	return _isValidPlay;
}

Point MiniGame::play(char currentPlayer,int key_press) {

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
			// If the current space is the 'NONE' player
			if(_grid[_gridPositionY][_gridPositionX] == NONE) {
				_grid[_gridPositionY][_gridPositionX] = currentPlayer;
				_isValidPlay = true;
				// Do other STUFF ?!
			} else {
				_isValidPlay = false;
				// Occupied position ... somehow show that...
				// mvprintw(_mY / 2 - 10, _mX / 2 - 6, "OCCUPIED");
			}
			break;
			
	}

	
	/*cout << " key_press " << key_press << "\n";
	cout << " _gridPositionX " << _gridPositionX << "\n";
	cout << " _gridPositionY " << _gridPositionY << "\n"; */
	
	draw(true);
	
	
	return Point(_gridPositionY,_gridPositionX);
} 
