#include <ctime>

#include "Card.h"

void Card::suffleCards()
{
	// ���� �õ� �ʱ�ȭ
	std::srand(std::time(0));

	// �Ǽ�-������ ���� �˰���
	for (size_t i = m_cardVector.size() - 1; i > 0; --i) {
		size_t j = std::rand() % (i + 1);
		std::swap(m_cardVector[i], m_cardVector[j]);
	}
}

void Card::showMyCard()
{
	for (string card : m_cardVector)
	{
		cout << card << " ";
	}
	cout << endl;
}

vector <string> Card::makeDeck(int type)
{
	// "sA", "s2", "s3", "s4", ... , "sQ", "sK"
	// ī���� ����
	vector<string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	// ī���� ��Ʈ
	vector<string> suits = { "s", "d", "h", "c" }; // �����̵�, ���̾�, ��Ʈ, Ŭ�ι�

	switch (type)
	{
	case 1: // �������
	{
		// ī�� �� ����
		for (const auto& suit : suits) {
			for (const auto& rank : ranks) {
				m_cardVector.push_back(suit + rank);
			}
		}
		m_cardVector.push_back("JK");
		break;
	}

	case 2: //Ȧ��
	{
		// ī�� �� ����
		for (const auto& suit : suits) {
			for (const auto& rank : ranks) {
				m_cardVector.push_back(suit + rank);
			}
		}
		break;
	}
	default:
		break;
	}
}