#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

int a[(int)1e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while( q-- )
    {
        int n, r;
        cin >> n >> r;

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);

        int ans = 0;
        int go = 0;
        int i =n-1;

        while ( i>=0)
        {

            int val = a[i];
            if ( val - go <= 0 ) break;

            ans++;
            while ( i>=0 && a[i] == val ) i--;

            go+=r;
        }

        cout << ans <<"\n";
    }
}