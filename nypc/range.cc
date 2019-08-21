#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long ans = 0;
    for (long long i=1; i*i<=b; i++)
    {
        long long r = b/i;
        long long l = a/i;
        if ( a%i >0) l++;
        l = max(l, i);
        ans += (r-l+1)*2;
        if ( i*i >= a ) ans--;
    }
    cout << ans <<"\n";

}