#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Data
{
    int mx , mn;
    Data(int mx, int mn) : mx(mx), mn(mn) {};
    Data(){};
    bool operator<(Data o) { return mn < o.mn;}
};

Data a[(int)1e5];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        int mx = -1e9, mn =1e9;
        vector<int> tmp;
        for (int j=0; j<m; j++)
        {
            int k;
            cin >> k;
            mx = max(mx, k);
            mn = min(mn, k);
            tmp.push_back(k);
        }
        bool good = false;
        for (int j=0; j<tmp.size(); j++)
        {
            for (int k=0; k<j; k++)
            {
                if ( tmp[k] < tmp[j]) 
                {
                    good= true;
                    break;
                }
            }
            if( good) break;
        }
        if (good) a[i] = {(int)1e9, (int)-1e9};
        else a[i] = {mx, mn};
    }
    ll ans = 0;
    sort(a, a+n);
    for (int i=0; i<n; i++)
    {
        int cur = a[i].mx;
        int l =0, r = n-1;
        while( l<=r )
        {
            int mid = (l+r)/2;
            if ( a[mid].mn >= a[i].mx) r = mid-1; 
            else l = mid+1;
        }
        int cnt = r+1;
        ans += cnt;
    }
   
    cout << ans << "\n";
}