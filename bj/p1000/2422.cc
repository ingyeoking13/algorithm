#include <iostream>
#include <string.h>

using namespace std;
bool p[200][200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    memset(p, 3, sizeof(p));

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        p[x][y] = p[y][x] = false;
    }

    int ans = 0;
    for (int i=0; i<n; i++)
    {
        for (int j =i+1; j<n; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if ( p[i][j] && p[j][k] && p[i][k]) ans++;
            }
        }
    }
    cout << ans << "\n";
}