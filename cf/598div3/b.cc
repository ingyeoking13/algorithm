#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)1e2];
bool v[(int)1e2];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++) cin >> a[i];
        memset(v, 0, sizeof(v));

        for (int i=0; i<n-1; i++)
        {
            int mn = 1e9;
            int idx = -1;
            for (int j=1; j<n; j++)
            {
                if ( mn > a[j] && v[j-1] == false) 
                {
                    mn = a[j];
                    idx = j;
                }
            }

            if ( mn == 1e9) break;

            if ( a[idx-1] < a[idx]) 
            {
                v[idx-1] = true;
                continue;
            }
            v[idx-1] = true;
            int tmp = a[idx-1];
            a[idx-1] = a[idx];
            a[idx] = tmp;
        }

        for (int i=0; i<n ;i++) cout << a[i] << " ";
        cout << "\n";
    }
}