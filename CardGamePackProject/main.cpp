#include "GameManager.h"
#include "Card.h"

// ȭ�� �ʱ�ȭ �Լ�
//void clearScreen();
using std::cout;
using std::endl;

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
	clearScreen();  
	
	// 2. ���� ���� â
	cout << "������� \n";
	cout << "���� ���� ! \n\n";
	
	// 2 - 1) ī�� �й�
	cout << "(1) ī�带 �й��մϴ�.\n";
	game1.dealCard();

	// if JK ���� ����
	// cout << "��Ŀ�Դϴ�! �������� �������ּ���\n"
	// else ���� ī�忡 ��Ŀ�� �����ϴ� ;
	
	// 2 - 2) �ߺ� ī�带 ������
	cout << "(2) �ߺ��� ����ī�带 �����ϴ�.\n";
	cout << "ī�带 �����ּ���.\n";
	game1.disCard();

	// 2 - 3) ī�� ���� ���� ���ϱ�
	game1.selectRoutine();
	game1.printSelectRoutine();
	clearScreen();

	// 3. �� �� ���� ����
	while (true)
	{
		cout << "������� \n";
		cout << game1.getGameRound() << "��° ���Դϴ�" << endl;

		




	}

	



	



	return 0;

}


void clearScreen()
{
	system("cls");
}



/*
* 
	while (true)
	{
		// ����� Ȯ��
		string winner = game1.selectWinner();

		if (!winner.empty())
		{
			cout << winner << endl;
			break;
		}
	}*/