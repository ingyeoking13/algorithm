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

        vector<int> v(n);
        set<int> s;
        set<int> e;

        for (int i=0; i<n; i++) {
            cin >> v[i];
            s.insert(v[i]);
        }

        for (int i=1; i<=n; i++) {
            if (s.find(i) == s.end()) e.insert(i);
        }

        vector<int> ans;

        for (int i=0; i<n; i++) {
            if (s.find(v[i]) != s.end()) {
                ans.push_back(v[i]);
                s.erase(v[i]);
            } else {
                ans.push_back(*e.begin());
                e.erase(*e.begin());
            }
        }
        for (int i=0; i<n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

}