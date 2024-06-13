#include "User.h"

void UserDataManager::writeUser(vector<string> userInfo)
//ȸ������ ����
//userInfo = {ID, password, nickname, point}
{
	vector<vector<string>> data = openUser();

	int userNum = data.size();
	int option = 1; // 1: ȸ������ 2: ����ȸ��
	string targetID; // �����ϴ� user�� ID

	//���� ȸ������ �ƴ��� Ȯ��
	//���̵� �񱳸� ���� Ȯ��
	//���� ȸ���̶�� ȸ���� ID ���� & ����� ȸ�� ����(point)�� ����
	for (int i = 0; i < userNum; i++)
	{
		if (data[i][0] == userInfo[0])
		{
			option = 2;
			targetID = data[i][0];
			data[i][3] = userInfo[3];
		}
	}

	//ȸ�������� ��� data�� ���ο� ȸ�� �߰�
	if (option == 1)
	{
		data.push_back(userInfo);
		userNum++;
	}

	//���� ���� ����

	ofstream file("User.txt");

	//���Ͽ� ȸ�� ���� ����
	for (int i = 0; i < userNum; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			file << data[i][j] << " ";
		}
		file << "\n";
	}

	file.close();
}

vector<vector<string>> UserDataManager::openUser()
{
	//������ ���ȴ��� Ȯ��
	ifstream file("User.txt");
	if (!file.is_open()) {

	}

	//ȸ���� ������ ������ ����
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

	file.close();

	return data;
}

void UserDataManager::signUp() //ȸ������
{
	vector<vector<string>> userdata = openUser();
	vector<string> user;
	int userNum = userdata.size();
	string ID, password, checkingpassword, nickname;
	bool signUpOK;

	system("cls");
	cout << "---------------------ȸ������---------------------\n";

	while (true)
	{
		cout << "���̵� : ";
		cin >> ID;

		// ������ ���̵� �����ϴ� ���
		bool ExistingUser = false;
		for (int i = 0; i < userNum; i++)
		{
			if (userdata[i][0] == ID) {
				ExistingUser = true;
			}
		}
		if (ExistingUser)
		{
			continue;
		}

		// �ű� ������ ���
		cout << "�г��� : ";
		cin >> nickname;
		cout << "��й�ȣ : ";
		password = inputPassword();

		// ��й�ȣ Ȯ��
		while (true)
		{
			cout << "��й�ȣ Ȯ�� : ";
			checkingpassword = inputPassword();
			if (password != checkingpassword)
			{
				cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
				continue;
			}
			else
			{
				signUpOK = true;
				break;
			}
		}
		if (signUpOK)
		{
			break;
		}
	}

	user.push_back(ID);
	user.push_back(password);
	user.push_back(nickname);
	user.push_back("1000000"); // ȸ�����Խ� �⺻ ���� ����Ʈ
	writeUser(user);

	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�. \n";
	//read_file.close();
}

string UserDataManager::inputPassword()
{
	const char BACKSPACE = 8;
	const char RETURN = 13;

	string password;
	char ch;

	// ��й�ȣ �Է� �ޱ�
	while (true) {
		ch = _getch();

		if (ch == RETURN) {
			std::cout << std::endl;
			break;
		}
		else if (ch == BACKSPACE) {
			if (!password.empty()) {
				std::cout << "\b \b"; // �齺���̽� ó��
				password.pop_back();
			}
		}
		else {
			std::cout << '*'; // '*'�� ��ü
			password.push_back(ch);
		}
	}

	return password;

}

void User::login() //�α��� return : Nickname, point
{
	vector<vector<string>> data = openUser();
	bool isUser = false;
	int userNum = data.size();
	int userIndex = -1; // �α����ϴ� user�� index
	string ID, password;

	system("cls");
	cout << "---------------------�α���---------------------\n";

	//ID�� �����ϴ� �� Ȯ��
	while (isUser == false)
	{
		cout << "���̵� : ";
		cin >> ID;
		// data�� ���Ǹ� id�� �����ϴ��� Ȯ��
		for (int i = 0; i < userNum; i++)
		{
			if (ID == data[i][0])
			{
				isUser = true;
				userIndex = i;
				break;
			}
		}

		if (isUser == false)
		{
			cout << "�������� �ʴ� ���̵��Դϴ�. \n";
			cout << "�ٽ� �Է����ּ���. \n";
		}
	}

	//��й�ȣ Ȯ��
	while (true)
	{
		cout << "��й�ȣ : ";
		password = inputPassword();

		if (password == data[userIndex][1])
		{
			cout << "�α��ο� �����߽��ϴ�. \n";
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ��� : \n";
		}
	}

	//User�� ���� ����
	setID(data[userIndex][0]);
	setPassword(data[userIndex][1]);
	setNickname(data[userIndex][2]);
	setGamePoint(data[userIndex][3]);
}

string User::getID()
{
	return this->m_ID;
}

string User::getPassword()
{
	return this->m_password;
}

string User::getNickname()
{
	return this->m_nickname;
}

string User::getGamePoint()
{
	return this->m_gamePoint;
}

void User::setID(string ID)
{
	this->m_ID = ID;
}

void User::setPassword(string PW)
{
	this->m_password = PW;
}

void User::setNickname(string Nickname)
{
	this->m_nickname = Nickname;
}

void User::setGamePoint(string gainedPoint)
{
	this->m_gamePoint = to_string(stoi(m_gamePoint) + stoi(gainedPoint));
}

