#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
	Card(int type) // type 1: �������, 2: Ȧ��
	{
		m_cardVector = makeDeck(type);
	}

	void suffleCards();
	void showMyCard();
	vector<string> getCardVector();

private:
	vector<string> m_cardVector;
	vector<string> makeDeck(int type);
};