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

        vector<pair<int, int>> v(n, {0, 0});
        for (int i=0; i<n; i++) {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        int mx = 0;
        for (int i=0; i<n; i++) {
            int b = v[i].second;
            if (b%2 == 0) {
                b = v.size()/2 + v.size()%2;
            } else {
                b = v.size()/2;
            }

            mx = max(v[i].first +b, mx);
        }
        cout << mx <<"\n";
    }
}