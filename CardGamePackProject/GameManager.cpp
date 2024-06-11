#include <random>
#include <numeric>

#include "GameManager.h"
#include "Design.h"

#define USERNUM 3

int GameManager::getGamePrice() { return m_gamePrice; }

void GameManager::setGamePrice(int price) { m_gamePrice = price; }

<<<<<<< HEAD

// OldMaid Ŭ���� �Լ� ����

// ������� ������ ī�� ��� ���� ���� 
void OldMaid::dealCard()
{
	CardDeck card(1);
	
	card.suffleCards();

	// ���� ���� �߰� �ؾ��ҵ� 14,14,15
	// 1. �÷��̾�� ī�� �й� : ���õ� ī�� ������ �� �÷��̾ 14��, 14��, 15�� �й�
	const int cardsPerPlayer[] = { 14,14,15 };

	// 3. ī�� �й� ��� ���� : �� �÷��̾ ���� ī�带 ������ ���ͳ� �ٸ� ������ ������ ������ ����
	int cardIndex = 0;

	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player1Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}

	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player2Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}

	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player3Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}
}

void OldMaid::removeDuplicates(std::vector<std::string>& playerCards)
{
	// �ߺ��� ��Ҹ� ã�� �����ϴ� ����
	for (int i = 0; i < playerCards.size(); i++)
	{
		for (int j = i + 1; j < playerCards.size();)
		{
			// ���� ��ҿ� ���� ��Ҹ� ���Ͽ� �ߺ� ���� Ȯ��
			if (playerCards[i] == playerCards[j])
			{
				// �ߺ��� ��� ���� ��Ҹ� ���� ����� ��ġ�� �����
				playerCards.erase(playerCards.begin() + j);
			}
			else
			{
				// �ߺ����� ���� ��� ���� ��ҷ� �̵�
				j++;
			}
		}
	}

	// ���� �÷��̾��� ī�尡 ��� �ִ��� Ȯ���ϰ�, ��� �ִٸ� m_zeroCnt ����
	if (playerCards.empty())
	{
		m_zeroCnt++;
	}

}

=======
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

// OldMaid Ŭ���� �Լ� ����
// ������� ������ ī�� ��� ���� ����
void OldMaid::dealCard()
{
	CardDeck card(1);

	card.suffleCards();
	// ���� ���� �߰� �ؾ��ҵ� 14,14,15
	// 1. �÷��̾�� ī�� �й� : ���õ� ī�� ������ �� �÷��̾ 14��, 14��, 15�� �й�
	const int cardsPerPlayer[] = { 14,14,15 };
	// 2. ī�� �й� ��� ���� : �� �÷��̾ ���� ī�带 ������ ���ͳ� �ٸ� ������ ������ ������ ����
	int cardIndex = 0;
	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player1Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}
	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player2Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}
	for (int card = 0; card < cardsPerPlayer[0]; card++)
	{
		player3Cards.push_back(m_cardVector[cardIndex]);
		cardIndex++;
	}
}
void OldMaid::removeDuplicates(std::vector<std::string>& playerCards)
{
	// �ߺ��� ��Ҹ� ã�� �����ϴ� ����
	for (int i = 0; i < playerCards.size(); i++)
	{
		for (int j = i + 1; j < playerCards.size();)
		{
			// ���� ��ҿ� ���� ��Ҹ� ���Ͽ� �ߺ� ���� Ȯ��
			if (playerCards[i] == playerCards[j])
			{
				// �ߺ��� ��� ���� ��Ҹ� ���� ����� ��ġ�� �����
				playerCards.erase(playerCards.begin() + j);
			}
			else
			{
				// �ߺ����� ���� ��� ���� ��ҷ� �̵�
				j++;
			}
		}
	}
	// ���� �÷��̾��� ī�尡 ��� �ִ��� Ȯ���ϰ�, ��� �ִٸ� m_zeroCnt ����
	if (playerCards.empty())
	{
		m_zeroCnt++;
	}
}
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
void OldMaid::disCard()
{
	removeDuplicates(player1Cards);
	removeDuplicates(player2Cards);
	removeDuplicates(player3Cards);
}
<<<<<<< HEAD

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

=======
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
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
void OldMaid::printSelectRoutine()
{
	// ��� ���
	cout << "�÷��̾� ����:\n";
<<<<<<< HEAD

=======
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	for (int i = 0; i < playerOrder.size(); ++i)
	{
		cout << (i + 1) << "��° : " << playerOrder[i] << "\n";
	}
<<<<<<< HEAD

}

=======
}
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
vector<string>& OldMaid::getPlayerCards(string& player)
{
	if (player == "��")
	{
		return player1Cards;
	}
<<<<<<< HEAD

=======
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	if (player == "user1")
	{
		return player2Cards;
	}
<<<<<<< HEAD

=======
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	else
	{
		return player3Cards;
	}
}
<<<<<<< HEAD

