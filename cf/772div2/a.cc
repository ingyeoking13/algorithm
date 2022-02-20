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
        int number=0, tmp;
        while(n--) {
            cin >> tmp;
            number |= tmp;
        }
        cout << number << "\n";
    }
}