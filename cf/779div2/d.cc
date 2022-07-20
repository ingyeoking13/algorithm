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
    vector<int> count(18);
    for (int i=0; i<=2^17; i++) {
        for (int j=0; j<=17; j++) {
            count[j] += i & (1<<j);
        }
    }
    
    while( t-- ) {
        int l, r;
        cin >> l >> r;
        int x =0;
        for (int i=0; i<r+1;i++ ) {
            int tmp;
            cin >> tmp;
            x^=tmp;
        }
        int d = r%4;
        if (d == 0) {
            d = r;
        } else if (d== 1); 
        else if ( d==2) d = r+1;
        else d = 0;
        cout << d << " , " << x << "\n";
        int ans = d^x;
        cout << ans <<"\n";
    }
}