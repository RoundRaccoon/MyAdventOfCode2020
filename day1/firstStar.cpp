#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

ifstream f("input.in");
map<int, bool > sums;

int main()
{
    int x;
    while(f>>x)
    {
        if(sums.find(2020-x)!=sums.end())
        {
            cout<< x * (2020 - x);
            return 0;
        }
        sums.insert(make_pair(x,true));
    }

    cout<<"no pair";
    return 1;
}
