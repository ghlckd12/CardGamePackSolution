#include "GameManager.h"

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

}

void Holdem::shuffleCard() {
    // Ȧ�� ������ ī�� ���� ���� ����
}

// OldMaid Ŭ���� �Լ� ����
string OldMaid::selectWinner() {
    // ������� ������ ���� ���� ���� ����
    return "OldMaid Winner";
}

void OldMaid::dealCard() {
    // ������� ������ ī�� ��� ���� ����
}

void OldMaid::shuffleCard() {
    // ������� ������ ī�� ���� ���� ����
}