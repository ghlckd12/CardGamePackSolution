
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
		}else
		{
			cout << "�߸��� �Է��Դϴ�.\n";
		}
	}





}