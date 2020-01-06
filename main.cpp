/********************************************
 *                                           *
 * Name: John Khalife                        *
 * Date: December 24th, 2019	             *  
 * Version: Dev C++ 5.11                     *
 * Purpose:	Assignment 	Pigkle				 *					
 *											 *
 *********************************************/


#include <iostream>

#include <windows.h>

using namespace std;

#include "MiniGame.h"

#include "BigGame.h"

#include "game.h"

#include "Point.h"

#include <curses.h>

#include<cstdlib>

/* Data dictionnary
int gridsize - saves the size of the bigtictac grid
int miniGameNeededSize - saves the size needed for a mini tic tac to game
int bigGameNeededSize - saves the size needed for the bigtictactoe game
int bigGameNeededLines - saves the total number of lines needed for the bigtictactoe game
char intro - saves the user's response to whether or not they would like to see the intro
*/


//Declaring intro function
void intro();

void slowtext(string phrase);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//calling the intro function
	intro();
	
	
	int GridSize = 3;

	// Think of how much space each game needs, exit if there isn't enough space to display the game

	// Each player character + 2 spaces + separators
	int miniGameNeededSize = GridSize + GridSize * 2 + ( GridSize - 1 );

	// Each minigame + 2 spaces + sparators
	int bigGameNeededSize = ( miniGameNeededSize*GridSize ) + (GridSize * 2)+ (GridSize - 1);
	
	int bigGameNeededLines = bigGameNeededSize + BIG_GAME_STATUS_BAR_LINES + 2;
	
	initscr();//turns on Ncurses
    noecho(); // Don't echo out keypresses.
    cbreak();//makes it so that ctrl + c exits
    keypad(stdscr,true);

	int key_press;

	
	bool  isGoodSize = false;

	bool running = true;
	
   do {

	if((bigGameNeededSize <= COLS) && (bigGameNeededLines <= LINES)) {
		isGoodSize=true; 
	} else {
	   	clear();
	   	printw("Please resize the screen - This game needs a screen size of %d %d\n",bigGameNeededSize,bigGameNeededLines);
		printw("You have provided a screen size of %d %d\n",COLS,LINES);
		printw("It is recommended that you maximize your screen\n");
		
		key_press = wgetch(stdscr);

		// Will try to resize
		if (is_termresized()==false) {
			printw("Attempt to resize was not successfull\n");
		} else {
			resize_term(0,0);
		}

         switch(key_press) {
                 case R_q:
	                 running = false;
	                 break;
                 case R_Q:
	                 running = false;
	                 break;
         } // End Switch/Case

	}
	
	} while( (isGoodSize == false) && (running == true ));
	clear();
	

    



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

		 theBigGame.draw();

		 key_press = wgetch(stdscr);

		 theBigGame.play(key_press);

         switch(key_press) {
                 case R_q:
	                 running = false;
	                 break;
                 case R_Q:
	                 running = false;
	                 break;
	             case R_r:
	             	theBigGame.reset();
				 	break;         
				case R_R:
	             	theBigGame.reset();
				 	break;
         } // End Switch/Case
		
	} //End While main loop
	
    endwin();

	return 0;
}

//defining intro function
void intro() {
	

	initscr();
	noecho();
	cbreak();
	
	mvprintw( 1, COLS / 2 - 7, "BIG TIC TAC TOE");
	mvprintw(5,COLS / 2 - 5, "   |   |   ");
	mvprintw(6,COLS / 2 - 5, "   |   |   ");
	mvprintw(7,COLS / 2 - 5, "   |   |   ");
	mvprintw(8,COLS / 2 - 5,  "---+---+---");
	mvprintw(9,COLS / 2 - 5, "   |   |   ");
	mvprintw(10,COLS / 2 - 5, "   |   |   ");
	mvprintw(11,COLS / 2 - 5, "   |   |   ");
	mvprintw(12,COLS / 2 - 5,  "---+---+---");
	mvprintw(13,COLS / 2 - 5, "   |   |   ");
	mvprintw(14,COLS / 2 - 5, "   |   |   ");
	mvprintw(15,COLS / 2 - 5, "   |   |   ");
	
	mvprintw(18,COLS / 2 - 7,"By John Khalife");
	mvprintw(22,COLS / 2 - 11, "Press any key to start:");
	getch();
	
	endwin();




	char intro;
	
	//Asking user if they would like to listen to the intro
	cout<< "Would you like to see the explanation of this game?\n";
	cout<< "Press 'n' if the answer is no, and any other key if you would like to see the intro.\n";
	cout<< "Enter your answer here:\n";
	intro = getch();
	system("cls");
	if (intro == 110) {
		

	} else {
	
	//Explain here
	slowtext("Hello!\n");
	slowtext("This is my sommative for Icsu grade ten.\n");
	slowtext("The program I chose to make for it is called bigtictactoe.\n");
	slowtext("The rules are a little complicated\n\n");
	slowtext("Press any key to continue:\n");
	getch();
	system("cls");
	

	slowtext("I will start with the controls:\n");
	slowtext("To select a small game of tic tac toe, or to mark a grid, press ENTER.\n");
	slowtext("To move the cursor around, use the arrow keys.\n");
	slowtext("if you want to quit the game once it has begun, press upper or lower case Q.\n");
	slowtext("If you want to restart the game once it has begun, press upper or lower case R.\n\n");
	slowtext("Those are all the controls. Press any key to continue:\n");
	getch();
	system("cls");
	
	slowtext("Let's move on to how to play:\n");
	slowtext("In this game, there are two players.\n");
	slowtext("The board consists of nine small tictactoe games inside one big tic tac toe grid.\n");
	slowtext("The goal of the game is to win the majority of the Minigames.\n\n");
	slowtext("Press any key to continue:\n");
	getch();
	system("cls");
	
	slowtext("Player one first begins the game.\n");
	slowtext("They can choose any one of the minigames on the big tic tac toe grid.\n");
	slowtext("Then, they are allowed to mark a spot on the grid they chose.\n");
	slowtext("After that, it is the next player's turn.\n");
	slowtext("They are sent to the minigame that is equivalent to the spot player 1 chose on the minigame they chose.\n");
	slowtext("For example, if player one played in the middle position of one of the minigames, player two would be sent\nto the middle minigame of the board.\n\n");
	slowtext("This is the main mechanic of the game.\n");
	slowtext("Press any key to continue:\n");
	getch();
	system("cls");
	
	slowtext("After playing for a while, if one of the players wins a minigame or the minigame is filled,\nno players can be sent back to that minigame.\n");
	slowtext("If they are, that player will be able to pick any minigame on the board to play in instead.\n\n");
	slowtext("Press any key to continue:\n");
	getch();
	system("cls");
	
	slowtext("The game will end once all the minigames have been one or there are no spaces left to fill up.\n\n");
	slowtext("These are all the instructions.\n");
	slowtext("Press any key to continue to the game:\n");
	getch();
	system("cls");
	
	}
	
}

void slowtext(string phrase) {
	
	cout<< phrase;
	Sleep(1000);
	
}

