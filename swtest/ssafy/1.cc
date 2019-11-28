#include <bits/stdc++.h> 
using ll = long long;

using namespace std;
int main()
{
    ll f1, f2, k;
    cin >> f1 >> f2 >> k;

    ll ans;
    for (int i=3; i<=k; i++)
    {
        ans = f1 + f2;
        f1 = f2;
        f2 = ans;
    }
    cout << ans << "\n";
}
