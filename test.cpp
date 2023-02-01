#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int setRow(int);
int setCol(int);
int setNumOfZombies(int);

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