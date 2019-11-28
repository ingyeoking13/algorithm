#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> a;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while ( t-- )
    {
        int a, b, n, s;
        cin >> a >> b >> n >> s;

        int div = s/n;
        div = min (a, div);
        if ( ((ll)div)*n + b >= s ) cout << "YES\n";
        else cout << "NO\n";
    }

}