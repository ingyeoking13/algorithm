#include <iostream>
#include <algorithm>

using namespace std;
int a[(int)2e5], b[(int)2e5];
int main()
{
    int T;
    cin >> T;
    for (int tc=1; tc<=T; tc++)
    {
        int n, k;
        cin >> n >> k;
        
        int mx = 0;

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            mx = max(a[i], mx);
        }

        for (int i=0; i<k; i++)
            cin >> b[i];

        int ll =1, rr = mx;

        int ans =0;
        while ( ll <= rr)
        {
            int mid = (ll+rr)/2;

            int i;
            int l=0;
            for ( i=0; i<n; i++ )
            {
                int j;
                for ( j=0; j<b[l]; j++)
                {
                    if ( i+j >= n ||  a[i+j] > mid ) 
                    {
                        i+=j;
                        break;
                    }
                }
                if ( j== b[l]) 
                {
                    i += (b[l]-1);
                    l++; 
                    if ( k ==l) break;
                }
            }
            if ( l == k ) ans = mid, rr = mid-1;
            else ll = mid+1;
        }

        cout << "#" << tc << " " << ans <<"\n";
    }
}