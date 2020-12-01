#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

ifstream f("input.in");
map<int,pair<int,int> > sums;
vector<int>v;

int main()
{
    int x;
    while(f>>x)
        v.push_back(x);

    for(int i = 0 ; i < v.size()-1 ; ++i)
        for(int j = i + 1 ; j < v.size() ; ++j)
        sums[v[i]+v[j]] = make_pair(i,j);

    for(int i = 0 ; i < v.size() ; ++i)
        if(sums.find(2020 - v[i])!=sums.end())
        {
            map<int,pair<int,int> >::iterator it = sums.find(2020 - v[i]);
            if(i != it->second.first && i!=it->second.second)
            {
                cout<<v[i]*v[it->second.first]*v[it->second.second];
                return 0;
            }
        }

    cout<<"no pair";
    return 1;
}
