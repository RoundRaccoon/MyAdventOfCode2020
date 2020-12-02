#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream f("input.in");



int check_password(string s)
{
    int firstPosition=0, secondPosition=0;
    int i;
    char searchChar;

    for(i = 0 ; i < s.length() && s[i]!='-'; ++i)
        firstPosition = firstPosition * 10 + (s[i] - '0');

    i++;

    for(;i < s.length() && s[i]!=' '; ++i)
        secondPosition = secondPosition * 10 + (s[i] - '0');

    i++;

    searchChar = s[i];

    i+=3;

    if(s[i + firstPosition - 1]==searchChar && s[i + secondPosition - 1]!=searchChar)
        return 1;
    if(s[i + firstPosition - 1]!=searchChar && s[i + secondPosition - 1]==searchChar)
        return 1;
    return 0;
}

int main()
{
    string s;
    int ans = 0;
    while(getline(f,s))
    {
        ans += check_password(s);
    }
    cout<<ans;
    return 0;
}
