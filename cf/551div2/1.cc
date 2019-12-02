#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)1e2], b[(int)1e2];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    int ans =0, mint = 1e9;
    for (int i=0; i<n;i++)
    {
        cin >> a[i] >> b[i];

        if ( t<= a[i] )
        {
            if ( mint >= a[i]) 
            {
                ans = i, mint=a[i];
            }
        }
        else 
        {
            int diff = (t - a[i]);
            int th = diff/b[i] + (diff%b[i]?1:0);
            int targett = a[i]+th*b[i];
            if ( targett <= mint) 
            {
                ans = i, mint = targett;
            }
        }
    }

    cout << ans+1 << "\n";
}