#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct aa{
    int x, y, z;
    aa(){
    }
    aa(int x, int y, int z) : x(x), y(y), z(z) {
    }
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        bool chk = true;
        for (int i=1; i<n; i++) if (v[i-1]>v[i]) chk=false;
        if (chk) {
            cout << "0\n";
            continue;
        }
        if (v[n-2] > v[n-1]) {
            cout << "-1\n";
            continue;
        }
        if (v[n-1] <0) {
            cout << "-1\n";
            continue;
        }
        vector<aa> ans;
        ll left= v[n-2];
        for (int i=n-3; i>=0; i--) {
            if (v[i] > left) {
                v[i] = left-v[n-1];
                ans.push_back(aa(i, i+1, n-1));
            }
            left = v[i];
        }
        cout << ans.size() <<"\n";
        for (int i=0; i<ans.size(); i++ ) 
            cout << ans[i].x+1 << " " << ans[i].y+1 << " " << ans[i].z+1 <<"\n";
    }
}