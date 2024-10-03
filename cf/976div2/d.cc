#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int root(vector<int>& v, int i) {
    if (v[i] == i) return v[i];
    return v[i] = root(v, v[i]);
}

int ufind(vector<int>& v, vector<int>& sz, int i, int j) {
    int x = root(v, i);
    int y = root(v, j);
    if (x == y) return 0;
    if(sz[x] > sz[y]) {
        v[y] = x;
        sz[x] += sz[y];
    }
    else {
        v[x] = y;
        sz[y] += sz[x];
    }
    return 1;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<int> v(2*n+1, 0);
        vector<int> sz(2*n+1, 1);
        vector<vector<int>> exists(11, vector<int>(n+1, 0));
        for (int i=1; i<=n; i++) v[i] = i;

        while(m--){
            int a, d, k;
            cin >> a >> d >> k;
            exists[d][a]++;
            exists[d][min(n, a+d*k)]--;
        }

        for (int d=1; d<=10; d++){
            for (int j=0; j<=d; j++) {
                int c = 0;
                for (int i=j; i<=n; i+=d){
                    c += exists[d][i];
                    if(c) ufind(v, sz, i, i+d);
                }
            }
        }
        for (int i=1; i<=n; i++) ans+= (v[i] == i);
        cout << ans << "\n";
    }
}