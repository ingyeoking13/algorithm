#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> vv;
vector<int> solution(string s) {
    vector<int> answer;
    
    int mxidx = 0;
    for (int i=1; i<s.size(); i++)
    {
        if ( s[i] == '{')
        {
            i++;
            int num = 0;
            vector<int> tmpv;
            while (s[i] != '}')
            {
                if (s[i] != ',')
                {
                    num*=10;
                    num+=(s[i]-'0');
                }
                else 
                {
                    tmpv.push_back( num ), num=0;
                }
                
                i++;
            }
            tmpv.push_back(num);
            vv.push_back( tmpv );
        }
    }
    
    sort( vv.begin(), vv.end(), []( vector<int> x, vector<int> y)
    {
         return x.size()  < y.size();
    });
    
    
    set<int> exist;
    for (vector<int> vec : vv)
    {
        for (int j : vec) 
        {
            if (exist.find(j) == exist.end()) answer.push_back(j), exist.insert(j);
        }
    }
    
    return answer;
}