#include "User.h"

void User::showUserInfo()
{


}

string User::getID()
{


}

string User::getPassword()
{


}

string User::getNickname()
{

}

int User::getGamePoint()
{

}

void User::setID()
{

}

void User::setPassword()
{

}

void User::setNickname()
{

}

void User::setGamePoint()
{

}
 
void UserDataManager::writeUser(vector<string> userInfo) //ȸ������ ����
{

}

void UserDataManager::openUser()
{

}

void UserDataManager::signUp() //ȸ������
{
	vector<string> user;
	string ID, password, checkingpassword, nickname;
	ifstream read_file("User.txt");

	cout << "---------------------ȸ������---------------------\n";

	if (read_file.is_open() == false)
	{
		//���� ������ ���� �� ��ϳ�
	}

	while (true)
	{
		cout << "���̵�			: \n";
		cin >> ID;
		cout << "��й�ȣ			: \n";
		cin >> password;
		cout << "��й�ȣ Ȯ��	: \n";
		cin >> checkingpassword;
		cout << "�г���			: \n";
		cin >> nickname;
		
		if (password != checkingpassword)
		{
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
		}
		else {
			break;
		}
	}
	
	user.push_back(ID);
	user.push_back(password);
	user.push_back(nickname);
	user.push_back("1000000"); // ȸ�����Խ� �⺻ ���� ����Ʈ
	writeUser(user);

	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�. \n";
	read_file.close();
}


vector<string> UserDataManager::login() //�α���
{
	vector<string> user;
	ifstream read_file("User.txt");

	if (read_file.is_open() == false)
	{
		//���� ������ ���� �� ��ϳ�
	}
	
	while (true)
	{
		cout << "���̵�			: \n";
		cout << "��й�ȣ			: \n";
	}

}

