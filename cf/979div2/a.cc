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
        int n;
        cin >> n;
        int mx = 0, mn = 1001;
        for (int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            mx = max(tmp, mx);
            mn = min(tmp, mn);
        }
        ll ans = (mx-mn)*(n-1);
        cout << ans << "\n";
    }
}