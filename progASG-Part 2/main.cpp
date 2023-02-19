#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#include "condition.hpp"

using namespace std;

void defaultSetting();

int row = 5, column = 9, numOfZombie = 1;
int x, y;

void help()
{
    cout << endl
         << "Commands" << endl;
    cout << "--------------" << endl;
    cout << "1.  up - Move up." << endl;
    cout << "2.  down - Move down." << endl;
    cout << "3.  left - Move left." << endl;
    cout << "4.  right - Move right." << endl;
    cout << "5.  arrow - Change the direction of an arrow." << endl;
    cout << "6.  help - Display user commands." << endl;
    cout << "7.  new - Generates new board." << endl;
    cout << "8.  reset - Resets the game." << endl;
    cout << "9.  save - Save the game." << endl;
    cout << "10. load - Load a game." << endl;
    cout << "11. quit - Quit the game." << endl;
}

void saveFile(string filename, vector<vector<char>> &boardsave, int row, int column)
{

    ofstream file(filename);
    if (file.is_open())
    {
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < column; y++)
            {
                file << boardsave[x][y];
            }
            file << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void loadFile(string filename, vector<vector<char>> &boardload, int row, int column)
{
    ifstream file(filename);
    if (file.is_open())
    {
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < column; y++)
            {
                file >> boardload[x][y];
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
        system("pause");
    }
}

void defaultSetting()
{
    string selection;
    cout << " " << endl;
    cout << "--__--__--__--__--__--__--__--_" << endl;
    cout << "     = ALIEN vs ZOMBIES! =     " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    cout << " " << endl;
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "gameboard Rows    : 5" << endl;
    cout << "gameboard Columns : 9" << endl;
    cout << "Zombie Count  : 1" << endl
         << endl;

    cout << "Do you wish to change the game settings (y/n)? => ";
    getline(cin >> ws, selection);
    while (selection != "y" && selection != "n")
    {
        cout << " " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|SORRY! Please Choose Only Character (y/n) |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << endl;
        cout << "Change the game settings (y/n)? => ";
        cin >> selection;
    }

    if (selection == "y")
    {
        system("Cls");
        cout << "gameboard Settings" << endl;
        cout << "------------------" << endl;
        cout << "Enter rows => ";
        cin >> row;
        while (row % 2 == 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << " " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|SORRY! Enter an odd number |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
                 << endl;
            cout << "Enter rows => ";
            cin >> row;
        }
        cout << "Enter columns => ";
        cin >> column;

        while (column % 2 == 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << " " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|SORRY! Enter an odd number |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
                 << endl;
            cout << "Enter Columns => ";
            cin >> column;
        }

        cout << endl;

        cout << "Zombie Settings" << endl;
        cout << "-------------------" << endl;
        cout << "Enter number of zombies => ";
        cin >> numOfZombie;
        while (numOfZombie > 9 || cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "*****************************************************************" << endl;
            cout << "|SORRY! Number of zombies should not be more than 9. |" << endl;
            cout << "*****************************************************************" << endl
                 << endl;
            cout << "Enter number of zombies => ";
            cin >> numOfZombie;
        }
        cout << endl;

        cout << "Settings updated." << endl;
        system("PAUSE");
    }
    else if (selection == "n")
    {
        cout << " " << endl;
        cout << "Default Settings Maintained. " << endl;
        row = 5;
        column = 9;
        numOfZombie = 1;
    }
}

class character
{
private:
    vector<vector<char>> gameboard;

public:
    char alien = 'A';
    int alienLife = 100;
    int alienAttack = 0;
    char zombie = 'Z';
    int zomL = rand() % 5 + 1;
    int zomLife = zomL * 100;
    int zomAttack = rand() % 30 + 1;
    void game();
};

// fix the printed object
//  save and load file not working

void character::game()
{
    // initialize gameboard
    character ch;
    char gameboard[column][row];

    int x, y;

    char objects[] = {' ', ' ', ' ', ' ', ' ', '^', 'v', '<', '>', 'h', 'p', 'r', 'A', '.', '1', '2', '3', '4',
                      '5', '6', '7', '8', '9'};
    int items = 12;
    int fromalien = 11;

    for (x = 0; x < column; x++)
    {
        for (y = 0; y < row; y++)
        {
            int objNo = rand() % items;
            gameboard[x][y] = objects[objNo];
        }
        cout << endl;
    }

    for (int i = 14; i < numOfZombie + 14; i++)
    {
        int rc = rand() % column;
        int rr = rand() % row;

        // cout << rc << " " << rr << endl;
        // system("pause");
        gameboard[rc][rr] = objects[i];
    }

    int mc = column / 2;
    int mr = row / 2;

    // cout << mc << " " << mr;

    gameboard[mc][mr] = objects[12];

    int xpos = mc;
    int ypos = mr;

    // saving gameboard for "reset"
    vector<vector<char>> gameboardHis;

    for (int i = 0; i < column; i++)
    {
        vector<char> rowHis;
        for (int j = 0; j < row; j++)
        {
            rowHis.push_back(gameboard[i][j]);
        }
        gameboardHis.push_back(rowHis);
    }

    while (true)
    {
    refreshgameboard:

        system("cls");

        gameboard[xpos][ypos] = 'A';

        // cout << "refreshing gameboard" << endl;

        // clear trail
        for (y = 0; y < row; y++)
        {
            for (x = 0; x < column; x++)
            {
                if (gameboard[x][y] == '.')
                {
                    gameboard[x][y] = ' ';
                }
            }
        }

        vector<vector<char>> gameboardVector;

        for (int i = 0; i < column; i++)
        {
            vector<char> rowVector;
            for (int j = 0; j < row; j++)
            {
                rowVector.push_back(gameboard[i][j]);
            }
            gameboardVector.push_back(rowVector);
        }
        refresh(gameboardVector, column, row, numOfZombie);

    com:
        string command;

        cout << "Command: ";
        cin >> command;

        if (command == "quit")
        {
            exit(0);
        }
        // else if (command == "reset")
        // {
        //     refresh(gameboardHis, column, row, numOfZombie);
        //     goto refreshgameboard;
        // }
        else if (command == "new")
        {
            ch.game();
        }
        else if (command == "arrow")
        {
            cout << "When you press enter, it goes to the next line." << endl;
            cout << "Command: column number" << endl;
            cout << "         row number" << endl;
            cout << "         arrow direction" << endl;

            system("pause");
            system("cls");

            refresh(gameboardVector, column, row, numOfZombie);

            int x, y;
            char arrow;
            cin >> x;
            cin >> y;
            cin >> arrow;

            if (arrow == 'v' || arrow == '^' || arrow == '<' || arrow == '>')
            {
                gameboard[x - 1][y - 1] = arrow;
            }
            else
            {
                cout << "Invalid response." << endl;
                system("pause");
                system("cls");
                refresh(gameboardVector, column, row, numOfZombie);
                goto com;
            }

            vector<vector<char>> gameboardVector;

            for (int i = 0; i < column; i++)
            {
                vector<char> rowVector;
                for (int j = 0; j < row; j++)
                {
                    rowVector.push_back(gameboard[i][j]);
                }
                gameboardVector.push_back(rowVector);
            }
            refresh(gameboardVector, column, row, numOfZombie);
            system("pause");
            goto refreshgameboard;
        }
        else if (command == "help")
        {

            help();
            system("pause");
            goto refreshgameboard;
        }
        else if (command == "save")
        {
            string filename;
            cout << "Enter the file name to save the current game (Eg: game_name.txt): " << endl;
            cin >> filename;
            saveFile(filename, gameboardVector, row, column);
        }
        else if (command == "load")
        {
            string filename;
            char choice;
            cout << "Do you want to save the current game? (y/n): ";
            cin >> choice;

            if (choice == 'y')
            {
                cout << "Enter the file name to save the current game (Eg: game_name.txt): " << endl;
                cin >> filename;
                saveFile(filename, gameboardVector, row, column);
            }  
            
            cout << "Enter the file name to load (Eg: game_name.txt): " << endl;
            cin >> filename;
            loadFile(filename, gameboardVector, row, column);
        }

        else if (command == "left" || command == "right" || command == "up" || command == "down")
        {
            if (command == "left")
            {
            left:
                cout << "Alien move left." << endl;
                while (xpos > 0)
                {
                    system("pause");
                    int savex = xpos;
                    int savey = ypos;
                    gameboard[savex][savey] = '.';

                    xpos--;

                    // repetitive can be shorten

                    if (gameboard[xpos][ypos] >= '1' && gameboard[xpos][ypos] <= '9')
                    {
                        stopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == 'r')
                    {
                        cout << "Alien hits rock" << endl;
                        system("PAUSE");
                        gameboard[savex][savey] = 'A';
                        int objspawn = 11;
                        int randobj = rand() % objspawn;
                        gameboard[xpos][ypos] = objects[randobj];
                        vector<vector<char>> gameboardVector;

                        for (int i = 0; i < column; i++)
                        {
                            vector<char> rowVector;
                            for (int j = 0; j < row; j++)
                            {
                                rowVector.push_back(gameboard[i][j]);
                            }
                            gameboardVector.push_back(rowVector);
                        }
                        refresh(gameboardVector, column, row, numOfZombie);
                        system("pause");
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == ' ' || gameboard[xpos][ypos] == '.' || gameboard[xpos][ypos] == 'h' || gameboard[xpos][ypos] == 'p')
                    {
                        nonstopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                    }
                    else if (gameboard[xpos][ypos] == '^')
                    {
                        up(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto up;
                    }
                    else if (gameboard[xpos][ypos] == 'v')
                    {
                        down(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto down;
                    }
                    else if (gameboard[xpos][ypos] == '<')
                    {
                        left(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto left;
                    }
                    else if (gameboard[xpos][ypos] == '>')
                    {
                        right(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto right;
                    }
                }
            }

            else if (command == "right")
            {
            right:
                cout << "Alien move right." << endl;
                while (xpos < column - 1)
                {
                    int savex = xpos;
                    int savey = ypos;
                    gameboard[savex][savey] = '.';
                    xpos++;

                    if (gameboard[xpos][ypos] >= '1' && gameboard[xpos][ypos] <= '9')
                    {
                        stopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == 'r')
                    {
                        cout << "Alien hits rock" << endl;
                        system("PAUSE");
                        gameboard[savex][savey] = 'A';
                        int objspawn = 11;
                        int randobj = rand() % objspawn;
                        gameboard[xpos][ypos] = objects[randobj];
                        vector<vector<char>> gameboardVector;

                        for (int i = 0; i < column; i++)
                        {
                            vector<char> rowVector;
                            for (int j = 0; j < row; j++)
                            {
                                rowVector.push_back(gameboard[i][j]);
                            }
                            gameboardVector.push_back(rowVector);
                        }
                        refresh(gameboardVector, column, row, numOfZombie);
                        system("pause");
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == ' ' || gameboard[xpos][ypos] == '.' || gameboard[xpos][ypos] == 'h' || gameboard[xpos][ypos] == 'p')
                    {
                        nonstopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                    }
                    else if (gameboard[xpos][ypos] == '^')
                    {
                        up(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto up;
                    }
                    else if (gameboard[xpos][ypos] == 'v')
                    {
                        down(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto down;
                    }
                    else if (gameboard[xpos][ypos] == '<')
                    {
                        left(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto left;
                    }
                    else if (gameboard[xpos][ypos] == '>')
                    {
                        right(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto right;
                    }
                }
            }

            else if (command == "up")
            {
            up:
                cout << "Alien move up." << endl;
                while (ypos > 0)
                {
                    int savex = xpos;
                    int savey = ypos;
                    gameboard[savex][savey] = '.';
                    ypos--;

                    if (gameboard[xpos][ypos] >= '1' && gameboard[xpos][ypos] <= '9')
                    {
                        stopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == 'r')
                    {
                        cout << "Alien hits rock" << endl;
                        system("PAUSE");
                        gameboard[savex][savey] = 'A';
                        int objspawn = 11;
                        int randobj = rand() % objspawn;
                        gameboard[xpos][ypos] = objects[randobj];
                        vector<vector<char>> gameboardVector;

                        for (int i = 0; i < column; i++)
                        {
                            vector<char> rowVector;
                            for (int j = 0; j < row; j++)
                            {
                                rowVector.push_back(gameboard[i][j]);
                            }
                            gameboardVector.push_back(rowVector);
                        }
                        refresh(gameboardVector, column, row, numOfZombie);
                        system("pause");
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == ' ' || gameboard[xpos][ypos] == '.' || gameboard[xpos][ypos] == 'h' || gameboard[xpos][ypos] == 'p')
                    {
                        nonstopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                    }
                    else if (gameboard[xpos][ypos] == '^')
                    {
                        up(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto up;
                    }
                    else if (gameboard[xpos][ypos] == 'v')
                    {
                        down(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto down;
                    }
                    else if (gameboard[xpos][ypos] == '<')
                    {
                        left(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto left;
                    }
                    else if (gameboard[xpos][ypos] == '>')
                    {
                        right(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto right;
                    }
                }
            }

            else if (command == "down")
            {

            down:
                cout << "Alien move down." << endl;
                while (ypos < row - 1)
                {
                    int savex = xpos;
                    int savey = ypos;
                    gameboard[savex][savey] = '.';
                    ypos++;

                    if (gameboard[xpos][ypos] >= '1' && gameboard[xpos][ypos] <= '9')
                    {
                        stopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == 'r')
                    {
                        cout << "Alien hits rock" << endl;
                        system("PAUSE");
                        gameboard[savex][savey] = 'A';
                        int objspawn = 11;
                        int randobj = rand() % objspawn;
                        gameboard[xpos][ypos] = objects[randobj];
                        vector<vector<char>> gameboardVector;

                        for (int i = 0; i < column; i++)
                        {
                            vector<char> rowVector;
                            for (int j = 0; j < row; j++)
                            {
                                rowVector.push_back(gameboard[i][j]);
                            }
                            gameboardVector.push_back(rowVector);
                        }
                        refresh(gameboardVector, column, row, numOfZombie);
                        system("pause");
                        xpos = savex;
                        ypos = savey;
                        break;
                    }
                    else if (gameboard[xpos][ypos] == ' ' || gameboard[xpos][ypos] == '.' || gameboard[xpos][ypos] == 'h' || gameboard[xpos][ypos] == 'p')
                    {
                        nonstopcon(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                    }
                    else if (gameboard[xpos][ypos] == '^')
                    {
                        up(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto up;
                    }
                    else if (gameboard[xpos][ypos] == 'v')
                    {
                        down(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto down;
                    }
                    else if (gameboard[xpos][ypos] == '<')
                    {
                        left(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto left;
                    }
                    else if (gameboard[xpos][ypos] == '>')
                    {
                        right(numOfZombie, column, row, xpos, ypos, savex, savey, gameboardVector);
                        goto right;
                    }
                }
            }
        }

        else
        {
            cout << "Invalid Response" << endl;
            system("pause");
            system("cls");
            refresh(gameboardVector, column, row, numOfZombie);
            goto com;
        }
        cout << "Alien turn end. The trail resets" << endl;
        system("pause");
        gameboard[xpos][ypos] = 'A';
        goto refreshgameboard;
    }
}

int main()
{
    srand(time(NULL));

    defaultSetting();

    character ch;

    // turn
    while (true)
    {
        ch.game();

        for (int count = 1; count <= numOfZombie; count++)
        {
            cout << "Zombie " << count << "'s turn." << endl;
            // ch.zombie()
        }
    }
exit:
    abort;
}