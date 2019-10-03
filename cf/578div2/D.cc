#include <iostream>
#include <algorithm>
<<<<<<< HEAD

using namespace std;

char s[2000][2001];
int row[2000][2], col[2000][2];
int d[2000][2000];
=======
 
using namespace std;
 
char a[2000][2001];
// d(i,j) stands for 
int d[2000][2000];
 
struct pos 
{
     int s, e;
     pos() {};
     pos(int s, int e ) : s(s), e(e) {};
};
 
pos row[2000], col[2000];
 
>>>>>>> origin/master
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
<<<<<<< HEAD

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
=======
 
    int n, k; 
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
 
    int absoluteLine = 0;
    for (int i=0; i<n; i++ )
    {
        row[i].s = row[i].e = -1;
        col[i].s = col[i].e = -1;
 
        for (int j=0; j<n; j++)
        {
            if ( a[i][j] == 'B' ) 
            {
                row[i].e = j;
                if ( row[i].s == -1 ) row[i].s = j;
            }
 
            if ( a[j][i] == 'B')
            {
                col[i].e = j;
                if ( col[i].s == -1) col[i].s = j;
            }
        }
 
        if ( row[i].s == -1 ) absoluteLine++;
        if ( col[i].s == -1 ) absoluteLine++;
    }
 
    for (int i=0; i<n;i++)
    {
        int cnt = 0;
        for (int j=0; j<n; j++)
        {
 
            if ( row[j].s >= i && i+k-1 >= row[j].e )  cnt++;
            if ( j-k >=0 &&  row[j - k].s >= i && i+k-1 >= row[j-k].e  ) cnt--;

            if ( j+1 >= k )
                d[j+1-k][i]  += cnt;
        }
    }
 
    for (int i=0; i<n; i++)
    {
        int cnt = 0;
        for (int j=0; j<n; j++)
        {
            if ( col[j].s >= i && i+k-1 >= col[j].e ) cnt++;
            if ( j-k >= 0 && col[j-k].s >= i && i+k-1 >= col[j-k].e ) cnt--;

            if ( j+1 >= k )
                d[i][j+1-k] += cnt;
        }
    }
 
    int ans = 0;
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            ans = max(d[i][j], ans );
        }
    }
 
    cout << ans  + absoluteLine << "\n";
}
>>>>>>> origin/master
