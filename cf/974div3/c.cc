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
        int n;
        cin >> n;
        ll sum = 0;
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
            sum += v[i];
        }
        if (n <= 2) {
            cout << "-1\n";
            continue;
        }

        sort(v.begin(), v.end());
        int target = v[v.size()/2];

        ll ans = ((ll)target) * v.size() * 2 - sum + 1;
        cout << max(ans,0LL) << "\n";
    }
}