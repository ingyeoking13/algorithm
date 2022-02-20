#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd = 1e9+7;

    int n, p;
    cin >> n >> p;
    vector<ll> d(p);
    vector<ll> sum(p);
    d[0]=1, d[1]=1;
    for (int i=2; i<p; i++) d[i] = (d[i-1] + d[i-2])%dd;
    sum[0]=1;
    for (int i=1; i<p; i++) sum[i] = (d[i]+sum[i-1])%dd;
    
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

}