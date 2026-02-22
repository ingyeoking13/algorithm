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
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i=0; i<n; i++){
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        int s = k / n;
        int r = k % n;
        int tries = 0;
        for (int i =0; i<v.size(); i++){
            if ( v[i] >= s) {
                int tmp = min(k, s);
                tries += tmp;
                k -= tmp;
                v[i] -= tmp;

                if (r > 0) {
                    if (v[i]> 0) {
                        k -= 1;
                        r--;
                    } else {
                        s += r / (v.size() - i - 1);
                        r = r % (v.size() - i - 1);
                    }
                    tries++;
                }
            } else {
                k -= v[i];
                tries += v[i];
                tries += 1;

                int tmp = s - v[i];
                r += tmp;
                s += r / (v.size() - i - 1);
                r = r % (v.size() - i - 1);
            }
            if (k == 0 && r == 0) 
                break;
        }
        cout << tries << "\n";
    }

}