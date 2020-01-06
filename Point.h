#ifndef POINT_H
#define POINT_H



class Point
{
	int _x;
	int _y;
	public:
		
		Point() : _x(0) , _y(0) {};
		
		Point(int y, int x);
		
		int getX() { return _x; };
		int getY() { return _y; };

	protected:

};

#endif
