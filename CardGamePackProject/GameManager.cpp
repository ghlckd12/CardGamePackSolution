#include <random>
#include <numeric>

// remove() �Լ� ���
#include <algorithm>

#include "GameManager.h"
#include "Design.h"

#define USERNUM 3

int GameManager::getGamePrice() { return m_gamePrice; }

void GameManager::setGamePrice(int price) { m_gamePrice = price; }


// OldMaid Ŭ���� �Լ� ����
// ������� ������ ī�� ��� ���� ���� 
void OldMaid::dealCard()
{
	CardDeck OldMaidDeck(1);

	OldMaidDeck.suffleCards();

	// ���� ���� �߰� �ؾ��ҵ� 17,18,18
	// 1. �÷��̾�� ī�� �й� : ���õ� ī�� ������ �� �÷��̾ 17��, 18��, 18�� �й�
	int cardsPerPlayer[] = { 17,18,18 };
	m_cardVector = OldMaidDeck.getCardVector();

	// 2. ī�� �й� ��� ���� : �� �÷��̾ ���� ī�带 ������ ���ͳ� �ٸ� ������ ������ ������ ����
	int cardIndex = 0;

	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player1Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}

	for (int card = 0; card < cardsPerPlayer[1]; card++)
	{
		player2Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}

	for (int card = 0; card < cardsPerPlayer[2]; card++)
	{
		player3Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}
}

void OldMaid::removeDuplicates(vector<string>& playerCards)
{
	for (int i = 0; i < playerCards.size(); i++)
	{
		for (int j = i + 1; j < playerCards.size(); j++)
		{
			// ���� �ߺ� �Ǵ� ���
			if (playerCards[i].substr(1) == playerCards[j].substr(1))
			{
				playerCards[i] = "00";
				playerCards[j] = "00";
				break;
			}
		}
	}
	// remove() : ��� �ִ� ��ҵ��� ������ �������� �̵���Ű��, ���ο� �� �ݺ��ڸ� ��ȯ
	playerCards.erase(remove(playerCards.begin(), playerCards.end(), "00"), playerCards.end());

	// ���� �÷��̾��� ī�尡 ��� �ִ��� Ȯ���ϰ�, ��� �ִٸ� m_zeroCnt ����
	//cout << "..............vector size : " << playerCards.size() << "..............." << endl;
	/*if (playerCards.empty())
	{
		m_zeroCnt++;
		cout << "..............m_zeroCnt = " << m_zeroCnt << "..............." << endl;
	}*/

	cout << "ī�� �� �� ��� �� : " << getzeroCnt() << endl;
}

void OldMaid::disCard()
{
	removeDuplicates(player1Cards);
	removeDuplicates(player2Cards);
	removeDuplicates(player3Cards);
}

void OldMaid::selectRoutine()
{
	cout << "����̱�� ������ ���մϴ�!\n";

	// ���� �ð��� �õ�� ����Ͽ� ���������� ����
	srand(time(0));

	// players ���͸� playerOrder ���Ϳ� ����
	playerOrder = players;

	// playerOrder ���͸� �������� ����
	random_shuffle(playerOrder.begin(), playerOrder.end());
}

void OldMaid::printSelectRoutine()
{
	// ��� ���
	cout << "�÷��̾� ����:\n";
	for (int i = 0; i < playerOrder.size(); ++i)
	{
		cout << (i + 1) << "��° : " << playerOrder[i] << "\n";
	};
}

vector<string>& OldMaid::getPlayerCards(string& player)
{
	if (player == "player1")
	{
		return player1Cards;
	}

	if (player == "player2")
	{
		return player2Cards;
	}

	else
	{
		return player3Cards;
	}
}

void OldMaid::showWinner()
{
	cout << endl << "------------showWinner-----------" << endl;
	cout << "Player1 card size : " << this->player1Cards.size() << endl;
	cout << "Player2 card size : " << this->player2Cards.size() << endl;
	cout << "Player3 card size : " << this->player3Cards.size() << endl << endl;

	if (this->player1Cards.size() == 0 ||
		this->player2Cards.size() == 0 ||
		this->player3Cards.size() == 0)
	{
		m_zeroCnt++;
		cout << "-------m_zeroCnt : " << m_zeroCnt << "-----------" << endl;
	}
}

