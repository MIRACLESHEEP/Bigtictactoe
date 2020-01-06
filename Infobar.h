#ifndef INFOBAR_H
#define INFOBAR_H

#include <curses.h>

#include <iostream>
using namespace std;

class Infobar
{
	public:
		Infobar() {};
		Infobar(int starty, int startx, int bigGameNeededSize);
		
		int _myheight;
		int _mywidth;
		int _starty;
		int _startx;
		
		int _pointsPlayer1;
		int _pointsPlayer2;
		int _currentPlayer;
		
		
		
		WINDOW * _mywin;

	
	    int _bigGameNeededSize;
	
	
		//draw box and info inside
		void draw();
	
		void updateScore(int pointsPlayer1, int pointsPlayer2, int currentPlayer);
		
		void showmessage(string message);
	
	protected:
		
		
		
};

#endif
