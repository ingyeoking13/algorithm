#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    return b?gcd(b, a%b):a;
}

long long a[(int)4e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    long long g= 0;
    for (int i=0; i<n; i++)
    {
        g = gcd(a[i], g);
    }

    int ans =0;
    for (long long i =1; i*i<=g; i++)
    {
        if ( g%i == 0)
        {
            ans+=2;
            if ( i*i == g) ans--;
        }
    }
    cout << ans <<"\n";
}