#include <iostream>
#include <algorithm>

using namespace std;

int a[400];
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
        for (int i=0; i<4*n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+4*n);

        int target = 0;
        if ( a[0] == a[1] && a[4*n-1] == a[4*n-2])
        {
            target = a[0]*a[4*n-2];
        }
        else 
        {
            cout <<"NO\n";
            continue;
        }

        int cnt = 1;
        bool chk = true;
        while(cnt < n) 
        { 
            if (!(a[2*cnt] == a[2*cnt+1] && a[4*n- 2*cnt-1] == a[4*n - 2*cnt-2]))
            {
                chk = false;
                break;
            }
            int area = a[2*cnt]*a[4*n-2*cnt-2];
            if (area != target )
            {
                chk = false;
                break;
            }
            cnt++;
        }

        if (chk) cout <<"YES\n";
        else cout <<"NO\n";
    }

}