#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >>t;
    while (t--) {
        int n, tmp, ans=0;
        cin >> n;
        vector<int> v;
        while(n--){
            cin >> tmp;
            v.push_back(tmp);
        }

        for (int i=1; i<v.size()-1; i++) {
            if (v[i-1] < v[i] && v[i] >v[i+1]) { // condition hit
                if (i+2>=v.size()) {
                    v[i+1] = v[i];
                } else {
                    v[i+1] = max(v[i], v[i+2]);
                }
                ans++;
            }
        }
        cout << ans  <<"\n";
        for (int i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
}