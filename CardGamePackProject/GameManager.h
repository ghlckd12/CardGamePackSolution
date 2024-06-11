#pragma once

// time �Լ� ���
#include <iostream>
#include <ctime>
#include <cstdlib>
// random_suffle �Լ� ���
#include <algorithm>
#include <vector>
#include <string>
<<<<<<< HEAD
#include "Card.h"
=======

#include "CardDeck.h"
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3

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

<<<<<<< HEAD
=======
class Holdem : public GameManager
{
public:
	Holdem() { m_gameType = 2; m_gamePrice = 0; m_gameCnt = 0;  m_activePlayerNum = 0; m_sumBettingPoint = 0; }
	string selectWinner() override;
	void dealCard() override;
	void play();

private:
	int m_gameCnt;
	int m_activePlayerNum;
	int m_sumBettingPoint;
	vector <string> m_fieldCard;
	vector <vector <string>> m_totalUserCard;
};
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3

class OldMaid : public GameManager
{

public:
<<<<<<< HEAD

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
=======
	void dealCard() override;
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3

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
<<<<<<< HEAD

};

#endif
=======
};
>>>>>>> 8c6d4269cc11034bd71b4b2c76a3ecd9c11702c3
