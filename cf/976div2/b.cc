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
    while(t--) {
        ll k;
        cin >> k;

        ll ans = k;
        ll prevsqrt = sqrt(ans);
        ans = prevsqrt + ans;

        ll diff = sqrt(ans) - prevsqrt;
        ans += diff;

        cout << ans << "\n";
    }

}