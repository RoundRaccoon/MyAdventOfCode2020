#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>

using namespace std;

map<string, int> indexOfColor;

ifstream f(".in");

long long solve(int bags[601][601], int n, int start)
{

    queue<pair<int, long long>> q;
    q.push(make_pair(start, 1));
    long long ans = 0;

    while (!q.empty())
    {
        pair<int,long long> crtPair = q.front();
        q.pop();

        int crt = crtPair.first;
        long long multiplier = crtPair.second;

        for (int i = 1; i <= n; ++i)
            if(bags[crt][i])
            {
                ans += bags[crt][i]*multiplier;
                q.push(make_pair(i,bags[crt][i]*multiplier));
            }   
    }

    return ans;

}

int main()
{
    string s;
    int bags[601][601];
    int destIndex = 0;

    for (int i = 1; i <= 600; ++i)
        for (int j = 1; j <= 600; ++j)
            bags[i][j] = false;

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
                int number = s[i] - '0';
                int j = i + 2;
                for (; j < s.length() && s[j] != ' '; ++j)
                    ;
                ++j;
                for (; j < s.length() && s[j] != ' '; ++j)
                    ;

                string newColor = s.substr(i + 2, j - i - 2);

                if (indexOfColor.find(newColor) != indexOfColor.end())
                {
                    bags[indexOfColor[currentColor]][indexOfColor[newColor]] = number;
                }
                else
                {
                    n++;
                    indexOfColor[newColor] = n;
                    bags[indexOfColor[currentColor]][indexOfColor[newColor]] = number;

                    if (newColor.compare("shiny gold") == 0)
                        destIndex = n;
                }
            }
        }
    }

    cout << solve(bags,n,destIndex);

    return 0;
}
