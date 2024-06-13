#include "Design.h"

void Design::cardDesign(string& card, int x, int y)
{
    string shape = card.substr(0, 1);
    string num = card.substr(1, 1);

    if (shape == "s")
    {
        shape = "♠";
    }
    else if (shape == "d")
    {
        shape = "◆";
    }
    else if (shape == "h")
    {
        shape = "♥";
    }
    else if (shape == "c")
    {
        shape = "♣";
    }

    drawSquare(x, y, 10, 7);
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

//색상 함수
void Design::setConsoleTextColor(WORD color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// 수평선을 그리는 함수
void Design::drawHorizontalLine(int x, int y, int length) {
    gotoxy(x, y);
    for (int i = 0; i < length; ++i) {
        std::cout << "─";
    }
    std::cout << std::endl;
}

// 수직선을 그리는 함수
void Design::drawVerticalLine(int x, int y, int length) {
    for (int i = 0; i < length; ++i) {
        gotoxy(x, y + i);
        std::cout << "│";
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
    cout << "┌";
    gotoxy(x + width, y);
    cout << "┐";
    gotoxy(x, y + height);
    cout << "└";
    gotoxy(x + width, y + height);
    cout << "┘";

}

void Design::printMyCard(vector<string>& myCard)
{
    vector<string> spade, diamond, heart, clover;
    int myCardSize = myCard.size();
    for (int i = 0; i < myCardSize; i++)
    {
        string shape = myCard[0].substr(0, 1);
        string num = myCard[0].substr(1, 1);
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
    gotoxy(50, 2);
    cout << "------my Card-----";

    gotoxy(50, 3);
    cout << "| ♠ | ";
    for (int i = 0; i < spade.size(); i++)
    {
        cout << spade[i] << " ";
    }

    gotoxy(50, 4);
    cout << "| ◆ | ";
    for (int i = 0; i < diamond.size(); i++)
    {
        cout << diamond[i] << " ";
    }

    gotoxy(50, 5);
    cout << "| ♥ | ";
    for (int i = 0; i < heart.size(); i++)
    {
        cout << heart[i] << " ";
    }

    gotoxy(50, 6);
    cout << "| ♣ | ";
    for (int i = 0; i < clover.size(); i++)
    {
        cout << clover[i] << " ";
    }
}

void Design::printMyInfo(vector<string>& myInfo)
{
    drawSquare(50, 15, 20, 5);
    gotoxy(52, 17);
    cout << myInfo[2];
    gotoxy(52, 18);
    cout << myInfo[3];

    gotoxy(100, 30);
}

void HoldemDesign::printCommunityCard(vector<string>& communityCard, int turnNum)
{
    //drawSquare(5, 10, 10, 7); // (x, y, 가로, 세로)
    //drawSquare(25, 10, 10, 7);
    //drawSquare(45, 10, 10, 7);
    //drawSquare(65, 10, 10, 7);
    //drawSquare(85, 10, 10, 7);

    if (turnNum == 0)
    {
        drawSquare(5, 10, 10, 8); // (x, y, 가로, 세로)
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

void OldMaidDesign::printJoker()
{
    vector<vector<string>> letters = { getJ(), getO(), getK(), getE(), getR() };

    // Determine the maximum height of the letters
    size_t max_height = 0;
    for (const auto& letter : letters) {
        if (letter.size() > max_height) {
            max_height = letter.size();
        }
    }
    setConsoleTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // 빨간색 설정
    // Print each row of the combined letters
    for (size_t row = 0; row < max_height; ++row) {
        gotoxy(50, 7 + row);
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
    setConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 기본 색상으로 복원
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
