#include "GameManager.h"
#include "CardDeck.h"
#include <algorithm>


using std::cout;
using std::endl;

void clearScreen();

int main()
{

	// ������� ��ü ����
	OldMaid game1;

	// 1. ���� ������ ���� ���� Ȯ�� â
	cout << "������� \n";
	cout << "�ٸ� ������ ��ٸ�����....";
	/*
	if (��� ���� ����)
	{
		cout << "��� ������ �����Ͽ����ϴ� ! "<< endl << "������ �����մϴ�";
	}
	*/

	// ȭ�� �ʱ�ȭ
	// clearScreen();  
	cout << endl<< game1.getzeroCnt() << endl;
	// 2. ���� ���� â
	cout << "������� \n";
	cout << "���� ���� ! \n\n";

	// 2 - 1) ī�� �й�
	cout << "(1) ī�带 �й��մϴ�.\n";
	game1.dealCard();

	cout << "ī�� �й� ��� \n";
	cout << "Player 1 Cards: ";
	for (const string& card : game1.getPlayer1Cards()) {
		cout << card << " ";
	}
	cout << endl;

	cout << "Player 2 Cards: ";
	for (const string& card : game1.getPlayer2Cards()) {
		cout << card << " ";
	}
	cout << endl;

	cout << "Player 3 Cards: ";
	for (const string& card : game1.getPlayer3Cards()) {
		cout << card << " ";
	}
	cout << endl << endl;

	// if JK ���� ����
	// cout << "��Ŀ�Դϴ�! �������� �������ּ���\n"
	// else ���� ī�忡 ��Ŀ�� �����ϴ� ;

	// 2 - 2) �ߺ� ī�带 ������
	cout << "(2) �ߺ��� ����ī�带 �����ϴ�.\n";
	cout << "ī�带 �����ּ���.\n";
	game1.disCard();

	cout << "Player 1 Cards: ";
	for (const string& card : game1.getPlayer1Cards()) {
		cout << card << " ";
	}
	cout << endl;

	cout << "Player 2 Cards: ";
	for (const string& card : game1.getPlayer2Cards()) {
		cout << card << " ";
	}
	cout << endl;

	cout << "Player 3 Cards: ";
	for (const string& card : game1.getPlayer3Cards()) {
		cout << card << " ";
	}
	cout << endl;

	// 2 - 3) ī�� ���� ���� ���ϱ�
	game1.selectRoutine();
	game1.printSelectRoutine();

	//clearScreen();
	//game1.pickCard();
	
	// 3. �� �� ���� ����
	while (true)
	{
		cout << endl;
		cout << "������� \n";
		cout << game1.getGameRound() << "��° ���Դϴ�" << endl;

		// ����� Ȯ��
		string winner = game1.selectWinner();

		if (!winner.empty())
		{
			cout << winner << endl;
			break;
		}
	}

	return 0;
}
	
	

void clearScreen()
{
	system("cls");
}


