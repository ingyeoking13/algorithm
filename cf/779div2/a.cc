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
    while( t-- ) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int ans = 0;
        int hit = 0;
        for (int i=0; i<n; i++) {
            if (str[i] == '0') {
                ans += hit;
                hit = 2;
            } else {
                hit--;
                hit = max(0, hit);
            }
        }
        cout << ans <<"\n";
    }
}