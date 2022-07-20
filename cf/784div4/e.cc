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
    while(t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        vector<vector<int> > head(11, vector<int>(11, 0)), tail(11, vector<int>(11, 0));
        head[v[n-1][0]-'a'][v[n-1][1]-'a']++;
        tail[v[n-1][1]-'a'][v[n-1][0]-'a']++;
        ll ans = 0;
        for (int i=n-2; i>=0; i--) {
            int h = v[i][0]-'a';
            int t = v[i][1]-'a';
            head[h][t]++;
            tail[t][h]++;
            ll sum = 0;
            for (int j=0; j<11; j++) {
                if (t == j) continue;
                sum += head[h][j];
            }
            for (int j=0; j<11; j++) 
            {
                if (h == j) continue;
                sum += tail[t][j];
            }

            ans += sum;
        }

        cout << ans << "\n";

    }
}