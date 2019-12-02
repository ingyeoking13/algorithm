#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int hh[100][2];
bool he[100][100];

int ans[100][100];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, h;
    cin >> n >> m >> h;

    for (int i=0; i<m;i++) cin >> hh[i][0];
    for (int i=0; i<n; i++) cin >> hh[i][1];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> he[i][j];

            if ( he[i][j] == 0) continue;

            ans[i][j] = min( hh[j][0], hh[i][1]);
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << ans[i][j] << " " ;
        }
        cout << "\n";
    }
}