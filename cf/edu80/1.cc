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

    while ( t--)
    {
        int n, d;
        cin >> n >> d;
        bool res = false;
        double val = (n-1)+ ((double)d)/n;
        if (val <= n ) 
        {
            res = true;
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}