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
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());
        if (v.size() > 1) {
            int diff = v[n-1] - v[n-2];
            if (diff < 0) diff *= -1;
            if (diff <=1) cout << "YES\n";
            else cout << "NO\n";
        } 
        else {
            cout <<(v[0]>1?"NO\n":"YES\n");
        } 
    }
}