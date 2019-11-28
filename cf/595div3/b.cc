#include <iostream>
#include <string.h>

using ll = long long;
using namespace std;

int a[(int)2e5];
int col[(int)2e5];
int len[(int)2e5];
int cur;

int go (int idx)
{
    if ( col[ idx ] >= 0 ) return 0;

    int ret =1;
    col[idx] = cur;
    return go( a[ idx ] ) + ret;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while( q-- )
    {
        memset(col, -1, sizeof(col));
        cur=0;
        int n; 
        cin >> n;

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            a[i]--;
        }

        for (int i=0; i<n; i++)
        {
            if ( col[i] >= 0 ) continue;
            int sz = go(i);
            len[ cur ] = sz;
            cur++;
        }

        for (int i=0; i<n; i++)
        {
            cout << len[ col[ i ] ] << " ";
        }
        cout << "\n";
    }

}