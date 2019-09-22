#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, p;
    cin >> n >> p;
    long long ans = 1;

    while(n)
    {
        ans *= n;
        ans %= p;
        n--;
    }
    cout << ans<<"\n";
}