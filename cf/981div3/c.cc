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
    while ( t-- ) {
        int n;
        cin >> n;
        vector<int> v(n+2, int(2e5)+1);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
        }

        for (int i=1; i<=n/2 ; i++) {
            int d1 = v[i] == v[i+1];
            int d2 = v[n-i+1]== v[n-i+2];

            int a1 = v[i] == v[n-i+2];
            int a2 = v[n-i+1] == v[i+1];

            if( d1 + d2  > a1 + a2  ) {
                int tmp = v[i];
                v[i] = v[n-i+1];
                v[n-i+1] = tmp;
            }
        }

        int mind = 0;
        for (int i=1; i<=n; i++) {
            cout << v[i] << " ";
            mind += v[i] == v[i+1];
        }
        cout << "\n";
        cout << mind <<"\n";
    }

}