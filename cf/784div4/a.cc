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
        int tmp;
        cin >> tmp;
        cout << "Division ";
        if ( tmp <= 1399 ) cout <<  "4";
        else if ( tmp <= 1599) cout << "3";
        else if ( tmp <= 1899) cout << "2";
        else cout << "1";
        cout << "\n";
    }
}