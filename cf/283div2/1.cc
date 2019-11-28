
#include <iostream>
using ll = long long;
using namespace std;

int a[100];
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

    int ans = 1e9;
    for (int i=1; i<n-1; i++)
    {
        int mid = i;
        int tmp = a[i] - a[i-1]  + a[i+1] -a[i];

        for (int j=0; j<n-1; j++)
        {
            if ( i== j || i == j+1) continue;

            int d = a[j+1] - a[j];
            if ( d > tmp ) tmp = d;
        }
        if ( tmp < ans) ans = tmp;
    }
    cout << ans << "\n";
}