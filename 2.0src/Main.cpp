
#include <iostream>
#include "Class/ChessBoard.h"
using namespace std;

int main()
{
	cout << "现有N x N 的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上！\n\n";
	cout << "请输入皇后个数:";
	int queen_number = 0;
	cin >> queen_number;

	while (cin.fail() || queen_number <= 0) {
		cout << "输入错误，请重新输入：\n";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> queen_number;
	}

	cout << '\n';
	
	ChessBoard chess = ChessBoard(queen_number);

	cout << "皇后摆法\n\n";
	chess.PlaceQueen(0);//begin with the first line

	cout << "八皇后问题共有" << chess.GetSlnNum() << "种解！" << endl;
	return 0;
}