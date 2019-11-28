#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char s[(int)1e6+3];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while ( t-- )
    {
        int n; ll k; 
        cin >> n >> k;

        cin >> s;

        vector<int> a;

        for (int i=0; i<n; i++)
        {
            if ( s[i] == '0') a.push_back(i);
        }

        int cur = 0;
        for (int& idx : a )
        {
            k -= (idx - cur);
            if ( k <= 0 )
            {
                idx = cur - k;
                break;
            }
            idx = cur;
            cur++;
        }

        for (int i=0; i<n; i++) s[i] ='1';
        for (int i : a ) s[i] ='0';
        cout << s <<"\n";

    }
}