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
        int two = n/2;
        int one = n - two*2;
        int diff = two - one;
        while(diff>=2) {
            one+=2;
            two--;
            diff = two-one;
        }
        string ans;
        if (two >= one) {
            while(true) {
                if (two>0) ans += '2', two--;
                if (one>0) ans += '1', one--;
                if (two == 0 && one == 0) break;
            }
        } else {
            while (true) {
                if (one>0) ans += '1', one--;
                if (two>0) ans += '2', two--;
                if (two == 0 && one == 0) break;
            }
        }
        cout << ans <<"\n";
    }

}