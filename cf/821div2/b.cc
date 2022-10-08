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
        int n, x, y;
        cin >> n >> x >> y;
        if (x != 0 && y != 0) {
            cout << "-1\n";
            continue;
        }
        if ( x == 0 && y == 0) {
            cout << "-1\n";
            continue;
        }
        int d = max(x,y);
        if ((n-1)%d==0) {
            int tmp = d;
            int cur = 1;
            for (int i=1; i<n; i++) {
                if (tmp == 0) cur = i+1, tmp = d;
                cout << cur << " ";
                tmp--;
            }
            cout << "\n";
        } 
        else cout << "-1\n";
    }
}