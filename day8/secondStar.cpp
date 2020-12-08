#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream f(".in");

int check(vector<string> instruction, int n)
{

    bool visited[700];
    for(int i = 0 ; i < n ; ++i)
        visited[i] = false;

    int acc = 0;

    int i = 0;

    while(i < n)
    {

        if(visited[i]==true)
        {
            return INT_MIN;
        }

        visited[i]=true;

        if(instruction[i][0]=='a')
        {
            int sign;

            if(instruction[i][4]=='+')
                sign = 1;
            else sign = -1;

            int number = 0;
            int j;

            for(j = 5 ; j < instruction[i].length() ; ++j)
                number = number * 10 + (instruction[i][j]-'0');

            acc = acc + number*sign;
            ++i;
        }
        else if(instruction[i][0]=='n')
            ++i;
        else if(instruction[i][0]=='j')
        {
            int sign;

            if(instruction[i][4]=='+')
                sign = 1;
            else sign = -1;

            int number = 0;
            int j;

            for(j = 5 ; j < instruction[i].length() ; ++j)
                number = number * 10 + (instruction[i][j]-'0');

            i = i + number*sign;
        }

    }
    return acc;

}

int main()
{
    int n = 0;
    bool visited[700];
    vector<string> instruction;
    string s;
    while(getline(f,s))
        instruction.push_back(s);

    n = instruction.size();

    for(int i = 0 ; i < n ; ++i)
    {
        if(instruction[i][0]=='n')
        {
            instruction[i][0]='j';
            int result = check(instruction,n);
            if(result != INT_MIN)
            {
                cout<<result;
                return 0;
            }
            instruction[i][0]='n';
        }
        else if(instruction[i][0]=='j')
        {
            instruction[i][0]='n';
            int result = check(instruction,n);
            if(result != INT_MIN)
            {
                cout<<result;
                return 0;
            }
            instruction[i][0]='j';
        }
    }



    for(int i = 0 ; i < n ; ++i)
        visited[i] = false;

    int acc = 0;

    int i = 0;

    while(1)
    {

        if(visited[i]==true)
        {
            cout<<acc;
            return 0;
        }

        visited[i]=true;

        if(instruction[i][0]=='a')
        {
            int sign;

            if(instruction[i][4]=='+')
                sign = 1;
            else sign = -1;

            int number = 0;
            int j;

            for(j = 5 ; j < instruction[i].length() ; ++j)
                number = number * 10 + (instruction[i][j]-'0');

            acc = acc + number*sign;
            ++i;
        }
        else if(instruction[i][0]=='n')
            ++i;
        else if(instruction[i][0]=='j')
        {
            int sign;

            if(instruction[i][4]=='+')
                sign = 1;
            else sign = -1;

            int number = 0;
            int j;

            for(j = 5 ; j < instruction[i].length() ; ++j)
                number = number * 10 + (instruction[i][j]-'0');

            i = i + number*sign;
        }

    }


    return 0;
}
