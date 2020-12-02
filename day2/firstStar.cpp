#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream f("input.in");



int check_password(string s)
{
    int leftMargin=0, rightMargin=0, charCount=0;
    int i;
    char searchChar;

    for(i = 0 ; i < s.length() && s[i]!='-'; ++i)
        leftMargin = leftMargin * 10 + (s[i] - '0');

    i++;

    for(;i < s.length() && s[i]!=' '; ++i)
        rightMargin = rightMargin * 10 + (s[i] - '0');

    i++;

    searchChar = s[i];

    for(i+=3; i < s.length() ; ++i)
        if(s[i]==searchChar)
            charCount++;

    if(charCount >= leftMargin && charCount <= rightMargin)
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
