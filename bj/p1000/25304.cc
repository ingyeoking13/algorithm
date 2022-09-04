#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t >> n;
    int sum = 0;
    while (n--) {
        int pay, m;
        cin >> pay >> m;
        sum += pay*m;
    }
    cout << (sum == t?"Yes":"No");
}