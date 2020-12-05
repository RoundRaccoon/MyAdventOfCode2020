#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

void search_for_fields(string s, vector<string> searchFields, bool req[MAX_FIELDS])
{
   for (int i = 0; i < searchFields.size(); ++i)
      if (s.find(searchFields[i]) != string::npos)
         req[i] = true;
   return;
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
      search_for_fields(s, searchFields, requiredFields);
   }

   cout<<validPassports;
   return 0;
}