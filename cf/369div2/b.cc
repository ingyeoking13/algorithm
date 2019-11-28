#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[500][500];
ll row[500];
ll col[500];
ll d[2];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x , y;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> a[i][j];
            if ( a[i][j]  == 0) x= i, y =j;
        }
    }

    if ( n== 1) 
    {
        cout << (a[0][0]==0?1:a[0][0] )<<"\n";
        return 0;
    }

    for (int i=0 ;i<n ;i++)
    {
        for (int j=0; j<n ;j++)
        {
            row[i] += a[i][j];
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            col[i] += a[j][i];
        }
    }

    for (int i=0; i<n ;i++)
    {
        d[0] += a[i][i];
        d[1] += a[i][n-1-i];
    }

    ll ans = 0;
    bool chk = true;

    ll val = row[x == 0 ?1:0];
    for (int i=0; i<n; i++)
    {
        if ( i == x ) continue;
        if ( val != row[i] ) chk = false;
    }

    for (int i=0; i<n ;i++)
    {
        if ( i == y ) continue;
        if ( val != col[i])  chk = false;
    }

    if ( x!=y && x != n-1-y)
    {
        if ( d[0] != d[1]) chk =false;
        if ( val != d[0]) chk = false;
    }
    else if ( x == y && x != n-1-y)
    {
        if ( val != d[1]) chk =false;
    }
    else if ( x == n-1-y && x!=y)
    {
        if (val != d[0]) chk =false;
    }

    if ( !chk )
    {
        cout << "-1\n";
        return 0;
    }

    val = row[x==0?1:0] - row[x];
    if ( val <= 0 ) chk = false;
    if ( val !=  col[y==0?1:0]-col[y]) chk =false;

    if ( x== y&& x== n-1-y) 
    {
        if (0 != d[1]-d[0]) chk =false;
        if( d[1] + val != row[x] + val) chk = false;
        if (d[0] + val != row[x]+ val) chk =false;
    }
    else if ( x == y )
    {
        if ( val != d[1]- d[0] ) chk =false;
    }
    else if ( x == n-1-y)
    {
        if ( val != d[0] - d[1]) chk =false;
    }

    if (!chk)
    {
        cout << "-1\n";
        return 0;
    }

     cout << val << "\n";
}