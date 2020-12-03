#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("input.in");

int main()
{
    string s;
    int row = 0;
    int ans = 0;
    getline(f,s);
    int length = s.length();
    while(getline(f,s))
    {

        row = (row+3) % length ;

        if(s[row] == '#')
            ans++;

    }
    cout<<ans;
    return 0;
}
