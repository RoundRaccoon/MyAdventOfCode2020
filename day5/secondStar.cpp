#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream f(".in");

int getSeatID(string s)
{
    int lowerRow = 0, upperRow = 127;
    for (int i = 0; i < 7; ++i)
    {
        int middle = (lowerRow + upperRow) / 2;
        if (s[i] == 'F')
            upperRow = middle;
        else if (s[i] == 'B')
            lowerRow = middle + 1;
    }

    int leftColumn = 0, rightColumn = 7;
    for (int i = 7; i < 10; ++i)
    {
        int middle = (leftColumn + rightColumn) / 2;
        if (s[i] == 'L')
            rightColumn = middle;
        else if (s[i] == 'R')
            leftColumn = middle + 1;
    }

    return (lowerRow * 8 + leftColumn);
}

int main()
{
    string s;
    int maxID = INT32_MIN;
    bool occupied[1024];

    for (int i = 0; i < 1024; ++i)
        occupied[i] = false;

    while (getline(f, s))
    {
        int ID = getSeatID(s);
        occupied[ID] = true;
    }

    int i = 0;

    while (!occupied[i])
        ++i;

    while (occupied[i])
        ++i;

    cout << i;

    return 0;
}