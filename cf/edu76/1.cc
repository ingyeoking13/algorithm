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
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if ( a > b)
        {
            int tmp = b;
            b = a;
            a = tmp;
        }

        int best = max(a-1, n-b);
        if ( x <= best )
        {
            int ans = min(best, x);
            cout << ans+b-a <<"\n";
        }
        else if ( x <= a-1 + n-b)
        {
            cout << x+ b-a <<"\n";
        }
        else cout << n-1 <<"\n";
    }
}