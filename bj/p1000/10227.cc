#include <iostream>
#include <string.h>

using namespace std;
int a[3001][3001] , cnt[3001][3001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c, h, w;
    cin >> r >> c >> h >> w;

    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            cin >> a[i][j];
    
    int ll = 1, rr= r*c;
    int ans = rr;

    while( ll<=rr )
    {
        int m = (ll+rr)/2;
        for (int i=1; i<=r; i++)
        {
            for (int j=1; j<=c; j++)
            {
                cnt[i][j] = 0;
                if ( m >= a[i][j]) cnt[i][j]++;
            }
        }

        for (int i=1; i<=r; i++)
        {
            for (int j=1; j<=c; j++)
            {
                cnt[i][j] += cnt[i][j-1] + cnt[i-1][j] - cnt[i-1][j-1];
            }
        }

        for (int i=1; i<=r; i++)
            for (int j=1; j<=c; j++);

        bool chk = false;
        for (int i=h; i<=r; i++)
        {
            for (int j=w; j<=c; j++)
            {
                int val = cnt[i][j] - cnt[i][j-w] - cnt[i-h][j]+cnt[i-h][j-w];
                if ( val > (h*w)/2  ) 
                {
                    chk = true;
                    break;
                }
            }
            if ( chk) break;
        }

        if ( chk ) 
        {
            rr= m-1;
            ans = m;
        }
        else ll = m+1;
    }
    cout << ans <<"\n";
}