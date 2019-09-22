/*
naver 2019 하반기 
풀어보라고해서 
description.png 참고 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main()
{
   

    vector<long long> ans;
    set<long long> ss;

    for (int i=1; i<=1e6; i++)
    {
        long long val = i;
        for (int j=1; j<14; j++)
        {
            val *= (i+j);
            if ( val >= 1e12 ) break;
            ss.insert(val);
        }
    }
    for (auto i : ss )
    {
        ans.push_back(i);
    }
    for (int tt=1; tt<=1e6; tt++)
    {
        int n;
        //cin >> n;
        n =tt;
        cout << ans[n-1] << "\n";
    }
}


