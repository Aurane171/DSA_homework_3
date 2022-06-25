#include "board.h"
#include <iostream>
#include <windows.h>

using namespace std;

//private
point board::begin()
{
	int row; 
	int col; 
	cout << "A row: "; 
	cin >> row; 
	cout << "A column: "; 
	cin >> col; 
	_board[row][col] = 'a'; 
	_board[row + 1][col] = 'x'; 

	cout << "B row: ";
	cin >> row;
	cout << "B column: ";
	cin >> col;
	_board[row][col] = 'b';

	point B(row, col); 
	return B; 
}

//public
board::board() 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			_board[i][j] = '-'; 
		}
	}
}

void board::next_generation()
{
	point B = begin();  
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (_board[i][j] == 'x')
			{				
					if (j < B.y)
					{
						_board[i][j] = '-';
						_board[i][j + 1] = 'x';
					}
					if (j > B.y)
					{
						_board[i][j] = '-';
						_board[i][j - 1] = 'x';
					}
					if (j == B.y)
					{
						if (i > B.x)
						{
							_board[i - 1][j] = 'x';
							_board[i][j] = '-';
						}
						if (i < B.x)
						{
							_board[i + 1][j] = 'x';
							_board[i][j] = '-';
						}
					}
					if (j == B.y && i == B.x)
					{
						cout << "done"<<endl; 
						return; 
					}
					draw();
					
				}
			
		}
	}
}


void board::draw()
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << _board[i][j] << " "; 

		}
		cout << endl; 
	}
	Sleep(100);
	system("cls"); 
}