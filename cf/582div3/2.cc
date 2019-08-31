#include <iostream>
#include <algorithm>

using namespace std;

int a[150000], b[150000];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >>n;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        b[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--)
        {
            b[i] = min(a[i], b[i+1]);
        }

        int ans = 0;
        for (int i=0; i<n-1; i++)
        {
            if ( a[i] > b[i+1]) ans++;
        }
        cout << ans <<"\n";
    }
}