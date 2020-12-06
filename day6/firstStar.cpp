#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f(".in");

void wipe(bool b[26], int &c)
{
    c = 0;
    for (int i = 0; i < 26; ++i)
        b[i] = false;
    return;
}

int main()
{

    bool answered[26];
    int count, ans = 0;
    wipe(answered, count);
    string s;

    while (getline(f, s))
    {

        if (s.length() < 1)
        {
            ans += count;
            wipe(answered, count);
            continue;
        }

        for (int i = 0; i < s.length(); ++i)
            if( answered[s[i] - 'a'] == false )
            {
                answered[s[i] - 'a'] = true;
                count++;
            }
    }

    cout << ans+count;
    return 0;
}