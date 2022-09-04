#include <bits/stdc++.h>
using ll = long long;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    while(n--) cin >> v[n];
    sort(v.begin(), v.end());
    cout << v[v.size()-k];
}