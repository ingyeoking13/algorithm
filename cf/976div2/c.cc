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
        ll b, c, d;
        cin >> b >> c >> d;
        ll a = 0;

        bool possible = true;
        for (int i=0; i<62; i++) {
            int bb = (b>>i) & 1;
            int cc = (c>>i) & 1;
            int dd = (d>>i) & 1;

            if(bb==0 && cc == 0 ) {
                if (dd==1) a |= (1ll<<i);
            }
            else if (bb==1 && cc == 0) {
                if (dd==0) {
                    possible = false;
                    break;
                }
            } else if (bb==0 && cc==1) {
                if (dd==1) {
                    possible = false;
                    break;
                }
            } else {
                if (dd==0) a |= (1ll<<i);
            }
        }
        cout << (possible?a:-1) <<"\n";
    }

}