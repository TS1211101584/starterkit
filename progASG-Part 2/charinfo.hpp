#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void charinfo(int numOfZombie, int column, int row)
{
    int alnDefLf = 100;
    int alnDeftAtk = 0;
    cout << setw(2) << " ";
    cout <<"Alien       : Life " << alnDefLf << "     , Attack    " << alnDeftAtk << endl;
    int zomCount = 1;
    for (int b = 0; b < numOfZombie; ++b)
    {
        int rdmLife = rand() % 9 + 1;
        int defLife = rdmLife * 100;

        int rdmAtk = rand() % 50 + 1;
        int rdmRange;

        if (column <= row)
        {
            int rangeMax = column;
            rdmRange = rand() % (column + 1);
        }
        else if (row <= column)
        {
            int rangeMax = row;
            rdmRange = rand() % (row + 1); 
        }

        cout << setw(2) << " ";
        cout << "Zombie " << zomCount << "    : Life " << defLife << "     , Attack    " << rdmAtk << "     , Range  " << rdmRange << endl;
        zomCount++;
        
    }
    cout << endl;
}