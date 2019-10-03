#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int a[(int)3e5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int mx = 0;
    for (int i=0; i<m; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l =1, r= mx;
    while( l<=r )
    {
        int mid = (l+r)/2;

        int man = 0;
        for (int i=0; i<m; i++)
        {
            man += a[i]/mid;
            man += (a[i]%mid==0?0:1);
        }
        if ( man > n ) l = mid+1;
        else r = mid-1;
    }
    cout << l << "\n";
}