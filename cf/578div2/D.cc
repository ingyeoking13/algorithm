#include <iostream>
#include <algorithm>

using namespace std;

char s[2000][2001];
int row[2000][2], col[2000][2];
int d[2000][2000];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , k;
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        cin >> s[i];
    }

    int cnt =0;
    for (int i=0; i<n; i++)
    {
        row[i][0] = 1e9;
        row[i][1] = -1;
        for (int j=0; j<n; j++)
        {
            if (s[i][j] == 'B')
            {
                row[i][0] = min(row[i][0], j);
                row[i][1] = j;
            }
        }
        if( row[i][0] ==1e9)  cnt++;
    }

    for (int i=0; i<n; i++)
    {
        col[i][0] =1e9;
        col[i][1] = -1;
        for (int j=0; j<n; j++)
        {
            if (s[j][i] == 'B')
            {
                col[i][0] = min(col[i][0], j);
                col[i][1] = j;
            }
        }
        if (col[i][0]==1e9)  cnt++;
    }

    int ans = 0;
    for (int i=0;i<n; i++)
    {
        int now = 0;
        for (int j=0;j<n ;j++)
        { // if click (i, j).

            if ( col[j][0] != 1e9 && i<= col[j][0]  && col[j][1] <= i+k-1 ) now++;
            if ( j-k>=0 && col[j-k][0] != 1e9 && i<= col[j-k][0] && col[j-k][1] <= i+k-1 ) 
                now--;
            if ( j-k>=0 ) d[j-k][i] = now;
        }
    }

    for (int i=0; i<n; i++)
    {
        int now = 0;
        for (int j=0; j<n; j++)
        {

            if ( row[j][0] != 1e9 && i<= row[j][0]  && row[j][1] <= i+k-1) now++;
            if( j>=k && row[j][0] != 1e9 && i<= row[j][0] && row[j][1] <=i+k-1) now--;

            if (j>=k)
            {
                d[i][j-k] += now;
            }
        }

    }

}