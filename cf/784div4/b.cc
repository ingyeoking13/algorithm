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
    while(t--){
        int n;
        cin >> n;
        map<int, int> mm;
        int ans = -1;
        while(n--) {
            int tmp;
            cin >> tmp;
            if (mm.find(tmp) == mm.end()) 
                mm[tmp]=1;
            else mm[tmp]++;
            if (mm[tmp]>=3) 
                ans=tmp;
        }
        cout << ans << "\n";
    }
 
}