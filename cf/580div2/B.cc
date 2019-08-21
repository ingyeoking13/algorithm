#include <iostream>
#include <algorithm>

using namespace std;

int a[(int)1e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mn =1e9+1, j=-1, mx =-1e9-1, k=-1;
    cin >> n;
    for (int i=0; i<n;i++) 
    {
        cin >> a[i];
        if ( a[i] >=0 && a[i] < mn) 
        {
            mn = a[i];
            j = i;
        }
        if ( a[i] <0 && a[i] > mx)
        {
            mx = a[i];
            k = i;
        }
    }

    int cnt=0;
    for (int i=0; i<n; i++)
    {
        if ( a[i] <0) cnt++;
    }

    long long ans = 0;
    if ( cnt%2 )
    {
        if ( j == -1) // 
        {
            ans += (-a[k] + 1);
            a[k] = 1;
        }
        else if ( k == -1)
        {
            ans += (a[j]+1);
            a[j] =-1;
        }
        else 
        {
            if ( abs(a[k]) > abs(a[j]) ) 
            {
                ans += (a[j]+1);
                a[j] =1;
            }
            else 
            {
                ans += (-a[k]+1);
                a[k] = -1;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        if ( a[i] < 0 )
        {
            ans += abs(a[i] +1);
        }
        else if ( a[i] == 0) ans++; 
        else ans += (a[i] -1);
    }
    cout << ans<<"\n";
}