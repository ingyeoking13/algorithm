#include <iostream>
#include <algorithm>

using namespace std;

int a[(int)1e3], d[(int)1e3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i =0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<n; i++)
    {
        d[i] = 1;
        for (int j=0; j<i; j++)
        {
            if ( a[i] < a[j] ) d[i] = max(d[j]+1, d[i]);
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++)  ans = max(ans, d[i]);
    cout << ans <<"\n";
}