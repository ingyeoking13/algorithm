#include <iostream>
#include <set>
#include <vector>
using ll = long long;

using namespace std;

struct Query {
    ll cmd, x, y;
} q[(int)1e5+1];

int cur[(int)1e5];
set<ll> s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> cur[i];
        s.insert(cur[i]);
    }

    for (int i=0; i<m; i++)
    {
        cin >> q[i].cmd;
        ll& qq = q[i].cmd;
        int idx, x, l, r;
        if ( qq == 1 )
        {
            cin >> idx >> x;
            q[idx].x--;
        }
        else if ( qq==2 )
        {
            cin >> idx >> x;
        }
        else if ( qq==3)
        {
            cin >> l >> r;
        }
        else if ( qq==4 )
        {
            cin >> idx;
        }
    }
}