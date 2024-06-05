#include <random>
#include <numeric>

#include "GameManager.h"
#include "Card.h"

#define USERNUM 3

int GameManager::getGamePrice() { return m_gamePrice; }

void GameManager::setGamePrice(int price) { m_gamePrice = price; }

// Holdem Ŭ���� �Լ� ����
string Holdem::selectWinner() {
    // Ȧ�� ������ ���� ���� ���� ����
    return "Holdem Winner";
}

void Holdem::dealCard()
{
    // Ȧ�� ������ ī�� ��� ���� ����
    //ī�� �� ����
    Card card(2); //Ȧ�� option == 2

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
}

// OldMaid Ŭ���� �Լ� ����
string OldMaid::selectWinner() {
    // ������� ������ ���� ���� ���� ����
    return "OldMaid Winner";
}

void OldMaid::dealCard() {
    // ������� ������ ī�� ��� ���� ����
}