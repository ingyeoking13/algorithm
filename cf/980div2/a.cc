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
    while ( t--) {
        int a;
        int b;
        cin >> a >> b;

        if (a >= b) {
            cout << a <<"\n";
        } else {
            int c = b - a;
            cout << max(a - c,0) <<"\n";
        }
    }
}