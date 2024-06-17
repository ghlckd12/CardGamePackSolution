#include "Design.h"
void Design::cardDesign(string & card, int x, int y)
{
    string shape = card.substr(0, 1);
    string num = card.substr(1, 1);
    if (num == "1") { num = "10"; }

    if (shape == "s")
    {
        shape = "��";
    }
    else if (shape == "d")
    {
        shape = "��";
    }
    else if (shape == "h")
    {
        shape = "��";
    }
    else if (shape == "c")
    {
        shape = "��";
    }

    drawSquare(x, y, 10, 8);
    gotoxy(x + 1, y + 1);
    cout << num;
    gotoxy(x + 9, y + 7);
    cout << num;
    gotoxy(x + 5, y + 4);
    cout << shape;

}

void Design::gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//���� �Լ�
void Design::setConsoleTextColor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// ������ �׸��� �Լ�
void Design::drawHorizontalLine(int x, int y, int length) {
    gotoxy(x, y);
    for (int i = 0; i < length; ++i) {
        std::cout << "��";
    }
    std::cout << std::endl;
}

// �������� �׸��� �Լ�
void Design::drawVerticalLine(int x, int y, int length) {
    for (int i = 0; i < length; ++i) {
        gotoxy(x, y + i);
        std::cout << "��";
    }
    std::cout << std::endl;
}

void Design::drawSquare(int x, int y, int width, int height)
{
    drawHorizontalLine(x, y, width);
    drawVerticalLine(x, y, height);
    drawVerticalLine(x + width, y, height);
    drawHorizontalLine(x, y + height, width);

    gotoxy(x, y);
    cout << "��";
    gotoxy(x + width, y);
    cout << "��";
    gotoxy(x, y + height);
    cout << "��";
    gotoxy(x + width, y + height);
    cout << "��";

}

void Design::printMyCard(vector<string>& myCard)
{
    vector<string> spade, diamond, heart, clover;
    int myCardSize = myCard.size();
    for (int i = 0; i < myCardSize; i++)
    {
        string shape = myCard[i].substr(0, 1);
        string num = myCard[i].substr(1, 1);
        if (shape == "s")
        {
            spade.push_back(num);
        }
        else if (shape == "d")
        {
            diamond.push_back(num);
        }
        else if (shape == "h")
        {
            heart.push_back(num);
        }
        else if (shape == "c")
        {
            clover.push_back(num);
        }
    }
    gotoxy(50, 3);
    cout << "------my Card-----";

    gotoxy(50, 4);
    cout << "| �� | ";
    for (int i = 0; i < spade.size(); i++)
    {
        cout << spade[i] << " ";
    }

    gotoxy(50, 5);
    cout << "| �� | ";
    for (int i = 0; i < diamond.size(); i++)
    {
        cout << diamond[i] << " ";
    }

    gotoxy(50, 6);
    cout << "| �� | ";
    for (int i = 0; i < heart.size(); i++)
    {
        cout << heart[i] << " ";
    }

    gotoxy(50, 7);
    cout << "| �� | ";
    for (int i = 0; i < clover.size(); i++)
    {
        cout << clover[i] << " ";
    }
}

void Design::printMyInfo(vector<string>& myInfo)
{
    drawSquare(80, 3, 20, 5);
    gotoxy(82, 5);
    cout << "�г��� : " << myInfo[0];
    gotoxy(82, 6);
    cout << "����Ʈ : " << myInfo[1];

    gotoxy(100, 30);
}

void HoldemDesign::printCommunityCard(vector<string>& communityCard, int turnNum)
{
    //drawSquare(5, 10, 10, 7); // (x, y, ����, ����)
    //drawSquare(25, 10, 10, 7);
    //drawSquare(45, 10, 10, 7);
    //drawSquare(65, 10, 10, 7);
    //drawSquare(85, 10, 10, 7);

    if (turnNum == 0)
    {
        drawSquare(5, 10, 10, 8); // (x, y, ����, ����)
        drawSquare(20, 10, 10, 8);
        drawSquare(35, 10, 10, 8);
        drawSquare(50, 10, 10, 8);
        drawSquare(65, 10, 10, 8);
    }
    else
    {
        for (int i = 0; i < turnNum + 2; i++)
        {
            cardDesign(communityCard[i], 5 + 15 * i, 10);
        }
        if (turnNum == 1)
        {
            drawSquare(50, 10, 10, 8);
            drawSquare(65, 10, 10, 8);
        }
        else if (turnNum == 2)
        {
            drawSquare(65, 10, 10, 8);
        }
    }

    gotoxy(100, 20);
}

void HoldemDesign::showHoldemResult(string Nickname, vector<string>& rank, vector<vector<string>>& finalHand)
{
    system("cls");
    int cardNum = 0; // �� ���� ����� ���� ī���� ��
    cout << "-------Ȧ��--------" << endl;
    cout << "!��� ����!" << endl;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(0, 4 + 10 * i);
        if (i == 0)
        {
            cout << Nickname << "\n";
        }
        else if (i == 1)
        {
            cout << "Hong Jin Ho" << "\n";
        }
        else if (i == 2)
        {
            cout << "Jang Dong Min" << "\n";
        }
        cout << rank[i];
        cardNum = finalHand[i].size();
        for (int j = 0; j < cardNum; j++)
        {
            cardDesign(finalHand[i][j], 25 + j * 15, 3 + i * 10);
        }
    }
    gotoxy(1, 32);
}

