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
        int x, y;
        cin >> x >> y;

        if ( x == 1)
        {
            if (y == 1) cout  << "YES\n";
            else cout <<"NO\n";
        }
        else if ( x == 2  || x == 3)
        {
            if ( y == 2 || y == 3 || y ==1) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }

}