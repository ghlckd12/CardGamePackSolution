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
 
void UserDataManager::writeUser(vector<string> userInfo) 
//ȸ������ ����
//userInfo = {ID, password, nickname, point}
{
	fstream file("User.txt", ios::in | ios::out);
	if (!file.is_open()) {

	}
	vector<vector<string>> data;
	string line;

	//���� �о����
	while (getline(file, line)) {
		istringstream iss(line);
		string word;
		vector<std::string> row;

		// �ٿ��� �ܾ �и��Ͽ� ���Ϳ� ����
		while (iss >> word) {
			row.push_back(word);
		}

		// �� ���� �����͸� ���� ���Ϳ� �߰�
		data.push_back(row);
	}

	int userNum = data.size();
	int option = 1; // 1: ȸ������ 2: ����ȸ��
	string targetID; // �����ϴ� user�� ID

	//���� ȸ������ �ƴ��� Ȯ��
	//���̵� �񱳸� ���� Ȯ��
	//���� ȸ���̶�� ȸ���� ID ���� & ����� ȸ�� ����(point)�� ����
	for (int i = 0; i < userNum; i++)
	{
		if (data[userNum][0] == userInfo[0])
		{
			option = 2;
			targetID = data[userNum][0];
			data[userNum][3] = userInfo[3];
		}
	}

	//option 1 : txt���� ������ �ٿ� ȸ������ �߰�
	//option 2 : txt���Ͽ� ���� ȸ�� ���� ����
	if (option == 1)
	{
		file.clear();
		file.seekp(0, ios::end);
		for (int i = 0; i < 4; i++)
		{
			file << userInfo[i] << " " ; // ȸ������ �߰�
		}
	}
	else if (option == 2)
	{
		file.clear();
		for (int i = 0; i < userNum; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				file << data[i][j] << " ";
			}
			file << "\n";
		}
	}

	file.close();
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

