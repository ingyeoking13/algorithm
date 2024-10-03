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
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << n << "\n";
            continue;
        }
        ll rem = n;
        ll ans = 0;
        while (rem) {
            if (rem < k) {
                ans += rem;
                rem = 0;
                continue;
            }
            ll cur;
            for(cur=k;cur<=rem;cur*=k);
            ans++;
            rem -= cur/k;
        }
        cout << ans << "\n";
    }

}