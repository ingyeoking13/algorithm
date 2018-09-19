#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int n; scanf("%d", &n);
    int f, t; scanf("%d %d",&f, &t);
    int m; scanf("%d", &m);
    vector<vector<int>> e(n+1);
    vector<int> v(n+1);
    while(m--)
    {
        int u, v; scanf("%d %d", &u, &v);
        e[u].push_back(v); e[v].push_back(u);
    }

    queue<int> q;
    q.push(f);
    v[f]=1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto i : e[now])
        {
            if ( !v[i] ) 
            {
                v[i]=v[now]+1;
                q.push(i);
            }
        }
    }
    printf("%d\n", v[t]-1);
}