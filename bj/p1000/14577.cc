#include <iostream>
#include <set>
#include <vector>
#include <map>
using ll = long long;

using namespace std;

struct Query {
    ll cmd, x, y;
} q[(int)1e5];

ll cur[(int)1e5], a[(int)1e5];
set<ll> s;
map<ll, int> mmap;
ll mmap2[(int)4e5];
int cnt[(int)4e5];
ll t[(int)16e5];

ll init(int idx, int l, int r )
{
    if ( l == r  ) return t[idx] = cnt[l];
    int mid = (l+r)/2;
    return t[idx] = init(idx*2+1, l, mid ) + init(idx*2+2, mid+1, r);
}

ll add(int idx, int l, int r, ll x, ll y)
{
    if ( l > x || r < x )
        return t[idx];
    
    if ( l == r ) return t[idx] += y;
    int mid = (l+r)/2;
    return t[idx] = add(idx*2+1, l, mid, x, y) + add(idx*2+2, mid+1, r, x, y);
}

ll query(int idx, int l, int r, ll x, ll y)
{
    if ( l > y || r < x ) return 0;
    if ( x <= l && r <= y) return t[idx];
    int mid =  (l+r)/2;
    return query(idx*2+1, l, mid, x, y) + query(idx*2+2, mid+1, r, x, y);
}

ll query2(int idx, int l, int r, int x)
{
    if ( l == r) return l;
    int mid = (l+r)/2;

    if ( x <= t[ idx*2 +1]) 
        return query2(idx*2+1, l, mid, x);
    
    return query2(idx*2+2, mid+1, r, x - t[idx*2+1]);
}

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
        a[i] =cur[i];
    }

    for (int i=0; i<m; i++)
    {
        cin >> q[i].cmd;
        ll& qq = q[i].cmd;
        if ( qq == 1 )
        {
            cin >> q[i].x >> q[i].y;
            q[i].x--;

            cur[q[i].x] += q[i].y;
            q[i].y = cur[q[i].x];
            s.insert(q[i].y);
        }
        else if ( qq==2 )
        {
            cin >> q[i].x >> q[i].y;
            q[i].x--;

            cur[q[i].x] -= q[i].y;
            q[i].y = cur[q[i].x];
            s.insert(q[i].y);
        }
        else if ( qq==3)
        {
            cin >> q[i].x >> q[i].y;
            s.insert(q[i].x);
            s.insert(q[i].y);
        }
        else if ( qq==4 )
            cin >> q[i].x;
    }

    int i =0;
    for (ll x : s)
    {
        mmap[x] = i;
        mmap2[i] = x;
        i++;
    }

    for (i=0; i<n; i++)
    {
        a[i] = mmap[ a[i] ];
        cnt[ a[i] ]++;
    }

    for (i=0; i<m;i++)
    {
        if ( q[i].cmd == 1 || q[i].cmd == 2)
        {
            q[i].y = mmap[q[i].y];
        }
        else if ( q[i].cmd == 3 )
        {
            q[i].x = mmap[q[i].x];
            q[i].y = mmap[q[i].y];
        }
    }

    int nn = s.size();
    init(0, 0, nn-1);
    for (int i=0; i<m; i++)
    {
        ll& qq = q[i].cmd;
        if ( qq == 1 || qq == 2 )
        {
            add(0, 0, nn-1, a[ q[i].x ], -1);
            a[ q[i].x ] = q[i].y;
            add(0, 0, nn-1, a[ q[i].x ], 1);
        }
        else if (q[i].cmd == 3) 
        {
            cout << query(0, 0, nn-1, q[i].x, q[i].y ) <<"\n";
        }
        else 
        {
            cout << mmap2[ query2(0, 0, nn-1, n-q[i].x+1) ] <<"\n";
        };
    }
}