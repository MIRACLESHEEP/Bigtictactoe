#include "Infobar.h"
#include <iostream>
#include "game.h"
#include<cstring>

using namespace std;


Infobar::Infobar (int starty, int startx, int bigGameNeededSize): _myheight(BIG_GAME_STATUS_BAR_LINES), _mywidth(bigGameNeededSize+starty), _bigGameNeededSize(bigGameNeededSize), _starty(starty), _startx(startx)
{
	_mywin = newwin(_myheight,_mywidth,_starty,_startx);
	
	// status = newwin(BIG_GAME_STATUS_BAR_LINES,bigGameNeededSize,myY + bigGameNeededSize, myX);
    // refresh();
	
}

void Infobar::draw() {
		
 
	  // Draws the "Status Bar"...
       box(_mywin,0,0);
       refresh();
       mvwprintw(_mywin,1,_bigGameNeededSize / 2 - 3, "STATS");
       mvwprintw(_mywin,2,1, "Player 1");
       mvwprintw(_mywin,4,4, "%d",_pointsPlayer1);
       mvwprintw(_mywin,2,_bigGameNeededSize - 10, "Player 2");
       mvwprintw(_mywin,4,_bigGameNeededSize - 4, "%d",_pointsPlayer2);
//       mvwprintw(status,5,1, "Current Game %d %d - Selected ? %d",_gridPositionY,_gridPositionX,selectedGame);
       mvwprintw(_mywin,6,1, "Current Player %c",_currentPlayer);
       
       //if( selectedGame == true )
       //       mvwprintw(status,7,1, "Current Game Won? %d",_miniGames[_gridPositionX][_gridPositionY].isWon());

       wrefresh(_mywin);

	
	
	
}


void Infobar::updateScore(int pointsPlayer1, int pointsPlayer2, int currentPlayer) {
	
	_pointsPlayer1 = pointsPlayer1;
	_pointsPlayer2 = pointsPlayer2; 
	_currentPlayer = currentPlayer; 
	

}

void Infobar::showmessage(string message) {
    mvwprintw(_mywin,5,1, "%s",message.c_str());
    wrefresh(_mywin);
}
