#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)2e5], b[(int)2e5], c[(int)2e5];
int d[(int)2e5+1];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while ( t--)
    {
        int n, m;
        cin >>n;

        d[n]=0;
        for (int i=0;i<n; i++)
        {
            cin >> a[i];
            d[i] =0;
        }

        cin >> m;
        int mmx = 0;
        for (int i=0; i<m; i++)
        {
            cin >> b[i] >> c[i];
            d[c[i]] = max(b[i], d[c[i]]);
            mmx = max(c[i], mmx);
        }
        for (int i=n-1; i>=1; i--) d[i] = max(d[i], d[i+1]);

        int cur=0;
        int ans = 0;
        while(cur<n)
        {
            int i=1;
            ans++;
            if ( a[cur] > d[i] ) break;

            int mx = a[cur];

            while ( cur < n && i <= mmx && a[cur] <= d[i] &&  mx <= d[i] )
            {
                cur++, i++;
                mx = max(mx, a[cur]);
            }
        }
        if ( cur == n)
            cout << ans << "\n";
        else cout << "-1\n";
    }

}