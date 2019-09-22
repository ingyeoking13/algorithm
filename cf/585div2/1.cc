#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int  a, b, n, m, k;
    cin >> a >> b>> n >> m >> k; 

    int cp = k;
    cp -= ((n-1)*a + (m-1)*b);
    if ( cp < 0 ) cp = 0;
    cout << cp << " ";

    int ans = 0;
    if ( n > m )
    {
        ans += min(k/m, b);
        k -= m*ans;
        ans += min(k/n, a);
    }
    else 
    {
        ans += min(k/n, a);
        k -= n*ans;
        ans += min(k/m, b);
    }
    cout << ans  <<"\n";
}