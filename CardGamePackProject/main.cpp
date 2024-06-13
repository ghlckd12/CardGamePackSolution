
#include <ctime>

#include "CardDeck.h"
#include "User.h"
#include "GameManager.h"
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
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�.\n";
		}
	}
	
	cout << user.getGamePoint() << endl;

	while (true)
	{
		string option;
		cout << "������ �����ϼ���." << endl;
		cin >> option;
		if (option == "1")
		{
			system("cls");
			//�������
			cout << "������⸦ �����մϴ�." << endl;
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
			holdem.play();
		}

		else if (option == "3")
		{
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
  }
}