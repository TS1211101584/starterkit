#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
class Mars
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
    Mars(int dimX, int dimY);
    void init(int dimX, int dimY);
    void display() const;
};
Mars::Mars(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'h', 'p', '^', 'v', '<', '>', 'r', '.'};
    int noOfObjects = 17; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)

    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}
void Mars::display() const
{
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "     = ALIEN vs ZOMBIES! =      " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row

    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
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
    cout << "  ";
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
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;

    cout << "Alien     : Life 100, Attack 0 " << endl;
    cout << "Zombie 1  : Life 250, Attack 5, Range 1" << endl;
    cout << "Zombie 2  : Life 250, Attack 15, Range 3" << endl;
}

void easy()
{
    cout << " 7 Col, 5 Row" << endl;
    Mars mars(7, 5);
    mars.display();
}

void medium()
{

    Mars mars(13, 7);
    mars.display();
}

void hard()
{
    Mars mars(19, 9);
    mars.display();
}

int main()
{
    srand(time(NULL)); // use this for fixed map during testing
                       // srand(time(NULL)); // try this for random map
    int choice;

    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "     = ALIEN vs ZOMBIES! =      " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    cout << "1. Easy   (7 Row, 5  Col)" << endl
         << "2. Medium (13 Row, 7 Col)" << endl
         << "3. Hard   (19Row, 9 Col)" << endl
         << "0. Exit" << endl;
    cout << "Your choice: ";

    cin >> choice;

    if (choice == 1)
        easy();
    else if (choice == 2)
        medium();
    else if (choice == 3)
        hard();
}