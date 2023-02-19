#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "charinfo.hpp"
using namespace std;

void refresh(vector<vector<char>> &board, int column, int row, int numOfZombie)
{

    system("cls");

    for (int a = 0; a < column - 8; ++a)
    {
        cout << " ";
    }
    cout << ".: Alien vs Zombie :." << endl; // 21

    for (int y = 0; y < row; y++)
    {

        cout << "  ";
        for (int j = 0; j < column; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (y + 1);

        for (int x = 0; x < column; x++)
        {
            cout << "|" << board[x][y];
        }
        cout << "|" << endl;
    }

    cout << "  ";
    for (int j = 0; j < column; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << "  ";
    for (int j = 0; j < column; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < column; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;

    charinfo(numOfZombie, column, row);
}