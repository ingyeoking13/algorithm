#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll i, j;
    int n;
    cin >> n;
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        cout <<  "? " << i << " 1 " << i << " " << n <<"\n";
        int k;
        cin >> k;
        if ( k % 2 ) v.push_back(i);
    }

    if ( v.size() != 0 && v.size() != 2) return -1;
    if ( v.size() == 2)
    {
        vector<pair<int, int>> ans;
        for (int i=0; i<2; i++)
        {
            int l = 1, r = n;
            while(l <= r)
            {
                int mid = (l+r)/2;
                cout << "? " << v[i] << " " << l << " " << v[i] << " " << mid <<"\n";
                int k ;
                cin >> k;
                if ( k%2) r = mid-1;
                else l = mid+1;
            }
            ans.push_back({v[i],l});
        }
        cout << "! " << ans[0].first << " " << ans[0].second << " " 
             << ans[1].first<< " " << ans[1].second;
        return 0;
    }

}
