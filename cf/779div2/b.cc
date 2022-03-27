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
    long long f[(int)1e3+1] = {1, };
    int mod = 998244353;
    for (int i=1; i<=1000; i++) {
        f[i] = i*f[i-1];
        f[i] %= mod;
    }

    while (t--) {
        int n;
        cin >> n;
        if (n%2) {
            cout << "0\n";
            continue;
        }
        int k = n/2;
        cout << (f[k]*f[k])%mod <<"\n";
    }
}