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
        vector<ll> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        if ( n== 1 ){
            cout << "0\n";
            continue;
        }

        int fl = -1, fr = n;
        ll lsum = 0, rsum = 0;
        int l =0, r = n-1;
        while(l<=r) {
            if (lsum < rsum) lsum += v[l++];
            else if (rsum < lsum) rsum += v[r--];
            if (lsum == rsum ) {
                if (lsum != 0) fl = l, fr = r;
                lsum += v[l++];
            }
        }

        if (fl == -1) cout << "0\n";
        else cout << fl + (n-fr-1) <<"\n";
    }
}