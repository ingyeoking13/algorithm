#include <iostream>

using namespace std;

int a[(int)4e2];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for (int i= 0; i<n; i++)
        {
            cin >> a[i];
        }

        for (int i=n; i<2*n; i++)
        {
            a[i] = a[i-n];
        }

        int one= -1, nn =-1;
        for (int i = 0; i<2*n; i++)
        {
            if ( one < 0 && a[i] == 1) one = i;
            if ( nn < 0 && a[i] == n) nn = i;
        }

        bool chk = true;
        for (int i=0; i<n; i++)
        {
            if ( one + i >= 2*n ) 
            {
                chk = false;
                break;
            }
            if ( a[one + i] !=  i +1 ) chk = false;
        }

        if ( chk)
        {
            cout << "YES\n";
            continue;
        }

        chk = true;
        for (int i=0; i<n; i++)
        {
            if ( nn + i >= 2*n )
            {
                chk =false;
                break;
            }
            if ( a[nn+i] != n - i ) 
            {
                chk =false;
            }
        }
        if ( chk )
        {
            cout << "YES\n";
            continue;
        }
        cout <<"NO\n";
    }
}