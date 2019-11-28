#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
vector<int> ans;
set<int> s;
int main()
{
    srand(time(0));
    int n;
    n = 10;
    while( ans.size()<10)
    {
    for (int i=1; i<=n; i++)
    {
        if ( rand()%2)
        {
            if ( s.find(i) == s.end()) 
            {
                ans.push_back(i);
                s.insert(i);
            }
        }
    }
    }

    for (int a : ans)
        cout << a << " ";
        cout <<"\n";

}
