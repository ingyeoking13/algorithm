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
        int n, k;
        cin >> n >> k;
 
        vector<int> v(n + 1, 0);
        for (int i=1; i<=n; i++)
            cin >>v[i];
        
        map<ll, ll> answer; 
 
        for (int i=2; i<=n-1; i++) {
            ll lines = ((ll)(n-i)+(n-1))*i/2 - ((ll)i-2)*(i-1)/2;
            ll edges = lines - (i - 1);
            if (answer.find(lines) == answer.end()) {
                answer[lines] = 1;
            } 
            else answer[lines] += 1;
 
            if (answer.find(edges) == answer.end()) {
                answer[edges] = v[i+1] - v[i] - 1;
            }
            else answer[edges] += v[i+1] - v[i] - 1;
        }
 
        if (answer.find(n-1) == answer.end()) {
            answer[n-1]=2;
        } else answer[n-1] += 2;
        if (answer.find(n-1) == answer.end()) {
            answer[n-1] = v[2] - v[1] - 1;
        } else answer[n-1] += v[2] - v[1] - 1;
 
        while(k--) {
            ll q;
            cin >> q;
            cout << answer[q] << " ";
        }
 
        cout <<"\n";
    }
 
}