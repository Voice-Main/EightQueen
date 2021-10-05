
#include <iostream>
#include "Class/ChessBoard.h"
using namespace std;

int main()
{
	cout << "����N x N �����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��к�ͬһб���ϣ�\n\n";
	cout << "������ʺ����:";
	int queen_number = 0;
	cin >> queen_number;

	while (cin.fail() || queen_number <= 0) {
		cout << "����������������룺\n";
		cin.clear();
		cin.ignore(65535, '\n');
		cin >> queen_number;
	}

	cout << '\n';
	
	ChessBoard chess = ChessBoard(queen_number);

	cout << "�ʺ�ڷ�\n\n";
	chess.PlaceQueen(0);//begin with the first line

	cout << "�˻ʺ����⹲��" << chess.GetSlnNum() << "�ֽ⣡" << endl;
	return 0;
}