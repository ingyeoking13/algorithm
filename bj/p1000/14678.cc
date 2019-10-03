#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
vector<int> e[(int)1e6];
int d[(int)1e6];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(d, -1, sizeof(d));
    int n;
    cin >> n;

    if (n==1)
    {
        cout << 1 <<"\n";
        return 0;
    }

    for (int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--,v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    d[0] = 0;

    int leaf =0, rootwin =0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if ( e[now].size() == 1 )
        {
            leaf++;
            if(d[now]%2==0) rootwin++;
        }

        for (auto next : e[now])
        {
            if ( d[next] >= 0 ) continue;
            d[next] = d[now]+1;
            q.push(next);
        }
    }

    int mx = 0;
    for (int i=0; i<n; i++)
    {
        if ( d[i]%2 == 1 )
        {
            mx = max( leaf - rootwin - (e[i].size()==1?1:0), mx);
        }
        else  mx = max(rootwin- (e[i].size()==1?1:0), mx);
    }
    cout << mx <<"\n";

}