#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)3e5], p[(int)3e5], d[(int)3e5];
vector<int> e[(int)3e5];
int go(int now)
{
    if ( e[now].size() == 0 )
        return d[now] = 1;

    if ( d[now] ) return d[now];
    
    int mn = 1e9;
    for (int i : e[now])
    {
        mn = min(go(i), mn);
    }
    if ( a[now] == 0 )
    {
        d[now] = 

    }
    
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
        d[i] = -1;
    }

    for (int i=1; i<=n-1; i++)
    {
        int tmp;
        cin >> tmp;
        p[i] = --tmp;
        e[tmp].push_back(i);
    }

    go(0);
}