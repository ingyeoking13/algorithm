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
        int n, k;
        cin >> n >> k;
        int cur = 0;
        int ans = 0;

        int tmp;
        for (int i=0; i<n; i++){
            cin>> tmp;
            if (tmp == 0) {
                if (cur > 0) ans++, cur--;
            }
            else if (tmp >= k) cur += tmp;
        }
        
        cout << ans <<"\n";
    }
}