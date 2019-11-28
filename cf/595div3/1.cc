#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int a[100];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        bool chk = false;
        for (int i=0; i<n-1; i++)
        {
            if ( a[i]+1 == a[i+1] )
                chk = true;
        }
        if ( chk ) cout << "2\n";
        else cout << "1\n";
    }
}