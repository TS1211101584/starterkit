// stop condition
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "refresh.hpp"

void stopcon(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    if (board[xpos][ypos] >= '1' && board[xpos][ypos] <= '9')
    {
        for (int i = 1; i <= 9; i++)
        {
            if (board[xpos][ypos] == (i + '0'))
            {
                cout << "Ah!! Zombie" << endl;
                system("pause");
                board[savex][savey] = 'A';
                board[xpos][ypos] = (i + '0');
                vector<vector<char>> boardVector;
                for (int i = 0; i < column; i++)
                {
                    vector<char> rowVector;
                    for (int j = 0; j < row; j++)
                    {
                        rowVector.push_back(board[i][j]);
                    }
                    boardVector.push_back(rowVector);
                }
                refresh(boardVector, column, row, numOfZombie);
                xpos = savex;
                ypos = savey;
                break;
            }
        }
    }
}

void rock(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', '^', 'v', '<', '>', 'h', 'p', 'r', 'A', '.', '1', '2', '3', '4',
                      '5', '6', '7', '8', '9'};
    if (board[xpos][ypos] == 'r')
    {
        cout << "Alien hits rock" << endl;
        system("PAUSE");
        board[savex][savey] = 'A';
        int objspawn = 11;
        int randobj = rand() % objspawn;
        board[xpos][ypos] = objects[randobj];
        vector<vector<char>> boardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(board[i][j]);
            }
            boardVector.push_back(rowVector);
        }
        refresh(boardVector, column, row, numOfZombie);
        system("pause");
    }
}

void nonstopcon(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    if (board[xpos][ypos] == ' ')
    {
        cout << "Alien found an empty space" << endl;
        system("PAUSE");

        board[savex][savey] = '.';
        board[xpos][ypos] = 'A';
        vector<vector<char>> boardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(board[i][j]);
            }
            boardVector.push_back(rowVector);
        }
        refresh(boardVector, column, row, numOfZombie);
        system("PAUSE");
    }

    else if (board[xpos][ypos] == '.')
    {
        cout << "It's just a trail." << endl;
        system("PAUSE");
        board[savex][savey] = '.';
        board[xpos][ypos] = 'A';
        vector<vector<char>> boardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(board[i][j]);
            }
            boardVector.push_back(rowVector);
        }
        refresh(boardVector, column, row, numOfZombie);
    }

    else if (board[xpos][ypos] == 'h')
    {
        cout << "Alien finds a health pack." << endl;
        system("PAUSE");
        board[savex][savey] = '.';
        board[xpos][ypos] = 'A';
        vector<vector<char>> boardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(board[i][j]);
            }
            boardVector.push_back(rowVector);
        }
        refresh(boardVector, column, row, numOfZombie);

        // alienLife = min(100, alienLife + 20);
    }
    else if (board[xpos][ypos] == 'p')
    {
        cout << "Alien finds a pod." << endl;
        system("PAUSE");
        board[savex][savey] = '.';
        board[xpos][ypos] = 'A';
        vector<vector<char>> boardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(board[i][j]);
            }
            boardVector.push_back(rowVector);
        }
        refresh(boardVector, column, row, numOfZombie);

        // 10 attack to zombie
        // system("PAUSE");

        // alienAttack = 0;
    }
}

void left(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    cout << "Alien moves left." << endl;
    // alienAttack = alienAttack + 20;
    system("PAUSE");
    board[savex][savey] = '.';
    board[xpos][ypos] = 'A';
    vector<vector<char>> boardVector;

    for (int i = 0; i < column; i++)
    {
        vector<char> rowVector;
        for (int j = 0; j < row; j++)
        {
            rowVector.push_back(board[i][j]);
        }
        boardVector.push_back(rowVector);
    }
    refresh(boardVector, column, row, numOfZombie);
}

void right(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    cout << "Alien moves right." << endl;
    // alienAttack = alienAttack + 20;
    system("PAUSE");
    board[savex][savey] = '.';
    board[xpos][ypos] = 'A';
    vector<vector<char>> boardVector;

    for (int i = 0; i < column; i++)
    {
        vector<char> rowVector;
        for (int j = 0; j < row; j++)
        {
            rowVector.push_back(board[i][j]);
        }
        boardVector.push_back(rowVector);
    }
    refresh(boardVector, column, row, numOfZombie);
}

void up(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    cout << "Alien moves up." << endl;
    // alienAttack = alienAttack + 20;
    system("PAUSE");
    board[savex][savey] = '.';
    board[xpos][ypos] = 'A';
    vector<vector<char>> boardVector;

    for (int i = 0; i < column; i++)
    {
        vector<char> rowVector;
        for (int j = 0; j < row; j++)
        {
            rowVector.push_back(board[i][j]);
        }
        boardVector.push_back(rowVector);
    }
    refresh(boardVector, column, row, numOfZombie);
}

void down(int numOfZombie, int column, int row, int xpos, int ypos, int savex, int savey, vector<vector<char>> &board)
{
    cout << "Alien moves down." << endl;
    // alienAttack = alienAttack + 20;
    system("PAUSE");
    board[savex][savey] = '.';
    board[xpos][ypos] = 'A';
    vector<vector<char>> boardVector;

    for (int i = 0; i < column; i++)
    {
        vector<char> rowVector;
        for (int j = 0; j < row; j++)
        {
            rowVector.push_back(board[i][j]);
        }
        boardVector.push_back(rowVector);
    }
    refresh(boardVector, column, row, numOfZombie);
}