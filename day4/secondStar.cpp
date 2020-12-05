#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#define len s.length()

#define BIRTH_YEAR "byr"
#define ISSUE_YEAR "iyr"
#define EXP_YEAR "eyr"
#define HEIGHT "hgt"
#define HAIR_COLOR "hcl"
#define EYE_COLOR "ecl"
#define PASS_ID "pid"

#define MAX_FIELDS 7
#define END_OF_PASSPORT len < 2

using namespace std;

ifstream f(".in");

bool check(bool req[MAX_FIELDS])
{
    for (int i = 0; i < MAX_FIELDS; ++i)
        if (!req[i])
            return false;
    return true;
}

void wipe(bool req[MAX_FIELDS])
{
    for (int i = 0; i < MAX_FIELDS; ++i)
        req[i] = false;
    return;
}

bool isBetween(int x, int lowerBound, int upperBound)
{
    return x >= lowerBound && x <= upperBound;
}

int string_to_int(string s)
{
    int ans = 0;
    for (int i = 0; i < len; ++i)
        ans = ans * 10 + (s[i] - '0');
    return ans;
}

void search_fields_and_check(string s, vector<string> searchFields, bool req[7])
{

    vector<pair<int, int>> yearBounds{
        {1920, 2002},
        {2010, 2020},
        {2020, 2030}};

    for (int i = 0; i < 3; ++i)
    {
        size_t found = s.find(searchFields[i]);
        if (found != string::npos)
        {
            string year = s.substr(found + 4, 4);
            if (isBetween(string_to_int(year), yearBounds[i].first, yearBounds[i].second))
                req[i] = true;
        }
    }

    vector<pair<int, int>> heightBounds{
        {150, 193},
        {59, 76}};

    size_t found = s.find(searchFields[3]);
    if (found != string::npos)
    {
        int start = found + 4;
        int end = start;
        for (; isdigit(s[end]); ++end)
            ;
        int height = string_to_int(s.substr(start, end - start));

        string unit = s.substr(end, 2);
        if (unit.compare("cm") == 0)
        {
            if (isBetween(height, heightBounds[0].first, heightBounds[0].second))
                req[3] = true;
        }
        else if (unit.compare("in") == 0)
        {
            if (isBetween(height, heightBounds[1].first, heightBounds[1].second))
                req[3] = true;
        }
    }

    found = s.find(searchFields[4]);
    if (found != string::npos)
    {

        if (s[found + 4] == '#')
        {
            int i;
            for (i = found + 5; i < len && isalnum(s[i]) && !isupper(s[i]); ++i)
                ;
            if (i == found + 11)
                req[4] = true;
        }
    }

    vector<string> eyeColors{
        "amb", "blu", "brn", "gry",
        "grn", "hzl", "oth"};

    found = s.find(searchFields[5]);
    if (found != string::npos)
    {
        string color = s.substr(found + 4, 3);
        for (int i = 0; i < 7; ++i)
            if (color.compare(eyeColors[i]) == 0)
            {
                req[5] = true;
                i = 8;
            }
    }

    found = s.find(searchFields[6]);
    if (found != string::npos)
    {

        int start = found + 4, end;
        for (end = start; end < len && isdigit(s[end]); ++end)
            ;
        if(end == start + 9)
            req[6] = true;
    }
}

int main()
{
    int validPassports = 0;
    bool requiredFields[MAX_FIELDS];
    wipe(requiredFields);
    string s;
    vector<string> searchFields{BIRTH_YEAR, ISSUE_YEAR,
                                EXP_YEAR, HEIGHT, HAIR_COLOR,
                                EYE_COLOR, PASS_ID};

    while (getline(f, s))
    {
        if (END_OF_PASSPORT)
        {
            if (check(requiredFields))
                validPassports++;
            wipe(requiredFields);
            continue;
        }
        search_fields_and_check(s, searchFields, requiredFields);
    }

    cout << validPassports;
    return 0;
}