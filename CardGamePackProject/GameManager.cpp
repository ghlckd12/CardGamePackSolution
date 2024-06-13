#include <random>
#include <numeric>
#include <map>
#include <set>
#include <sstream>

#include "GameManager.h"
#include "Design.h"

#define USERNUM 3

struct Card {
    char suit;  // 's', 'd', 'h', 'c'
    int value;  // 2-10, 11 (J), 12 (Q), 13 (K), 14 (A)

    Card(char s, int v) : suit(s), value(v) {}
};
std::map<char, int> value_map = {
    {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'1', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
};

std::vector<Card> parseCards(const std::vector<std::string>& card_strs) {
    std::vector<Card> cards;
    for (const auto& card_str : card_strs) {
        char suit = card_str[0];  // suit�� card_str[1]�� ����
        int value = value_map[card_str[1]];  // value�� card_str[0]�� ����
        cards.emplace_back(suit, value);
    }
    return cards;
}

// ���ĵ� unique_values ���Ͱ� ��Ʈ����Ʈ���� Ȯ���ϴ� �Լ�
bool isStraight(const std::vector<int>& unique_values, std::vector<int>& straight_cards) {
    straight_cards.clear(); // ��Ʈ����Ʈ ī�带 �����ϱ� ���� �ʱ�ȭ

    // unique_values�� ������������ ����
    std::vector<int> sorted_values = unique_values;
    std::sort(sorted_values.begin(), sorted_values.end());

    int consecutive_count = 1; // ���ӵ� ī���� ������ ���� ����
    for (size_t i = 1; i < sorted_values.size(); ++i) {
        // ���� ���� ���� ���� 1 ���̰� ���� ���ӵ� ���̹Ƿ� consecutive_count ����
        if (sorted_values[i] - sorted_values[i - 1] == 1) {
            consecutive_count++;
        }
        else {
            consecutive_count = 1; // ������ �������Ƿ� �ٽ� 1�� �ʱ�ȭ
        }

        // ���ӵ� ī�尡 5���� �Ǹ� ��Ʈ����Ʈ�̹Ƿ� �ش� ������ straight_cards�� ����
        if (consecutive_count == 5) {
            for (int j = i - 4; j <= i; ++j) {
                straight_cards.push_back(sorted_values[j]);
            }
            return true; // ��Ʈ����Ʈ�� Ȯ�εǾ����Ƿ� true ��ȯ
        }
    }

    return false; // ��Ʈ����Ʈ�� �����Ƿ� false ��ȯ
}

bool compareByValue(const Card& a, const Card& b) {
    return a.value > b.value;
}

pair<string, vector<Card>> determineHand(const std::vector<Card>& all_cards) {
    // Sort cards by value
    std::vector<Card> cards = all_cards;
    std::sort(cards.begin(), cards.end(), [](const Card& a, const Card& b) {
        return a.value < b.value;
        });

    // Helper structures
    std::map<int, int> value_count;
    std::map<char, int> suit_count;
    std::map<char, std::vector<int>> suit_values;

    for (const auto& card : cards) {
        value_count[card.value]++;
        suit_count[card.suit]++;
        suit_values[card.suit].push_back(card.value);
    }

    // Check for straight flush and royal flush
    for (const auto& suit_values_pair : suit_values) {
        char suit = suit_values_pair.first;
        const std::vector<int>& values = suit_values_pair.second;
        if (values.size() >= 5) {
            std::vector<int> sorted_values = values;
            std::sort(sorted_values.begin(), sorted_values.end());
            std::vector<int> straight_cards;
            if (isStraight(sorted_values, straight_cards)) {
                std::vector<Card> straight_flush_cards;
                for (const auto& card : cards) {
                    if (std::find(straight_cards.begin(), straight_cards.end(), card.value) != straight_cards.end() && card.suit == suit) {
                        straight_flush_cards.push_back(card);
                    }
                }
                if (straight_cards.back() == 14 && straight_cards[straight_cards.size() - 5] == 10) {
                    return { "Royal Flush", straight_flush_cards };
                }
                return { "Straight Flush", straight_flush_cards };
            }
        }
    }
    
    // Check for four of a kind
    for (const auto& value_count_pair : value_count) {
        int value = value_count_pair.first;
        int count = value_count_pair.second;
        if (count == 4) {
            std::vector<Card> four_of_a_kind_cards;
            for (const auto& card : cards) {
                if (card.value == value) {
                    four_of_a_kind_cards.push_back(card);
                }
            }
            return { "Four of a Kind", four_of_a_kind_cards };
        }
    }
    
    // Check for full house
    int three_value = 0, pair_value = 0;
    for (const auto& value_count_pair : value_count) {
        int value = value_count_pair.first;
        int count = value_count_pair.second;
        if (count == 3) {
            three_value = value;
        }
        else if (count == 2 && value > pair_value) {
            pair_value = value;
        }
    }
    if (three_value && pair_value) {
        std::vector<Card> full_house_cards;
        for (const auto& card : cards) {
            if (card.value == three_value || card.value == pair_value) {
                full_house_cards.push_back(card);
            }
        }
        return { "Full House", full_house_cards };
    }
    
    // Check for flush
    for (const auto& suit_count_pair : suit_count) {
        char suit = suit_count_pair.first;
        int count = suit_count_pair.second;
        if (count >= 5) {
            std::vector<Card> flush_cards;
            for (const auto& card : cards) {
                if (card.suit == suit) {
                    flush_cards.push_back(card);
                }
            }
            return { "Flush", std::vector<Card>(flush_cards.begin(), flush_cards.begin() + 5) };
        }
    }
    
    // Check for straight
    std::vector<int> unique_values;
    for (const auto& card : cards) {
        if (unique_values.empty() || unique_values.back() != card.value) {
            unique_values.push_back(card.value);
        }
    }
    std::vector<int> straight_cards;
    if (isStraight(unique_values, straight_cards)) {
        std::vector<Card> straight_hand_cards;
        for (const auto& card : cards) {
            if (std::find(straight_cards.begin(), straight_cards.end(), card.value) != straight_cards.end()) {
                straight_hand_cards.push_back(card);
            }
        }
        return { "Straight", straight_hand_cards };
    }
    
    // Check for three of a kind
    for (const auto& value_count_pair : value_count) {
        int value = value_count_pair.first;
        int count = value_count_pair.second;
        if (count == 3) {
            std::vector<Card> three_of_a_kind_cards;
            for (const auto& card : cards) {
                if (card.value == value) {
                    three_of_a_kind_cards.push_back(card);
                }
            }
            return { "Three of a Kind", three_of_a_kind_cards };
        }
    }

    // Check for two pair and one pair
    std::vector<int> pairs;
    for (const auto& value_count_pair : value_count) {
        int value = value_count_pair.first;
        int count = value_count_pair.second;
        if (count == 2) {
            pairs.push_back(value);
        }
    }

    if (pairs.size() >= 2) {
        std::vector<Card> two_pair_cards;
        for (const auto& card : cards) {
            if (card.value == pairs[0] || card.value == pairs[1]) {
                two_pair_cards.push_back(card);
            }
        }
        return { "Two Pair", two_pair_cards };
    }

    if (pairs.size() == 1) {
        std::vector<Card> one_pair_cards;
        for (const auto& card : cards) {
            if (card.value == pairs[0]) {
                one_pair_cards.push_back(card);
            }
        }
        return { "One Pair", one_pair_cards };
    }

    // High Card
    vector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), compareByValue);
    vector <Card> highestCard = { sortedCards[0] };
    return { "High Card",  highestCard };
}

