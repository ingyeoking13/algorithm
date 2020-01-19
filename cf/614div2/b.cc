#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    double ans = 0;
    for (int i=0; i<n; i++)
    {
        ans += (1)/(double(n-i));
    }
    cout << ans <<"\n";
}