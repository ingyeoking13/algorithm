#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void gg(bool g){
    string result = g?"NO":"YES";
    cout << result << "\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        bool result = (((ll)n - k + 1 + n) * k / 2)%2;
        gg(result);
    }
}
