#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<ll> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        vector<ll> k(q);
        for (int i = 0; i < q; ++i) {
            cin >> k[i];
        }

        // Calculating the number of segments covered by intervals
        vector<ll> coverage; // Will store the number of integers covered by 1 or more intervals
        for (int i = 1; i < n; ++i) {
            ll segment_length = x[i] - x[i - 1];
            coverage.push_back(segment_length);
        }

        sort(coverage.begin(), coverage.end());

        // To handle queries up to max k
        vector<ll> result_counts(n + 1, 0);
        ll covered_points = 0;
        
        // Calculate how many integers are covered by exactly 1, 2, ..., n segments
        for (ll i = 1; i <= n - 1; ++i) {
            covered_points += coverage[i - 1];
            result_counts[i] = covered_points + i;  // Include the left endpoints contribution
        }

        for (int i = 0; i < q; ++i) {
            if (k[i] <= n - 1) {
                cout << result_counts[k[i]] << " ";
            } else {
                cout << "0 ";
            }
        }

        cout << "\n";
    }

    return 0;
}