std::string handToString(const std::pair<std::string, std::vector<Card>>& hand) {
    std::stringstream ss;
    ss << hand.first << ": ";
    for (const auto& card : hand.second) {
        std::string value_str;
        switch (card.value) {
        case 11: value_str = "J"; break;
        case 12: value_str = "Q"; break;
        case 13: value_str = "K"; break;
        case 14: value_str = "A"; break;
        default: value_str = std::to_string(card.value); break;
        }
        ss << card.suit << value_str << " ";
    }
    return ss.str();
}

int Holdem::checkFinalWinner()
{
    std::map<string, int> rankResult = { { "High Card", 1 }, {"One Pair", 2}, {"Two Pair", 3},
    {"Three of a Kind", 4}, {"Straight", 5}, {"Flush", 6}, {"Full House", 7}, {"Four of a Kind", 8}, {"Straight Flush", 9}, {"Royal Flush", 10} };

    // �ջ� ����� ����� ����
    for (string userResult : m_totalResult)
    {
        std::vector<std::string> tokens1;
        std::string token1;
        std::istringstream tokenStream1(userResult);
        while (std::getline(tokenStream1, token1, ':')) {
            tokens1.push_back(token1);
        }
        m_userRankResultVector.push_back(tokens1[0]);

        // ����������� ��ũ ����� ī�� ���� ����� ex) { "cA", "dA", "c8", "d8", "s8" }
        std::vector<std::string> tokens2;
        std::string token2;
        std::istringstream tokenStream2(tokens1[1]); 

        while (std::getline(tokenStream2, token2, ' ')) {
            if (!token2.empty()) {  // �� ���ڿ��� �ƴ� ��쿡�� �߰�
                tokens2.push_back(token2);
            }
        }
        m_userRankResultCardVector.push_back(tokens2);
    }

    // tokens1[0] �� ���� ��ũ�� ��������? ex) �����, �����, Ʈ����
    // tokens1[1] �� �ش� ��ũ�� ī�� ������ ��������? ex) "s9 d9", "d10 s10 d8 c8", "d10 s10 c10"

    vector <int> userRankVector;
    for (int i = 0; i < USERNUM; i++)
    {
        userRankVector.push_back(rankResult[m_userRankResultVector[i]]);
    }

    int userRankMax = 0;
    int userMaxIdx = 0;
    for (int i = 0; i < USERNUM; i++)
    {
        if (userRankVector[i] > userRankMax)
        {
            userRankMax = userRankVector[i];
            userMaxIdx = i;
        }
    }

    return userMaxIdx;
}

