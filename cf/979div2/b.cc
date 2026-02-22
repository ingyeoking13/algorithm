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
    while ( t-- ) {
        int n;
        cin >> n;

        string ans = "1";
        for (int i=1; i<n; i++) {
            ans += "0";
        }
        cout << ans << "\n";

    }

}