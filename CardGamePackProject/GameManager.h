#pragma once

// time �Լ� ���
#include <iostream>
#include <ctime>
#include <cstdlib>
// random_suffle �Լ� ���
#include <algorithm>
#include <vector>
#include <string>
#include "Card.h"

//#include "Card.h"

using namespace std;

#ifndef __GameManager__
#define __GameManager__


class GameManager
{
public:
	GameManager() {}
	int getGamePrice();
	void setGamePrice(int price);

	// ���� �Լ� ����
	virtual string selectWinner() = 0;
	virtual void dealCard() = 0;

protected:
	int m_gameType; // 1 : �������, 2 : Ȧ��
	int m_gamePrice;
	vector <string> m_cardVector;
};


class OldMaid : public GameManager
{

public:

	void dealCard() override;
	
	// �ߺ� ���� �Լ�
	void removeDuplicates(vector<string>& playerCards);
	void disCard();
	// ���� ���� �� ������ �����ִ� �Լ�
	void selectRoutine();
	void printSelectRoutine();
	// ���� ī�带 ��� �Լ� pickCard()����
	vector<string>& getPlayerCards(string& player);
	void pickCard();
	string determineWinner();
	string selectWinner() override;
	int getGameRound();

	// ī�� ���� �� �÷��̾� 1,2,3 ���� �ش� ���� ī�� ���� ����
	vector<string> player1Cards;
	vector<string> player2Cards;
	vector<string> player3Cards;

private:
	int m_gameRound = 1;
	int m_zeroCnt = 0;
	vector<string> players = { "��", "user1" , "user2" };
	vector<string> playerOrder;

};

#endif