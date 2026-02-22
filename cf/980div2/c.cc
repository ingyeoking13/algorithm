#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll merge(vector<int>& v, int l, int m, int r){
    int n1 = m - l +1;
    int n2 = r - m;
    vector<int> v1(n1), v2(n2);
    for (int i=0; i<n1; i++)
        v1[i] = v[l + i];

    for (int i=0; i<n2; i++)
        v2[i] = v[m + 1 + i];

    ll res = 0;
    int i =0, j = 0, k = l;
    while( i< n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            v[k++] = v1[i++];
        } else {
            v[k++] = v2[j++];
            res += (n1 - i);
        }
    }

    while (i < n1) 
        v[k++] = v1[i++];

    while (j < n2) 
        v[k++] = v2[j++];
    return res;
}

ll go(vector<int>& v, int l, int r){
    ll res = 0;
    if (l < r) {
        int m = (l+r)/2;
        res += go(v, l, m); 
        res += go(v, m+1, r);

        res += merge(v, l, m, r);
    }

    return res;

}

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
        vector<pair<int, int>> v(n);
        for (int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            v[i].first = b;
            v[i].second = a;
        }

        sort(v.begin(),v.end());
        vector<int> vv(2*n);
        for (int i=0; i<n; i++){
            vv[2*i] = v[i].first;
            vv[2*i+1] = v[i].second;
        }
        ll ans1 = go(vv, 0, 2*n-1);

        for (int i=0; i<n; i++) {
            int tmp = v[i].first;
            v[i].first = v[i].second;
            v[i].first = tmp;
        }
        sort(v.begin(),v.end());
        for (int i=0; i<n; i++){
            vv[2*i] = v[i].first;
            vv[2*i+1] = v[i].second;
        }
        ll ans2 = go(vv, 0, 2*n-1);

        if (ans1 < ans2) {
            for (int i=0; i<n; i++) {
                int tmp = v[i].first;
                v[i].first = v[i].second;
                v[i].first = tmp;
            }
            sort(v.begin(), v.end());
        }

        for (int i=0; i<v.size(); i++) {
            cout << v[i].second << " " << v[i].first << " ";
        }
        // cout << ans << "\n";
        cout <<"\n";
    }
}