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
  _winner = NONE;

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
	
	// What is this game was finished?
	if (isFinished() == false) {
	
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
	} else {
		int maxSize = 11;
		if (_winner == PLAYER1) {	
			for( int i=0; i < maxSize; i++ ) {
			  mvprintw(myY+i,myX + i,"%c",_winner);
			  mvprintw(myY + i,myX + (maxSize-1) - i,"%c",_winner);
			}
		} else {
			
			for( int i=0; i < maxSize; i++ ) {
			  for(int y=0; y < maxSize; y++) {
			  		if( i==0 || y == 0)
				 	 mvprintw(myY+i,myX + y,"%c",_winner);
			  		if( i==(maxSize-1) || y == (maxSize-1))
				 	 mvprintw(myY+i,myX + y,"%c",_winner);
			  }
			}
		}	
	}

}

bool MiniGame::isValidPlay() {
	return _isValidPlay;
}

bool MiniGame::isFinished() {
	
if(isWon()) 
	return true;

for (int i = 0; i < GRID_SIZE; i++) {
	
	for (int j = 0; j < GRID_SIZE; j++) { 

		if (_grid[i][j] == NONE) 
			return false;
	
		}	
	
	}

	return true;

}

char MiniGame::winner() {
	return _winner;	
}

bool MiniGame::isWon() {
	
	//Detect when a minigame is won
	
	//check rows for matching symbols
	for(int i = 0; i < GRID_SIZE; i++) {
   
		if ((_grid[i][0] == _grid[i][1]) && (_grid[i][1] == _grid[i][2]) && (_grid[i][0] != NONE)) {
			_winner = _grid[i][0];
		return true;	
		}
    	
    }
    
    	//check colls for matching symbols
    for(int i = 0; i < GRID_SIZE; i++) {
		
		if ((_grid[0][i] == _grid[1][i]) && (_grid[1][i] == _grid[2][i]) && (_grid[0][i] != NONE)) {
			_winner = _grid[0][i];
			return true;	
		
		}
    	
    }

	


	//check diagonal for matching symbols
	if ((_grid[0][0] == _grid[1][1]) && (_grid[1][1] == _grid[2][2]) && (_grid[0][0] != NONE)) {
		_winner = _grid[0][0];
			return true;	
		
		}
    
    if ((_grid[0][2] == _grid[1][1]) && (_grid[1][1] == _grid[2][0]) && (_grid[2][0] != NONE)) {
    	_winner = _grid[0][2];
		return true;
    	
	}
    
    
    
	
	
	return false;
	
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
