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
        int a, b;
        cin >>  a >> b;

        int rem = abs(a-b);
        int ans =0;
        ans += rem/5;
        rem%=5;
        ans += rem/2;
        rem%=2;
        ans += rem;
        cout << ans <<"\n";
    }
}