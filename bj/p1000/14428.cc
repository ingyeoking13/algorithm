#include <iostream>
#include <algorithm>

using namespace std;
int a[(int)1e5];
pair<int, int> seg[(int)4e5];

pair<int, int> build(int cur, int l, int r)
{
    if ( l == r ) return seg[cur] = {a[l], l};

    int m = (l+r)/2;
    auto lv = build(cur*2+1,   l, m);
    auto rv = build(cur*2+2, m+1, r); 
    return seg[cur] = min(lv, rv);
};

pair<int, int> get(int cur, int l, int r, int ql, int qr)
{
    if ( ql<= l && r <= qr ) return seg[cur];
    if ( r < ql || qr < l ) return {1e9+1, 1e9+1};

    int m = (l+r)/2;
    auto lv = get(cur*2+1,   l, m, ql, qr);
    auto rv = get(cur*2+2, m+1, r, ql, qr); 
    return min(lv, rv);
};

pair<int, int> modified(int cur, int l, int r, int idx, int val)
{
    if ( l == r ) 
    {
        if ( l == idx ) return seg[cur] = {val, idx};
        return seg[cur];
    }
    if ( r < idx || idx < l ) return seg[cur];

    int m = (l+r)/2;

    auto lv = modified(cur*2+1, l, m , idx, val);
    auto rv = modified(cur*2+2, m+1, r, idx, val);

    return seg[cur] = min(lv, rv);
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    build(0, 0, n-1);

    int q;
    cin >> q;

    while(q--)
    {
        int o, x, y;
        cin >> o >> x >> y;
        if ( o == 2) // get
        {
            x--, y--;
            cout << get(0, 0, n-1, x, y).second +1 <<"\n";
        }
        else  // modified
        {
            x--;
            modified(0, 0, n-1, x, y);
        }

    }
}