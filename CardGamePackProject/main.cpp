#include <windows.h>
#include <ctime>

#include "CardDeck.h"
#include "User.h"
#include "GameManager.h"
#include "Design.h"
int main()
{
	UserDataManager manager;
	User user;
	
	//ȸ������, �α��� ����
	while (true)
	{
		system("cls");
		cout << "��CARD GAME��\n";
		string option = "0";
		cout << "1. ȸ������ 2. �α��� 3. ���α׷� ���� \n";
		cin >> option;
		if (option == "1")
		{
			manager.signUp();
		}
		else if (option == "2")
		{
			user.login();
			break;
		}

		else if (option == "3")
		{
			cout << "���α׷��� �����մϴ�.\n";
			return 0;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�.\n";
			Sleep(2000);
		}
	}
	
	cout << user.getGamePoint() << endl;

	int botton;
	while (true)
	{
		string option;
		system("cls");
		cout << "������ �����ϼ���." << endl;
		cout << "1. ������� 2. Ȧ�� 3. ���� ����" << endl;
		cin >> option;
		if (option == "1")
		{
			system("cls");
			//�������
			OldMaid game1;
			game1.play(user);

			continue;

		}
		else if (option == "2")
		{
			system("cls");
			//Ȧ��
			cout << "Ȧ���� �����մϴ�." << endl;
			Holdem holdem;

			cout << "ī�带 ���� ����մϴ�." << endl;
			holdem.dealCard();

			cout << "Ȧ���� �����մϴ�." << endl;
			holdem.play(user);
			cout << "������ �����Ϸ��� �ƹ� ��ư�̳� �����ּ���!";
			cin >> botton;
		}

		else if (option == "3")
		{
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(2000);
		}
  }
}