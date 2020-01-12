#include <bits/stdc++.h>
using ll = long long;
using namespace std;


ll p[250001];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    p[1]=  p[0]=1;
    for(int i=2; i<=n; i++)
    {
        p[i]= p[i-1];
        p[i]*= i;
        p[i]%=m;
    }

    ll ans = 0;
    for (int i=1; i<=n; i++)
    {
        ll tmp = n - i  + 1;
        tmp *= n - i + 1;
        tmp %= m;
        tmp *= p[n-i];
        tmp %= m;
        tmp *= p[i];
        tmp %= m;
        ans += tmp;
        ans %= m;
    }
    cout << ans <<"\n";
}