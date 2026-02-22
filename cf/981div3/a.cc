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

        int val = 0;
        int i;
        for (i=1; i<=n; i++) {
            int cur = 2*i - i;
            if (i%2) {
                val -= cur;
            } else {
                val += cur;
            }
            if ( val <= n || val >= -n) continue;
            else {
                i++;
                break;
            }
        }
        i--;
        if (i%2) 
            cout << "Kosuke\n";
        else 
            cout << "Sakurako\n";
    }

}