#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    if (x>0 && y> 0) cout << "1";
    if (x<0 && y> 0) cout << "2";
    if (x<0 && y< 0) cout << "3";
    if (x>0 && y< 0) cout << "4";
}