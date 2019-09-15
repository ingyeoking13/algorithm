#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long base = 1;
    long long fb = 0, fa = 0;
    while( b )
    {
        fb += base * ((b+1)/2);

        b/=2;
        base*=2;
    }

    base = 1;
    a--;
    while( a )
    {
        fa += base * ((a+1)/2);

        a/=2;
        base*=2;
    }
    cout << fb-fa <<"\n";
}