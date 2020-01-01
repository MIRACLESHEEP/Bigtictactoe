#include <iostream>

#include <iostream>

using namespace std;

#include "MiniGame.h"

#include "BigGame.h"

#include "game.h"

#include "Point.h"

#include <curses.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int GridSize = 3;

	// Think of how much space each game needs, exit if there isn't enough space to display the game

	// Each player character + 2 spaces + separators
	int miniGameNeededSize = GridSize + GridSize * 2 + ( GridSize - 1 );

	// Each minigame + 2 spaces + sparators
	int bigGameNeededSize = ( miniGameNeededSize*GridSize ) + (GridSize * 2)+ (GridSize - 1);
	
	
	initscr();
    noecho(); // Don't echo out keypresses.
    cbreak();
    keypad(stdscr,true);


	
	bool  isGoodSize = false;

	if((bigGameNeededSize > COLS) || (bigGameNeededSize > LINES)) {
		cout <<  "Please resize your screen.\n";
		cout <<  "This game needs a screen size of " << bigGameNeededSize << " x " << bigGameNeededSize << "\n";
		cout << "You have provided a screen size of " << COLS << " x " << LINES << "\n";

		// Will try to resize
		resize_term(bigGameNeededSize, bigGameNeededSize);
		if (is_termresized()==false) {
			cout << "Attempt to resize was not successfull\n";
			return(1);
		}
		
		
	}


	bool running = true;
	int key_press;

    



	// Find how big the screen is... at start time, NO Resizing ?!




	//Window is a variable type
	//pointer to a window
	//newwin - makes a new window

	refresh();

	int startX = (COLS - bigGameNeededSize) / 2;
	int startY = (LINES - (bigGameNeededSize + BIG_GAME_STATUS_BAR_LINES)) / 2;
	
	Point gameCoordinates(startY,startX);
	
	BigGame theBigGame(gameCoordinates,COLS,LINES);
		
	// TODO: Mainloop for BigGame/Scoring/exit..
	while(running) {

		 key_press = wgetch(stdscr);

		 theBigGame.play(key_press);

         switch(key_press) {
                 case R_q:
	                 running = false;
	                 break;
                 case R_Q:
	                 running = false;
	                 break;
         } // End Switch/Case
		
	} //End While main loop
	
    endwin();

	return 0;
}