void OldMaidDesign::printJoker()
{
    
    // ���� Ŀ�� ��ġ ����
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD originalPos = csbi.dwCursorPosition;

    vector<vector<string>> letters = { getJ(), getO(), getK(), getE(), getR() };

    // Determine the maximum height of the letters
    size_t max_height = 0;
    for (const auto& letter : letters) {
        if (letter.size() > max_height) {
            max_height = letter.size();
        }
    }
    setConsoleTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // ������ ����
    // Print each row of the combined letters
    for (size_t row = 0; row < max_height; ++row) {
        gotoxy(50, 8 + row);
        for (const auto& letter : letters) {
            if (row < letter.size()) {
                cout << letter[row];
            }
            else {
                // If the letter is shorter than the maximum height, print spaces
                cout << string(letter[0].size(), ' ');
            }
        }

        cout << endl;
    }
    setConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // �⺻ �������� ����
    // ���� ��ġ�� Ŀ�� �̵�
    gotoxy(originalPos.X, originalPos.Y);
}

void OldMaidDesign::printCardNum(string nickname, vector<int>& cardNum, vector <string> nickNameVector)
{   
    // ���� Ŀ�� ��ġ ����
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD originalPos = csbi.dwCursorPosition;
    
    vector <string> nickVec = { nickname, "Hong Jin Ho", "Jand Dong Min" };

    gotoxy(90, 1);
    cout << "------- ���� ī�� ���� -------\n";
    for (int i = 0; i < 3; i++)
    {
        gotoxy(90, 2 + i);

        cout << nickVec[i] << "���� ī�� �� : " << cardNum[i] << endl;
    }
    
    // ���� ��ġ�� Ŀ�� �̵�
    gotoxy(originalPos.X, originalPos.Y);

}


vector<string> OldMaidDesign::getJ() {
    return {
        " ***** ",
        "   *   ",
        "   *   ",
        "*  *   ",
        " ***   "
    };
}

vector<string> OldMaidDesign::getO() {
    return {
        " ***  ",
        "*   * ",
        "*   * ",
        "*   * ",
        " ***  "
    };
}

vector<string> OldMaidDesign::getK() {
    return {
        "*   * ",
        "*  *  ",
        "***   ",
        "*  *  ",
        "*   * "
    };
}

vector<string> OldMaidDesign::getE() {
    return {
        "***** ",
        "*     ",
        "***** ",
        "*     ",
        "***** "
    };
}

vector<string> OldMaidDesign::getR() {
    return {
        "****  ",
        "*   * ",
        "****  ",
        "*  *  ",
        "*   * "
    };
}


void OldMaidDesign::oldMaidPrintMyCard(vector<string>& myCard)
{
  // ���� Ŀ�� ��ġ ����
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  COORD originalPos = csbi.dwCursorPosition;

  vector<string> spade, diamond, heart, clover;
  int myCardSize = myCard.size();
  for (int i = 0; i < myCardSize; i++)
  {
    string shape = myCard[i].substr(0, 1);
    string num = myCard[i].substr(1, 1);
    if (shape == "s")
    {
      spade.push_back(num);
    }
    else if (shape == "d")
    {
      diamond.push_back(num);
    }
    else if (shape == "h")
    {
      heart.push_back(num);
    }
    else if (shape == "c")
    {
      clover.push_back(num);
    }
  }
  gotoxy(50, 3);
  cout << "------my Card-----";

  gotoxy(50, 4);
  cout << "| �� | ";
  for (int i = 0; i < spade.size(); i++)
  {
    cout << spade[i] << " ";
  }

  gotoxy(50, 5);
  cout << "| �� | ";
  for (int i = 0; i < diamond.size(); i++)
  {
    cout << diamond[i] << " ";
  }

  gotoxy(50, 6);
  cout << "| �� | ";
  for (int i = 0; i < heart.size(); i++)
  {
    cout << heart[i] << " ";
  }

  gotoxy(50, 7);
  cout << "| �� | ";
  for (int i = 0; i < clover.size(); i++)
  {
    cout << clover[i] << " ";
  }

  // ���� ��ġ�� Ŀ�� �̵�
  gotoxy(originalPos.X, originalPos.Y);
}

void OldMaidDesign::printSelectRoutine(vector<string>& playerTurn, vector<string>& nickNameVector)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  COORD originalPos = csbi.dwCursorPosition;

  gotoxy(90, 6);

  
  cout << "------- �÷��̾� ���� -------\n";
  for (int i = 0; i < playerTurn.size(); ++i)
  {
    gotoxy(90, 7 + i);
    cout << (i + 1) << "��° : " << nickNameVector[i] << "\n";
  };
  
  gotoxy(originalPos.X, originalPos.Y);

}

void OldMaidDesign::getGamePointInfo()
{
  // ���� Ŀ�� ��ġ ����
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  COORD originalPos = csbi.dwCursorPosition;

  gotoxy(90, 3);
  cout << "------- ����Ʈ ȹ�� ���� -------\n";
  /*
  for (int i = 0; i < 3; i++)
  {
    gotoxy(90, 5 + i);
    if (i == 0)
    {
      cout << nickname << "�� ī�� �� : " << cardNum[i];
    }
    else
    {
      cout << i + 1 << "��° player�� ī�� �� : " << cardNum[i];
    }
    cout << endl;
  }
  */

  // ���� ��ġ�� Ŀ�� �̵�
  gotoxy(originalPos.X, originalPos.Y);

}