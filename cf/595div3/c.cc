#include <iostream>
#include <map>

using namespace std;
using ll = long long;

map<ll, int> m;
map<ll, ll> ss;

int main ()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int cnt=0;
    ll sum =0;
    for (ll i=1; i<=1e18+4e17; i*=3)
    {
        sum += i;
        m[i] = cnt++;
        ss[i] = sum;
    }

    int q;
    cin >> q;

    while(q--)
    {

        ll n;
        cin >> n;

        auto ret = m.lower_bound( n );

        if ( ret->first == n )
        {
            cout << n <<"\n";
            continue;
        }

        ll ans = 0;

        while( n>0 )
        {
            ret = m.lower_bound( n );
            if( ret->first == n );
            else 
            {
                ret--;
                if ( ss[ ret->first ] < n ) ret++;
            }
            ans += ret->first;
            n-=ret->first;
        }
        cout << ans << "\n";
    }
}