int GameManager::getGamePrice() { return m_gamePrice; }

void GameManager::setGamePrice(int price) { m_gamePrice = price; }

// Holdem Ŭ���� �Լ� ����
string Holdem::selectWinner() {
    // Ȧ�� ������ ���� ���� ���� ����
    for (int i = 0; i < USERNUM; i++)
    {
        for (string fieldCard : m_fieldCard)
        {
            m_totalUserCard[i].push_back(fieldCard);
        }
    }
    
    for (int j = 0; j < USERNUM; j++)
    {
        //vector <string> testV = { "s2", "dA", "d10", "d9", "d6", "dK", "c2" };
        //vector<Card> cards = parseCards(testV);
        vector<Card> cards = parseCards(m_totalUserCard[j]);
        pair<string, vector<Card>> result = determineHand(cards);
        string strResult = handToString(result);
        m_totalResult.push_back(strResult);
    }
    
    int winnerIdx = checkFinalWinner();

    // user �ν��Ͻ� ������� �г��� ��������
    // �г��� ������ string ������ ����� idx �����ϱ�
    
    cout << std::to_string(winnerIdx) + "��° �÷��̾� ���" << endl;
    return "0";
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

void Holdem::betting(int turnNum)
{
	int bettingOption;
	cout << endl << "���� ����" << endl;
	cout << "0 : Call | 1 : Raise | 2 : Fold -> ";
	cin >> bettingOption;
}

void Holdem::play()
{
	int turnNum = 0;
	HoldemDesign holdemDesign;
    // ���� ���� ī�� �ޱ�
	holdemDesign.printMyCard(m_totalUserCard[0]);
	while (true)
	{
		// n��°�� : 0/5 -> 3/5 -> 4/5 -> 5/5
		holdemDesign.printCommunityCard(m_fieldCard, turnNum);
		// ���� : ����, �۽�Ʈ, ������, ��Ʈ
		betting(turnNum);

        // Fold ���� ���� ������ winner�� �����ֱ�
		if (turnNum == 3)
		{
            selectWinner();
			break;
		}

		turnNum++;
	}
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
	}
}
vector<string>& OldMaid::getPlayerCards(string& player)
{
	if (player == "��")
	{
		return player1Cards;
	}
	if (player == "user1")
	{
		return player2Cards;
	}
	else
	{
		return player3Cards;
	}
}
// 1�� ���� ���� ī�带 ���Ƿ� �̱�
void OldMaid::pickCard()
{
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
		// pickCard() �������� ���Ӷ��� ���� ����
		m_gameRound++;
	}
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
	// ���� m_zeroCnt�� 2�� ��� (��, ī�尡 ���� �÷��̾ 2�� �̻��� ���)
	if (m_zeroCnt == 2)
	{
		// ���ڸ� �����ϰ� ��ȯ
		return determineWinner();
	}
	// m_zeroCnt�� 2�� �ƴ� ���, pickCard() �Լ� ȣ��
	pickCard();
	// ������ ���� ������� �ʾ����Ƿ� �� ���ڿ� ��ȯ
	return "";
}
int OldMaid::getGameRound()
{
	return m_gameRound;
}