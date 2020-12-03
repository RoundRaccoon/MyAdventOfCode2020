#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("input.in");

int main()
{
    string s;
    getline(f,s);
    int len = s.length();
    int row = 0;
    int trees[]={0,0,0,0,0};
    int slopes[]={0,0,0,0,0};

    while(getline(f,s))
    {

        row++;
        slopes[0] = (slopes[0] + 1) % len;
        slopes[1] = (slopes[1] + 3) % len;
        slopes[2] = (slopes[2] + 5) % len;
        slopes[3] = (slopes[3] + 7) % len;
        if(row%2==0)
            slopes[4] = ( slopes[4] +1 )%len;

        if(s[slopes[0]] == '#')
            trees[0]++;

        if(s[slopes[1]] == '#')
            trees[1]++;

        if(s[slopes[2]] == '#')
            trees[2]++;

        if(s[slopes[3]] == '#')
            trees[3]++;

        if(s[slopes[4]] == '#' && row%2==0)
            trees[4]++;

    }

    cout<<(long long)trees[0]*trees[1]*trees[2]*trees[3]*trees[4];

    return 0;
}
