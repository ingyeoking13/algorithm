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
    while (t--)
    {
        int a, b, x, y;
        cin >> x >> y >> a >> b;
        if ( x > y ) 
        {
            cout << -1 << "\n";
            continue;
        }
        int d = y-x;
        if (d%(a +b) > 0)
        {
            cout << -1 <<"\n";
            continue;
        }
        cout << d/(a+b) << "\n";
    }
}