// 1�� ���� ���� ī�带 ���Ƿ� �̱�
void OldMaid::pickCard()
{

=======
// 1�� ���� ���� ī�带 ���Ƿ� �̱�
void OldMaid::pickCard()
{
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	// �÷��̾���� ������� ī�带 �̱� �����մϴ�.
	for (int i = 0; i < playerOrder.size(); i++)
	{
		// ���� ������ �÷��̾�
		string& currentPlayer = playerOrder[i];
<<<<<<< HEAD

		// ���� ������ �÷��̾�
		string& nextPlayer = playerOrder[(i + 1) % playerOrder.size()];

		cout << currentPlayer << "�� �����Դϴ�.\n";

		// ���� ������ �÷��̾� ī�� ����� ������ �����ɴϴ�.
		vector<string>& nextPlayerCards = getPlayerCards(nextPlayer);

=======
		// ���� ������ �÷��̾�
		string& nextPlayer = playerOrder[(i + 1) % playerOrder.size()];
		cout << currentPlayer << "�� �����Դϴ�.\n";
		// ���� ������ �÷��̾� ī�� ����� ������ �����ɴϴ�.
		vector<string>& nextPlayerCards = getPlayerCards(nextPlayer);
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
		// ���� ������ �÷��̾ �� �̻� ī�带 ������ ���� ���� ���
		if (nextPlayerCards.empty())
		{
			cout << nextPlayer << "�� �� �̻� ī�带 ������ ���� �ʽ��ϴ�.\n";
			continue;
		}
<<<<<<< HEAD

		// ���� ���õ� ī�� ��������
		int cardIndex = rand() % nextPlayerCards.size();
		string pickedCard = nextPlayerCards[cardIndex];

=======
		// ���� ���õ� ī�� ��������
		int cardIndex = rand() % nextPlayerCards.size();
		string pickedCard = nextPlayerCards[cardIndex];
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
		// ���� ������ �÷��̾� ī�� ����� ������ �����ɴϴ�.
		vector<string>& currentPlayerCards = getPlayerCards(currentPlayer);
		// ���� �÷��̾��� ī�� ��Ͽ� ���õ� ī�带 �߰��մϴ�.
		currentPlayerCards.push_back(pickedCard);
		// ���� �÷��̾��� ī�� ��Ͽ��� ���õ� ī�带 �����մϴ�.
		nextPlayerCards.erase(nextPlayerCards.begin() + cardIndex);
<<<<<<< HEAD

		cout << currentPlayer << "�� " << nextPlayer << "�� ī�带 �̾ҽ��ϴ�: " << pickedCard << "\n";

=======
		cout << currentPlayer << "�� " << nextPlayer << "�� ī�带 �̾ҽ��ϴ�: " << pickedCard << "\n";
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
		// �ߺ��� ī�带 ����
		removeDuplicates(currentPlayerCards);
		// pickCard() �������� ���Ӷ��� ���� ����
		m_gameRound++;
	}
<<<<<<< HEAD

}

string OldMaid::determineWinner() {
	// ����ڸ� ������ ���� �ʱ�ȭ
	string winner = "";

=======
}
string OldMaid::determineWinner() {
	// ����ڸ� ������ ���� �ʱ�ȭ
	string winner = "";
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	// �÷��̾���� ī�带 Ȯ���Ͽ� ���� ī�尡 ���� �÷��̾ ã��
	for (string& player : playerOrder)
	{
		vector<string>& playerCards = getPlayerCards(player);
<<<<<<< HEAD

=======
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
		if (playerCards.empty()) {
			winner = player;
			break; // ���� ī�尡 ���� �÷��̾ ã�����Ƿ� ���� ����
		}
	}
<<<<<<< HEAD

=======
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
	// ����ڰ� ���� ��� "Game is still ongoing." ��ȯ
	if (winner.empty()) {
		return "Game is still ongoing.";
	}
<<<<<<< HEAD

	// ����ڰ� �ִ� ��� �ش� �÷��̾ ����ڷ� �����Ͽ� ��ȯ
	return winner + " is the Old Maid!";
}

=======
	// ����ڰ� �ִ� ��� �ش� �÷��̾ ����ڷ� �����Ͽ� ��ȯ
	return winner + " is the Old Maid!";
}
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
string OldMaid::selectWinner()
{
	// ���� m_zeroCnt�� 2�� ��� (��, ī�尡 ���� �÷��̾ 2�� �̻��� ���)
	if (m_zeroCnt == 2)
	{
		// ���ڸ� �����ϰ� ��ȯ
		return determineWinner();
	}
	// m_zeroCnt�� 2�� �ƴ� ���, pickCard() �Լ� ȣ��
	pickCard();
<<<<<<< HEAD

	// ������ ���� ������� �ʾ����Ƿ� �� ���ڿ� ��ȯ
	return "";
}

=======
	// ������ ���� ������� �ʾ����Ƿ� �� ���ڿ� ��ȯ
	return "";
}
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
int OldMaid::getGameRound()
{
	return m_gameRound;
}