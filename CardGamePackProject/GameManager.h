#pragma once
#include <vector>
#include <string>

#include "Card.h"

using namespace std;

class GameManager
{
public:
	int getGamePrice();
	void setGamePrice(int price);
	
	// ���� �Լ� ����
	virtual string selectWinner() = 0;
	virtual void dealCard() = 0;
	virtual void shuffleCard() = 0;

protected:
	int m_gameType; // 1 : �������, 2 : Ȧ��
	int m_gamePrice;
	vector <string> m_cardVector;
};

class Holdem : public GameManager
{
public:
	string selectWinner() override;
	void dealCard() override;
	void shuffleCard() override;

private:
	int m_gameCnt;
	int m_activePlayerNum;
	int m_sumBettingPoint;
};

class OldMaid : public GameManager
{
public:
	string selectWinner() override;
	void dealCard() override;
	void shuffleCard() override;

private:
	int m_zeroCnt;
};