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
        long long ans = 0;
        int n, k;
        cin >> n >> k;
        vector<int> v(k, 0);
        for (int i=0; i<n; i++){
            int tmp;
            cin >> tmp;
            v[i%k] = max(v[i%k], tmp);
        }
        for (int i=0; i<k; i++) {
            ans += v[i];
        }
        cout << ans << "\n";
    }

}