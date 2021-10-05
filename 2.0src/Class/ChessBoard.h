#pragma once

#define DEBUG 1
class ChessBoard
{
public:
	ChessBoard(int queen);
	ChessBoard() { ; }
	~ChessBoard() { ; }

	void OutPut();
	void PlaceQueen(int row);

	//how many solution have been found
	const int GetSlnNum()const;

	//If (row,col) can place a queen
	bool Check(int row, int col);

	//If (row,col) is in the corrent range
	bool ifInside(int row, int col);
private:
	int m_queen;//the number of the queen
	int m_sln;//the solution of this problem

	bool* m_pChessboard;
};

