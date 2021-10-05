#include <iostream>
using namespace std;

const int QueenNumber = 6;
static int totalSln = 0;
int count1 = 0;
#define Placed   true
#define UnPlaced false

//the position(x,y) is inside the chessBoard
bool ifInside(int row, int col);
void placeQueen(bool array[][QueenNumber], int row);
bool check(bool array[][QueenNumber], int row, int col);
void Output(bool array[][QueenNumber]);
int main()
{

	bool chessBoard[QueenNumber][QueenNumber];
	for (int i = 0; i < QueenNumber; i++) {
		for (int j = 0; j < QueenNumber; j++) {
			chessBoard[i][j] = UnPlaced;
		}
	}

	placeQueen(chessBoard, 0);//begin with the first row
	cout << "八皇后问题共有" << totalSln << "种解！" << endl;
	cout << "cout: " << count1 << endl;
}

bool ifInside(int row, int col)
{
	if (row >= 0 && col >= 0) {
		if (row < QueenNumber && col < QueenNumber) {
			return true;
		}
	}
	return false;
}

void placeQueen(bool array[][QueenNumber], int row)
{
	const int column = QueenNumber;
	count1++;
	for (int column = 0; column < QueenNumber; column++)//look every col
	{
		array[row][column] = Placed;//just try
		//if this place can place a queen
		if (check(array, row, column))
		{
			if (row + 1 == QueenNumber)//this row is the last row and you can place a queen successfully, so it's a kind of solution
			{
				Output(array);
			}
			else//in the middle line, this place is fine, and you need to keep trying the next line
			{
				placeQueen(array, row + 1);
			}
		}
		array[row][column] = false;//if you finish a method, to get another method, you need to remove the queen that's been placed
	}
}

//if I put the queen in the (row,col), if there is a conflict with all previos operations
bool check(bool array[][QueenNumber], int row, int col)
{
	if (row == 0) {
		return true;//the first row, you can even place anywhere
	}

	//check the previous col
	for (int i = 0; i < row; i++) {
		if (array[i][col] == Placed) {
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

		if (array[x][y] == UnPlaced) {
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

		if (array[x][y] == UnPlaced) {
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

		if (array[x][y] == UnPlaced) {
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

		if (array[x][y] == UnPlaced) {
			x--;
			y++;
		}
		else {//you have placed a queen here
			return false;
		}
	}

	return true;
}

void Output(bool array[][QueenNumber])
{
	totalSln++;
	cout << "第" << totalSln << "种解：\n";
	for (int i = 0; i < QueenNumber; i++) {
		for (int j = 0; j < QueenNumber; j++) {
			if (array[i][j] == Placed) {
				cout << "x ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
