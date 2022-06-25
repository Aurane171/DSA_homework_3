#pragma once

struct point {
	int x;
	int y;
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class board
{
	static const int row = 20; 
	static const int col = 40; 
	char _board[row][col]; 
	char _next_board[row][col]; 
	point begin();
public: 
	board();
	void next_generation(); 
	void draw(); 
};



