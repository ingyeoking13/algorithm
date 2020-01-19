#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[2][(int)1e5];
int dy[3] = {-1, 0, 1};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    for (int i=0;i<n; i++) a[0][i] = a[1][i] = 1;

    for (int i=0; i<k; i++)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;

        a[r][c] = 3-a[r][c];
        bool isOff = a[r][c]==1;

        int dx = r==0?1:-1;
        bool bad = false;

        for (int i =0; i<3; i++)
        {
            if ( c +dy[i] <0 || c+dy[i] >= n) continue;
            if ( a[r+dx][c+dy[i]] ) 
            {
                bad = true;
                break;
            }
        }

        if ( bad) cout <<"NO\n";
        else cout << "YES\n";
    }

}