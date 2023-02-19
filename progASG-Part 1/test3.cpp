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
}

void easy()
{
    cout << " 5 Col, 7 Row" << endl;
    Mars mars(7, 5);
    mars.display();
    cout << "Alien     : Life 2, Attack 0 " << endl;
    cout << "Zombie 1  : Alive" << endl;
    cout << "Zombie 2  : Alive" << endl;
}

void medium()
{
    cout << " 7 Col, 13 Row" << endl;
    Mars mars(13, 7);
    mars.display();
    cout << "Alien     : Life 1, Attack 0 " << endl;
    cout << "Zombie 1  : Alive" << endl;
    cout << "Zombie 2  : Alive" << endl;
    cout << "Zombie 3  : Alive" << endl;
    cout << "Zombie 4  : Alive" << endl;
    cout << "Zombie 5  : Alive" << endl;
}

void hard()
{
    cout << " 9 Col, 19 Row" << endl;
    Mars mars(19, 9);
    mars.display();
    cout << "Alien     : Life 0, Attack 0 " << endl;
    cout << "Zombie 1  : Alive" << endl;
    cout << "Zombie 2  : Alive" << endl;
    cout << "Zombie 3  : Alive" << endl;
    cout << "Zombie 4  : Alive" << endl;
    cout << "Zombie 5  : Alive" << endl;
    cout << "Zombie 6  : Alive" << endl;
    cout << "Zombie 7  : Alive" << endl;
}
void exit()
{
    cout << "HAVE A NICE DAY !! " << endl;
}
void wrong()
{
    cout << "Choose a number between 1 to 3 only !! " << endl;
    cout << "restart the game :)" << endl;
}

int main()
{
    srand(time(NULL)); // use this for fixed map during testing
                       // srand(time(NULL)); // try this for random map
    int choice;

    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "     = ALIEN vs ZOMBIES! =      " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    cout << "1. Easy   (5 Col,  7 Row)" << endl
         << "2. Medium (7 Col, 13 Row)" << endl
         << "3. Hard   (9 Col, 19 Row)" << endl
         << "0. Exit " << endl;
    cout << "Your choice: ";

    cin >> choice;

    if (choice == 1)
        easy();
    else if (choice == 2)
        medium();
    else if (choice == 3)
        hard();
    else if (choice == 0)
        exit();
    else if (choice > 3)
        wrong();
}