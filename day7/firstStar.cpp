#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> indexOfColor;

ifstream f(".in");

int main()
{
    string s;
    bool adjacent[601][601];
    int destIndex = 0;

    for (int i = 1; i <= 600; ++i)
        for (int j = 1; j <= 600; ++j)
            adjacent[i][j] = false;

    int n = 0;
    while (getline(f, s))
    {

        int i = 0, j;
        for (; s[i] != ' '; ++i)
            ;
        ++i;
        for (; s[i] != ' '; ++i)
            ;
        string currentColor = s.substr(0, i);

        if (indexOfColor.find(currentColor) == indexOfColor.end())
        {
            n++;
            indexOfColor[currentColor] = n;

            if (currentColor.compare("shiny gold") == 0)
            destIndex = n;

        }

        for (; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
            {
                int j = i + 2;
                for (; j < s.length() && s[j] != ' '; ++j)
                    ;
                ++j;
                for (; j < s.length() && s[j] != ' '; ++j)
                    ;

                string newColor = s.substr(i + 2, j - i - 2);

                if (indexOfColor.find(newColor) != indexOfColor.end())
                {
                    adjacent[indexOfColor[currentColor]][indexOfColor[newColor]] = true;
                }
                else
                {
                    n++;
                    indexOfColor[newColor] = n;
                    adjacent[indexOfColor[currentColor]][indexOfColor[newColor]] = true;

                    if (newColor.compare("shiny gold") == 0)
                        destIndex = n;
                }
            }
        }
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if(adjacent[i][k] && adjacent[k][j])
                    adjacent[i][j] = true;

    int count = 0;
    for(int i = 1;i<=n;++i)
        if(adjacent[i][destIndex])
        count++;

    cout<<count;

    return 0;
}
