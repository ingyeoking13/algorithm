#include <stdio.h>
#include <map>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;
//vector<pair<int, int>> a;
//deque<pair<int, int>> a;
set<pair<int, int>> a;
int b[(int)2e5];
int main()
{
    int n, m,d; scanf("%d%d%d", &n, &m, &d);
   // a.resize(n);
    for (int i=0; i<n;i++) {
        int tmp;
        scanf("%d", &tmp);
        a.insert({tmp,i});
    } 
 //   sort(a.begin(), a.end());
    int ans=0;
    while(!a.empty())
    {
        b[a.begin()->second]= ans+1;
        int peg = a.begin()->first;
        a.erase(a.begin());

        while(1)
        {
    //        auto i =lower_bound(a.begin(), a.end(), make_pair(peg+d+1,0));
            auto i = a.lower_bound({peg+d+1,0});
            if (i==a.end()) break;
            auto now = *i;
            b[now.second] = ans+1;
            peg = now.first;

            a.erase(i);
        }
        ans++;
    }

    printf("%d\n", ans);
    for (int i=0; i<n; i++)
    {
        printf("%d ", b[i]);
    }
}