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
        string s;
        cin >> n >> s;
        bool ans = (s[0]=='1')?true:false;
        if (n == 1)  {
            cout << (ans?"YES\n":"NO\n");
            continue;
        }
        if (n%2 == 0) {
            if (s[n-1] == '1') {
                ans = true;
            } else {
                int tmp = (s[0]=='1')?1:0;
                for (int i=1; i<n; i++) {
                    int c = (s[i]=='1'?1:0);
                    if (i%2) tmp |= c;
                    else tmp &= c;
                    if (tmp && (i%2==0)) {
                        tmp = -1;
                        ans = true;
                        break;
                    }
                }
                if (tmp >=0) ans = false;
            }
        } else if (n%2 == 1) {
            if (s[n-1]=='0') {
                ans = false;
            } else {
                int tmp = (s[0]=='1')?1:0;
                for (int i=1; i<n; i++) {
                    int c = (s[i]=='1'?1:0);
                    if (i%2) tmp |= c;
                    else tmp &= c;
                    if (tmp==0 && (i%2==1)) {
                        tmp = -1;
                        ans = false;
                        break;
                    }
                }
                if (tmp >=0) ans = true;
            }
        } 
        cout << (ans?"YES\n":"NO\n");
        continue;
    }

}