// 1�� ���� ���� ī�带 ���Ƿ� �̱�
void OldMaid::pickCard()
{
	// debug
	cout << "..............pickCard()............" << endl;

	// �÷��̾���� ������� ī�带 �̱� �����մϴ�.
	for (int i = 0; i < playerOrder.size(); i++)
	{
		// ���� ������ �÷��̾�
		string& currentPlayer = playerOrder[i];

		// ���� ������ �÷��̾�
		string& nextPlayer = playerOrder[(i + 1) % playerOrder.size()];

		cout << currentPlayer << "�� �����Դϴ�.\n";

		// ���� ������ �÷��̾� ī�� ����� ������ �����ɴϴ�.
		vector<string>& nextPlayerCards = getPlayerCards(nextPlayer);

		// ���� ������ �÷��̾ �� �̻� ī�带 ������ ���� ���� ���
		if (nextPlayerCards.empty())
		{
			cout << nextPlayer << "�� �� �̻� ī�带 ������ ���� �ʽ��ϴ�.\n";
			continue;
		}

		// ���� ���õ� ī�� ��������
		int cardIndex = rand() % nextPlayerCards.size();
		string pickedCard = nextPlayerCards[cardIndex];

		// ���� ������ �÷��̾� ī�� ����� ������ �����ɴϴ�.
		vector<string>& currentPlayerCards = getPlayerCards(currentPlayer);

		// ���� �÷��̾��� ī�� ��Ͽ� ���õ� ī�带 �߰��մϴ�.
		currentPlayerCards.push_back(pickedCard);

		// ���� �÷��̾��� ī�� ��Ͽ��� ���õ� ī�带 �����մϴ�.
		nextPlayerCards.erase(nextPlayerCards.begin() + cardIndex);
		cout << currentPlayer << "�� " << nextPlayer << "�� ī�带 �̾ҽ��ϴ�: " << pickedCard << "\n";

		// �ߺ��� ī�带 ����
		removeDuplicates(currentPlayerCards);

		cout << "���� �� ��� \n" << "Player 1 Cards: ";
		for (const string& card : getPlayer1Cards()) {
			cout << card << " ";
		}
		cout << endl;

		cout << "Player 2 Cards: ";
		for (const string& card : getPlayer2Cards()) {
			cout << card << " ";
		}
		cout << endl;

		cout << "Player 3 Cards: ";
		for (const string& card : getPlayer3Cards()) {
			cout << card << " ";
		}
		cout << endl;

		// �÷��̾� ī�尡 ����ִ°� �ν� ����
		// ���� �� 1�� ���� �ֱ� = 2���̾��µ� pickCard ���� �ߺ�ī�� ���� ���� �� 
		showWinner();

	}


	// pickCard() �������� ���Ӷ��� ���� ����
	m_gameRound++;
}

string OldMaid::determineWinner() {
	// ����ڸ� ������ ���� �ʱ�ȭ
	string winner = "";

	// �÷��̾���� ī�带 Ȯ���Ͽ� ���� ī�尡 ���� �÷��̾ ã��
	for (string& player : playerOrder)
	{
		vector<string>& playerCards = getPlayerCards(player);

		if (playerCards.empty()) {
			winner = player;
			break; // ���� ī�尡 ���� �÷��̾ ã�����Ƿ� ���� ����
		}
	}

	// ����ڰ� ���� ��� "Game is still ongoing." ��ȯ
	if (winner.empty()) {
		return "Game is still ongoing.";
	}

	// ����ڰ� �ִ� ��� �ش� �÷��̾ ����ڷ� �����Ͽ� ��ȯ
	return winner + " is the Old Maid!";
}

string OldMaid::selectWinner()
{
	// m_zeroCnt�� 2�� �ƴ� ���, pickCard() �Լ� ȣ��
	pickCard();

	// ���� m_zeroCnt�� 2�� ��� (��, ī�尡 ���� �÷��̾ 2�� �̻��� ���)
	if (m_zeroCnt == 2)
	{
		// ���ڸ� �����ϰ� ��ȯ
		return determineWinner();
	}

	// ������ ���� ������� �ʾ����Ƿ� �� ���ڿ� ��ȯ
	return "";
}

int OldMaid::getGameRound()
{
	return m_gameRound;
}

int OldMaid::getzeroCnt()
{
	return m_zeroCnt;
}

// Holdem Ŭ���� �Լ� ����
string Holdem::selectWinner() {
	// Ȧ�� ������ ���� ���� ���� ����
	return "Holdem Winner";
}

void Holdem::dealCard()
{
	// Ȧ�� ������ ī�� ��� ���� ����
	//ī�� �� ����
	CardDeck card(2); //Ȧ�� option == 2

	//ī�� ���� �� ī�� ���� ��������
	card.suffleCards();
	vector<string> cardVector = card.getCardVector();

	////�����ϰ� �ʵ�ī�� 5�� �������� ���� cardVector���� �� ����
	//���� ���� �ʱ�ȭ
	random_device rd;
	mt19937 g(rd());

	//���� �ε���
	vector<int> indices(cardVector.size());
	iota(indices.begin(), indices.end(), 0);

	//�ε��� ������ ����
	shuffle(indices.begin(), indices.end(), g);

	//������ 5���� �ε��� ���� ����
	vector<int> selected_indices(indices.begin(), indices.begin() + 5);

	//�ʵ忡 ���� 5�� ī�� ���� ����
	vector<string> fieldCard;
	for (int index : selected_indices) {
		fieldCard.push_back(cardVector[index]);
	}

	//���� 5���� ī�带 ������ cardVector���� ����
	sort(selected_indices.rbegin(), selected_indices.rend());
	for (int index : selected_indices) {
		cardVector.erase(cardVector.begin() + index);
	}

	////������ cardVector���� �����ϰ� 2�徿 ������ usersCard�� �ֱ�
	vector<vector <string>> usersCard(USERNUM);

	for (int i = 0; i < USERNUM; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			usersCard[i].push_back(cardVector.back());
			cardVector.pop_back();
		}
	}

	m_fieldCard = fieldCard;
	m_totalUserCard = usersCard;
}

void Holdem::play()
{
	// ���� ���� ī�� �ޱ�
	// 0��°�� : 0/5 ����
	// ����(����)
	// 1��°�� : 3/5 ����
	// ����(�۽�Ʈ)
	// 2��°�� : 4/5 ����
	// ����(������)
	// 3��°�� : 5/5 ����
	// ����(��Ʈ)
}

