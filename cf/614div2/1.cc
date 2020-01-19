#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, s, kk;
        cin >> n>> s>> kk;
        vector<int> a(kk);
        bool damn = false;
        int j = -1;
        for (int i=0; i<kk; i++)
        {
            cin >> a[i];
            if ( a[i] == s)
            {
                damn = true;
            }
        }
        sort(a.begin(), a.end());

        for (int i=0; i<kk; i++) 
            if ( a[i] == s) 
                j = i;

        if ( damn == false) 
        {
            cout << 0 << "\n";
        }
        else
        {
            int k =j;
            int buf = s;
            int ans = 1e9;
            while( --k >=0 )
            {
                if ( buf-a[k] >1 )
                {
                    ans = s-(buf-1);
                    break;
                }
                buf = a[k];
            }
            if ( ans == 1e9) 
            {
                ans = (a[0] -1 >=1)?s-(a[0]-1):1e9;
            }

            k = j;
            buf = s;
            int ans2= 1e9;
            while( ++k < kk)
            {
                if ( a[k] - buf > 1)
                {
                    ans2 =  (buf+1)-s;
                    break;
                }
                buf = a[k];
            }
            if ( ans2 == 1e9)
            {
                ans2 = (a[kk-1]+1<=n)?a[kk-1]+1-s:1e9;
            }
            cout << min(ans, ans2) <<"\n";
        }
    }
}