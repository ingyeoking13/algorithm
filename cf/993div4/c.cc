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
    while (t--) {
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll ans = 0;
        ll ma = min(m, a);
        ans += ma;
        ll mb = min(m, b);
        ans += mb;
        ll rem = m - ma + m - mb;
        ans += min(rem, (ll)c);
        cout << ans << "\n";
    }
}