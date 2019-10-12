#include <iostream>

using namespace std;

int a[(int)2e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while ( q-- )
    {
        int h, n;
        cin >> h >> n;

        for (int i=0; i<n; i++)
            cin >> a[i];

        int i = 0;
        int cur;
        int ans = 0;
        while ( i < n-2 )
        {
            cur = a[i];
            if ( cur-1 == a[i+1]) 
            {
                if ( a[i+2] < a[i]-2) ans++, a[i+1] = cur-2;
                else i++;
                i++;
            }
            else 
            {
                if ( a[i+1] -1 == a[i+2]) i++;
                else a[i+1] = a[i+1]-1, ans++;  
                i++;
            } 
        }

        if ( i == n-2)
        {
            if ( a[i+1] == a[i]-1 && a[i] == 2); 
            else if ( a[i+1]== 1); 
            else ans++;
        }

        cout << ans <<"\n";
    }
}