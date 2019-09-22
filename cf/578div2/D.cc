#include <iostream>
#include <algorithm>
 
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
 
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
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
