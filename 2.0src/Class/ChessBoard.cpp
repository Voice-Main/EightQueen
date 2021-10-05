#include "ChessBoard.h"
#include <iostream>
using namespace std;

#if DEBUG
#include "Log.h"
#endif // DEBUG

#define Placed   true
#define UnPlaced false

ChessBoard::ChessBoard(int queen)
{
	m_queen = queen;
	m_pChessboard = new bool[queen * queen];
	if (DEBUG && !m_pChessboard){
		Log::Error("nullptr in chessboard's construction");
		return;
	}
	bool* p = m_pChessboard;
	for (int i = 0; i < queen * queen; i++) {
		*p = UnPlaced;
		p++;
	}
}

void ChessBoard::OutPut()
{
	m_sln++;
	cout << "第" << m_sln << "种解法：\n\n";
	bool* p = m_pChessboard;
	for (int i = 0; i < m_queen * m_queen; i++) {
		if (*p == Placed) {
			cout << "x ";
		}
		else {
			cout << *p << ' ';
		}
		if ( (i+1) % m_queen == 0) {
			cout << '\n';
		}
		p++;
	}
	cout << "\n\n";
}

void ChessBoard::PlaceQueen(int row)
{
	bool* p = m_pChessboard;//p is the head of the chessboard
	for (int column = 0; column < m_queen; column++)//look every col
	{
		*(p + (row * m_queen) + column) = Placed;
		//== array[row][column] = Placed;
		//just try if this place can place a queen

		if (Check(row, column))
		{
			if (row + 1 == m_queen)//this row is the last row and you can place a queen successfully, so it's a kind of solution
			{
				OutPut();
			}
			else//in the middle line, this place is fine, and you need to keep trying the next line
			{
				PlaceQueen(row + 1);
			}
		}
		*(p + (row * m_queen) + column) = UnPlaced;
		// == array[row][column] = false;
		//if you finish a method, to get another method, you need to remove the queen that's been placed
	}
}

const int ChessBoard::GetSlnNum() const
{
	return m_sln;
}

bool ChessBoard::Check(int row, int col)
{
	bool* p = m_pChessboard;
	if (row == 0) {
		return true;//the first row, you can even place anywhere
	}

	//check the previous col
	for (int i = 0; i < row; i++) {
		if (*(p + (i * m_queen) + col) == Placed) {
			return false;
		}
	}

	int x = row, y = col;
	//check the diagonal(对角线), four direction
	//1. left_above
	x--;
	y--;
	while (1)
	{
		if (!ifInside(x, y)) {
			break;//break the border, if you got this step, this direction is placeable
		}

		if (*(p + (x * m_queen) + y) == UnPlaced) {
			x--;
			y--;
		}
		else {//you have placed a queen here
			return false;
		}
	}

	x = row, y = col;//return the origin point
	//2. right_above
	x++;
	y--;
	while (1)
	{
		if (!ifInside(x, y)) {
			break;//break the border
		}

		if (*(p + (x * m_queen) + y) == UnPlaced) {
			x++;
			y--;
		}
		else {//you have placed a queen here
			return false;
		}
	}

	x = row, y = col;//return the origin point
	//3. right_down
	x++;
	y++;
	while (1)
	{
		if (!ifInside(x, y)) {
			break;//break the border
		}

		if (*(p + (x * m_queen) + y) == UnPlaced) {
			x++;
			y++;
		}
		else {//you have placed a queen here
			return false;
		}
	}

	x = row, y = col;//return the origin point
	//4. left_down
	x--;
	y++;
	while (1)
	{
		if (!ifInside(x, y)) {
			break;//break the border
		}

		if (*(p + (x * m_queen) + y) == UnPlaced) {
			x--;
			y++;
		}
		else {//you have placed a queen here
			return false;
		}
	}

	return true;
}

bool ChessBoard::ifInside(int row, int col)
{
	if (row >= 0 && col >= 0) {
		if (row < m_queen && col < m_queen) {
			return true;
		}
	}
	return false;
}

