#include <iostream>
#include <string.h>
#include <map>
#include <set>

using ll = long long;
using namespace std;

struct Q
{
    ll cmd, x, y;
}q[(int)2e5];

ll cur[(int)1e5];
ll cnt[(int)1e5];
ll seg[(int)4e5];
ll table[(int)1e5];

ll init(int idx, int l, int r)
{
    if (l ==r ) return seg[idx] = cnt[l];
    int mid = (l+r)/2;
    return seg[idx] = init(idx*2+1, l, mid) 
                   + init(idx*2+2, mid+1, r);
}

ll add(int idx, int l, int r, int x, int dx)
{
    if ( x < l || r < x) return seg[idx];
    if (l == r )         return seg[idx] += dx;

    int mid = (l+r)/2;
    return seg[idx] = add(idx*2+1, l, mid, x, dx)
                    + add(idx*2+2, mid+1, r, x, dx);
}

ll query(int idx, int l, int r, int point)
{
    if ( r == point ) return seg[idx];

    int mid = (l+r)/2;
    if ( point <= mid )
        return query(idx*2+1, l, mid, point);
    return  query(idx*2+2, mid+1, r, point) + seg[idx*2+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        memset(cur, 0, sizeof(cur));
        memset(table, 0, sizeof(table));

        set<ll> sset;
        for (int i=0; i<m; i++)
        {
            char s[3];
            cin >> s;
            if ( s[0] == 'R')
            {
                cin >> q[i].x >> q[i].y;

                q[i].x--;
                q[i].cmd =1;

                cur[q[i].x] += q[i].y;
                q[i].y= cur [ q[i].x ];
                sset.insert(q[i].y);
            }
            else 
            {
                cin >> q[i].x; 
                q[i].cmd =0;
                q[i].x--;
            }
        }

        sset.insert(0);

        map<ll, int> mmap;
        int i =0;
        for (ll x : sset)
        {
            mmap[x]= i++;
        }

        for (int i=0; i<m; i++)
        {
            q[i].y = mmap[q[i].y];
        }

        cnt[0] = n;
        int sz = sset.size();
        init(0, 0, sz-1);
        for (int i=0; i<m; i++)
        {

            if ( q[i].cmd == 1)
            {
                add(0, 0 , sz-1, table[ q[i].x ], -1);
                table[q[i].x] = q[i].y;
                add(0, 0 , sz-1, table[ q[i].x ], +1);
            }
            else 
            {
                cout << n - query(0, 0, sz-1, table[q[i].x])+1 <<"\n";
            }
        }
    }
}