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
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            cout << "1\n";
            continue;
        }
        cout << 2*b + a + 1 <<"\n";
    }
}