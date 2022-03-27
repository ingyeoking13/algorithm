#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        int idx=-1;
        bool hit= false;
        for (int i=0; i<n; i++) 
        {
            if (v[i]==1) {
                if (hit) {
                    idx=-1;
                    break;
                }
                idx=i;
                hit = true;
            }
        }

        if (idx == -1) {
            cout << "NO\n";
            continue;
        }

        hit = false;
        for (int i=idx; i<idx+n; i++) {
            if (v[(i+1)%n]> v[i%n]+1) {
                hit = true;
                break;
            }
        }
        if (hit) {
            cout << "NO\n";
            continue;
        }
        idx = -1;
        hit = false;
        for (int i=0; i<n; i++) {
            if (v[i] == n){
                hit = true;
                idx = i;
                break;
            }
        }
        if (hit && v[(idx+1)%n]!=1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

}