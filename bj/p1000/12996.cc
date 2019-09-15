#include <iostream>

using namespace std;
long long d[51][51][51][51];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    d[0][0][0][0] = 1;

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=a[0]; j++)
        {
            for (int k=0; k<=a[1]; k++)
            {
                for (int l=0; l<=a[2]; l++)
                {
                    if ( i == 0 && j == 0 && k ==0) continue;
                    int next = i;

                    if ( j-1 >= 0) d[next][j][k][l] += d[next-1][j-1][k][l];
                    if ( k-1 >= 0) d[next][j][k][l] += d[next-1][j][k-1][l];
                    if ( l-1 >= 0) d[next][j][k][l] += d[next-1][j][k][l-1];
                    d[next][j][k][l] %= (int)(1e9+7);

                    if ( j-1 >= 0 && k-1>=0) d[next][j][k][l] += d[next-1][j-1][k-1][l];
                    if ( j-1 >=0 && l-1 >=0) d[next][j][k][l] += d[next-1][j-1][k][l-1];
                    if ( k-1 >=0 && l-1>=0) d[next][j][k][l] += d[next-1][j][k-1][l-1];
                    if ( j-1 >=0 && k-1>=0 && l-1>=0) d[next][j][k][l]+= d[next-1][j-1][k-1][l-1];
                    d[next][j][k][l] %= (int)(1e9+7);
                }
            }
        }
    }
    cout << d[n][a[0]][a[1]][a[2]] <<"\n";
}