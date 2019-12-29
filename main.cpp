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
	
	int maxX, maxY;
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

	getmaxyx(stdscr, maxY, maxX);
	if((bigGameNeededSize > maxY) || (bigGameNeededSize > maxX)) {
		cout <<  "Please resize your screen.\n";
		cout <<  "This game needs a screen size of " << bigGameNeededSize << " x " << bigGameNeededSize << "\n";
		cout << "You have provided a screen size of " << maxX << " x " << maxY << "\n";
		return(1);
	}


/*
	do {
		
		initscr();
		getmaxyx(stdscr, maxY, maxX);
		refresh();
		if((bigGameNeededSize > maxY) || (bigGameNeededSize > maxX)) {
		printw( "Please resize your screen.\n");
		printw(  "This game needs a screen size of %d x %d.\n", bigGameNeededSize, bigGameNeededSize);
		printw( "You have provided a screen size of %d x %d.\n", maxX , maxY );
		printw("Enter any key once you have resized your screen:\n");
		getch();
		clear();
		refresh();
	} else {
		isGoodSize = true;
	}   

	} while( isGoodSize == false );
	*/

	bool running = true;
	int key_press;

    



	// Find how big the screen is... at start time, NO Resizing ?!




	//Window is a variable type
	//pointer to a window
	//newwin - makes a new window

	refresh();

	
	
	Point gameCoordinates(0,0);
	
	BigGame theBigGame(gameCoordinates,maxY,maxY);
		
	// TODO: Mainloop for BigGame/Scoring/exit..
	while(running) {

		 key_press = wgetch(stdscr);

		 theBigGame.play(key_press);

         switch(key_press) {
                 case R_Q:
	                 running = false;
	                 break;
         } // End Switch/Case
		
	} //End While main loop
	
    endwin();

	return 0;
}
