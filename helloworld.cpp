#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int setRow(int);
int setCol(int);
int setNumOfZombies(int);
void displayGame(int, int, int);
void symbols(int, int);

class Game 
{
    private: 
        int row;
        int col;
        vector< vector<char> > map_;
    public:
        void init(int row, int col);
        void displayGame() const;
};

int main()
{
    int choice;

    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "     = ALIEN vs ZOMBIES! =      " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    cout << "1. Easy" << endl
         << "2. Medium" << endl
         << "3. Hard" << endl
         << "0. Exit" << endl;
    cout << "Your choice: ";

    cin >> choice;
    int row = setRow(choice);
    int col = setCol(choice);
    int zombies = setNumOfZombies(choice);

    // cout << row << " " << col << " " << zombies << endl;
    displayGame(row, col, zombies);

    return 0;
}

// easy 5x7 zombies:2
// medium 7x12 zombies:5
// hard 9x19 zombies:10
int setRow(int choice)
{
    int row;

    switch (choice)
    {
    case 1:
        row = 5;
        break;
    case 2:
        row = 7;
        break;
    case 3:
        row = 9;
        break;
    default:
    {
        cout << "Input error" << endl;
        main();
    }
    }

    return row;
}

int setCol(int choice)
{
    int col;

    switch (choice)
    {
    case 1:
        col = 7;
        break;
    case 2:
        col = 12;
        break;
    case 3:
        col = 19;
        break;
    default:
    {
        cout << "Input error" << endl;
        main();
    }
    }

    return col;
}

int setNumOfZombies(int choice)
{
    int zombies;

    switch (choice)
    {
    case 1:
        zombies = 2;
        break;
    case 2:
        zombies = 7;
        break;
    case 3:
        zombies = 9;
        break;
    default:
    {
        cout << "Input error" << endl;
        main();
    }
    }

    return zombies;
}
// Y=row X=col
void displayGame(int row, int col, int zombies)
{
    char map[row][col];

    // for each row
    for (int i = 0; i < row; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < col; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (row - i);
        // display cell content and border of each column
        for (int j = 0; j < col; ++j)
        {
            cout << "|" << map[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < col; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < col; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < col; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void symbols(int row, int col)
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$'};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map.resize(row); // create empty rows
    for (int i = 0; i < row; ++i)
    {
        map[i].resize(col); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
}
/*ITS HERE 
void Mars::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Curiosity, Welcome to Mars! =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}*/