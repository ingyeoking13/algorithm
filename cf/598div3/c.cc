#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[(int)1e3+1];
vector<int> ans;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    int sum = 0;
    a[0]=0;

    for (int i=1;i<=m; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }

    if ( sum > n ) 
    {
        cout << "NO\n";
        return 0;
    }
    else if ( (m+1)*(d-1) + sum < n )
    {
        cout << "NO\n";
        return 0;
    }
    else 
    {
        cout << "YES\n";
        int left =n-sum;
        for (int i=1; i<=m; i++)
        {
            int cnt =0;
            while( left > 0 && cnt < d-1)
            {
                ans.push_back(0);
                cnt++;
                left--;
            }
            ans.push_back(i);
        }
        while(left--) ans.push_back(0);

        for (int i=0; i<ans.size(); i++)
        {
            if ( ans[i] == 0 ) cout << "0 ";
            else 
            {
                while( a[ans[i]]--) cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }

}