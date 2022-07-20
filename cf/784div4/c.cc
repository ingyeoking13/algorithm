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
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        int f[2] = { -1, -1 };
        int ans = 1;
        for (int i=0; i<n; i++) 
        {
            if (f[i%2] == -1) 
                f[i%2] = v[i]%2;
            else if (f[i%2] != v[i]%2)
                ans = 0;
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}