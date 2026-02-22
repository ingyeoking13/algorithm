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
        vector<vector<int>> v(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> v[i][j];
            }
        }

        vector<int> d(2*n-1, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (v[i][j] < 0) {
                    d[i-j+n-1]= min(d[i-j+n-1], v[i][j]);
                }
            }
        }
        ll ans =0;
        for (int i=0; i<d.size(); i++){
            ans += d[i];
        }
        cout << -ans <<"\n";
    }

}
