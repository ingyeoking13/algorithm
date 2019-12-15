#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)3e5], d[(int)3e5];
int leaf =0;
vector<int> e[(int)3e5];
int go(int now)
{
    if ( e[now].size() == 0 )
    {
        leaf++;
        return d[now] = 1;
    }

    if ( d[now] >=0 ) return d[now];
    
    d[now] = 0;
    if ( a[now] ==1 ) d[now] = 1e9;
    else d[now] = 0;

    for (int i : e[now])
    {
        d[now] = a[now]?(min(go(i), d[now])):(d[now]+go(i));
    }
    return d[now];
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
        --tmp;
        e[tmp].push_back(i);
    }

    //go(0);
    //cout << leaf + 1 - d[0] <<"\n";

    cout << leaf + 1 - go(0) <<"\n";
}